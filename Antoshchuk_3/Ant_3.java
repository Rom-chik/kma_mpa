import java.util.Arrays;
import java.util.Random;
import java.util.Scanner;

public class Ant_3 {
    static int mid;
    static int right;

    public static void main(String[] args) {
        System.out.print("Write the size of the array: ");
        Scanner sc = new Scanner(System.in);
       /* int sizeOfArray = sc.nextInt();
        int[] myArray = fillArray(sizeOfArray);*/

        int sizeOfArray = 7;
        int[] myArray = {6, 5, 4, 3, 1, 7, 2};

        System.out.println("Your array is: " + Arrays.toString(myArray));

        sortByMrg(myArray, sizeOfArray);
        System.out.println("Sorted array is: " + Arrays.toString(myArray));

    }

    //метод автозаповнення масиву рандомними числами
    public static int[] fillArray(int sizeOfArray) {
        int[] myArray = new int[sizeOfArray];
        Random random = new Random();
        for (int i = 0; i < sizeOfArray; i++) {
            myArray[i] = random.nextInt(2 * sizeOfArray) + 1;
        }
        return myArray;
    }

    public static void merge(int[] arrX, int[] arrY, int l, int m, int r) {
        int k; // індекс у цільовому масиві
        int i, j;// індекси у половинах
        i = l;
        j = m + 1;
        k = l;
        while (k <= r) {
            if (i > m) {
                arrY[k] = arrX[j];
                j++;
            } else if (j > r) {
                arrY[k] = arrX[i];
                i++;
            } else if (arrX[i] < arrX[j]) {
                arrY[k] = arrX[i];
                i++;
            } else {
                arrY[k] = arrX[j];
                j++;
            }
            k++;
        }
    }

    public static void copyArr(int[] arrX, int[] arrY, int left, int right){
        int i = left;
        while (i<=right){
            arrY[i] = arrX[i];
            i++;
        }
    }

    public static boolean findPair(int[] arrX, int n, int left){
        boolean findPair = false;
        if  (left <= n){
            mid = left;
            while ((mid < n) && (arrX[mid] <= arrX[mid +1])){
                mid++;
            }
            if (mid == n){
                right = mid;
            } else{
                findPair = true;
                right = mid + 1;
                while ((right < n) && (arrX[right] <= arrX[right +1])){
                    right++;
                }
            }
        }
        return findPair;
    }

    public static boolean mergeStep (int[] arrX, int[] arrY, int n){
        boolean mergeStep = true;
        int left = 0;

        while(findPair(arrX, n, left)){
            merge(arrX, arrY, left, mid, right);
            left = right+1;
        }
        if ((left==0) && (right == n)){
            mergeStep = false;
        } else{
            if(left <= n){
                copyArr(arrX, arrY, left, n);
            }
        }
        return mergeStep;
    }

    public static void sortByMrg(int[] arrA, int n){
        int[] arrB = new int[n];
        n-=1;
        int step = 0;
        boolean notSorted = true;
        while (notSorted){
            step++;
            if(step % 2 == 1){
                notSorted = mergeStep(arrA, arrB, n);
                System.out.println(Arrays.toString(arrA));
            } else {
                notSorted = mergeStep(arrB, arrA, n);
                System.out.println(Arrays.toString(arrB));
            }
        }
        if(step % 2 == 0){
            copyArr(arrB, arrA, 0, n);
        }
    }
}