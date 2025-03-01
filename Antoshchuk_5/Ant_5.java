import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Ant_5 {
    public static double[][] simplexTable;
    private static int rowsCount, columnsCount;
    private static ArrayList<Integer> basisIndices;

    // Initialize the simplex table with slack variables
    public static void initializeTable(double[][] originalMatrix) {
        rowsCount = originalMatrix.length;
        columnsCount = originalMatrix[0].length;
        simplexTable = new double[rowsCount][columnsCount + rowsCount - 1];
        basisIndices = new ArrayList<>();

        for (int i = 0; i < rowsCount; i++) {
            for (int j = 0; j < simplexTable[0].length; j++) {
                if (j < columnsCount) {
                    simplexTable[i][j] = originalMatrix[i][j];
                } else {
                    simplexTable[i][j] = 0;
                }
            }
            if ((columnsCount + i) < simplexTable[0].length) {
                simplexTable[i][columnsCount + i] = 1;
                basisIndices.add(columnsCount + i);
            }
        }
        columnsCount = simplexTable[0].length;
    }

    // Calculate the optimal solution using the simplex algorithm
    public static double[] findOptimalSolution(double[] solutionVector) {
        int pivotColumn, pivotRow;

        double[][] updatedTable = new double[rowsCount][columnsCount];

        while (!checkOptimality()) {
            pivotColumn = selectPivotColumn();
            pivotRow = selectPivotRow(pivotColumn);
            basisIndices.set(pivotRow, pivotColumn);

            for (int j = 0; j < columnsCount; j++) {
                updatedTable[pivotRow][j] = simplexTable[pivotRow][j] / simplexTable[pivotRow][pivotColumn];
            }

            for (int i = 0; i < rowsCount; i++) {
                if (i == pivotRow) continue;
                for (int j = 0; j < columnsCount; j++) {
                    updatedTable[i][j] = simplexTable[i][j] - simplexTable[i][pivotColumn] * updatedTable[pivotRow][j];
                }
            }

            simplexTable = updatedTable.clone();
        }

        // Extracting solution
        for (int i = 0; i < solutionVector.length; i++) {
            int basisIndex = basisIndices.indexOf(i + 1);
            if (basisIndex != -1) {
                solutionVector[i] = simplexTable[basisIndex][0];
            } else {
                solutionVector[i] = 0;
            }
        }

        return solutionVector;
    }

    // Check if the current solution is optimal
    private static boolean checkOptimality() {
        for (int j = 1; j < columnsCount; j++) {
            if (simplexTable[rowsCount - 1][j] < 0) {
                return false;
            }
        }
        return true;
    }

    // Select the pivot column for the next iteration
    private static int selectPivotColumn() {
        int pivotCol = 1;
        for (int j = 2; j < columnsCount; j++) {
            if (simplexTable[rowsCount - 1][j] < simplexTable[rowsCount - 1][pivotCol]) {
                pivotCol = j;
            }
        }
        return pivotCol;
    }

    // Select the pivot row based on the pivot column
    private static int selectPivotRow(int pivotColumn) {
        int pivotRow = 0;
        for (int i = 0; i < rowsCount - 1; i++) {
            if (simplexTable[i][pivotColumn] > 0) {
                pivotRow = i;
                break;
            }
        }

        for (int i = pivotRow + 1; i < rowsCount - 1; i++) {
            if ((simplexTable[i][pivotColumn] > 0) &&
                    ((simplexTable[i][0] / simplexTable[i][pivotColumn]) <
                            (simplexTable[pivotRow][0] / simplexTable[pivotRow][pivotColumn]))) {
                pivotRow = i;
            }
        }

        return pivotRow;
    }
    public static void main(String[] args) {
        try (BufferedReader br = new BufferedReader(new FileReader("src/input.txt"))) {
            int rowCount = Integer.parseInt(br.readLine());
            String[] coefficients = br.readLine().split(" ");
            double[][] initialMatrix = new double[rowCount + 1][coefficients.length + 1];

            for (int i = 0; i < rowCount; i++) {
                String[] rowValues = br.readLine().split(" ");
                for (int j = 0; j < initialMatrix[0].length; j++) {
                    initialMatrix[i][j] = j == 0 ? Double.parseDouble(rowValues[coefficients.length]) : Double.parseDouble(rowValues[j - 1]);
                }
            }

            for (int i = 0; i < coefficients.length; i++) {
                initialMatrix[rowCount][i + 1] = -Double.parseDouble(coefficients[i]);
            }

            double[] solution = new double[coefficients.length];
            initializeTable(initialMatrix);
            solution = findOptimalSolution(solution);

            System.out.println("X = (");
            for (double v : solution) {
                System.out.print(v + ", ");
            }
            System.out.println("\n)");
            System.out.println("\nResult: " + simplexTable[rowsCount - 1][0]);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}