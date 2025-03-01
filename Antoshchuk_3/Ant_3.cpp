#include <iostream> //developed by Roman Antoshchuk on 13.02.2024
#include <vector>
#include <random>
using std::cout;
using std::cin;
using std::endl;

void outputArrayToConsole(const std::vector<int>& array) {
    cout << "[ ";
    for (int i : array) {
        cout << i << " ";
    }
    cout << "]" << endl;
}

std::vector<int> generateRandomIntArray(int arrayLength) {
    std::vector<int> array(arrayLength);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, arrayLength * 2);

    for (int i = 0; i < arrayLength; i++) {
        array[i] = distrib(gen);
    }

    return array;
}

void merge(std::vector<int>& array, int leftIndex, int middleIndex, int rightIndex) {
    int leftPartLength = middleIndex - leftIndex + 1;
    int rightPartLength = rightIndex - middleIndex;

    std::vector<int> leftPart(array.begin() + leftIndex, array.begin() + middleIndex + 1);
    std::vector<int> rightPart(array.begin() + middleIndex + 1, array.begin() + rightIndex + 1);

    int i = 0, j = 0, k = leftIndex;
    while (i < leftPartLength && j < rightPartLength) {
        if (leftPart[i] <= rightPart[j]) {
            array[k] = leftPart[i];
            i++;
        }
        else {
            array[k] = rightPart[j];
            j++;
        }
        k++;
    }

    while (i < leftPartLength) {
        array[k] = leftPart[i];
        i++;
        k++;
    }

    while (j < rightPartLength) {
        array[k] = rightPart[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int>& array, int leftIndex, int rightIndex) {
    if (leftIndex < rightIndex) {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        mergeSort(array, leftIndex, middleIndex);
        mergeSort(array, middleIndex + 1, rightIndex);
        merge(array, leftIndex, middleIndex, rightIndex);

        outputArrayToConsole(array);
    }
}

int main() {
    cout << "\n---Lab work---" << endl;
    cout << "  Roman Antoshchuk  " << endl;
    cout << "----13.02.2024----" << endl;

    cout << '\n' << endl;

    cout << "Enter array length: ";
    int arrayLength;
    cin >> arrayLength;

    std::vector<int> array = generateRandomIntArray(arrayLength);

    cout << "Random array: ";
    outputArrayToConsole(array);

    cout << "\nSorting:" << endl;
    mergeSort(array, 0, arrayLength - 1);

    cout << "\nSorted array: ";
    outputArrayToConsole(array);

    return 0;
}
