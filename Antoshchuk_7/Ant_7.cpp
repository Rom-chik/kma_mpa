#include <iostream> // developed by Roman Antoshchuk on 01.04.2024
#include <vector>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

bool isSafe(const vector<vector<int>>& matrix, int n, int row, int col, int num) {
    // Check the row
    for (int x = 0; x < n; x++)
        if (matrix[row][x] == num)
            return false;

    // Check the column
    for (int x = 0; x < n; x++)
        if (matrix[x][col] == num)
            return false;

    return true;
}

bool solveSquare(vector<vector<int>>& matrix, int n, int fixedCol) {
    if (fixedCol != -1) {
        for (int row = 0; row < n; ++row) {
            matrix[row][fixedCol] = row + 1;
        }
        return solveSquare(matrix, n, -1); 
    }

    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if (matrix[row][col] != 0)
                continue;

            for (int num = 1; num <= n; ++num) {
                if (isSafe(matrix, n, row, col, num)) {
                    matrix[row][col] = num;
                    if (solveSquare(matrix, n, -1))
                        return true;
                    matrix[row][col] = 0;
                }
            }
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Enter the size of the square (3 <= N < 10): ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int col1 = -1;

    cout << "Enter the numbers for the first row: ";
    for (int i = 0; i < n; ++i) {
        cin >> matrix[0][i];
        if (matrix[0][i] == 1)
            col1 = i;
    }

    if (col1 == -1) col1 = 0;
    if (solveSquare(matrix, n, col1)) {
        printMatrix(matrix);
    }
    else {
        cout << "No solution exists." << endl;
    }

    return 0;
}