#include <iostream> //developed by Roman Antoshchuk on 01.05.2024
#include <string>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

// подільність на 15 за моїм ефективним алгоритмом
bool checkDivisibilityBy15Optimized(const std::string& binaryNumber) {
    int oddSum = 0, evenSum = 0;
    int length = binaryNumber.length();

    // подільність на 3 суми
    for (int i = 0; i < length; ++i) {
        if (binaryNumber[i] == '1') {
            if ((i % 2) == 0) {
                evenSum += 1;
            }
            else {
                oddSum += 1;
            }
        }
    }
    if (std::abs(evenSum - oddSum) % 3 != 0) {
        return false;
    }

    // подільність на 5 останніх трьох бітів
    if (length < 3) {
        return false;
    }
    std::string lastThreeBits = binaryNumber.substr(length - 3);
    if (lastThreeBits != "000" && lastThreeBits != "101") {
        return false;
    }

    return true;
}

// ПЕРЕВІРКА ПОДІЛЬНОСТІ ЗВИЧАЙНИМ СПОСОБОМ з конвертацією
bool checkDivisibilityBy15Normal(const std::string& binaryNumber) {
    long long decimalNumber = 0;
    int length = binaryNumber.length();

    for (int i = 0; i < length; i++) {
        if (binaryNumber[i] == '1') {
            decimalNumber += 1LL << (length - i - 1);
        }
    }

    return (decimalNumber % 15 == 0);
}

int main() {
    std::string binaryNumber;
    cout << "Введіть двійкове число: ";
    cin >> binaryNumber;

        if (checkDivisibilityBy15Optimized(binaryNumber)) {
            cout << "Оптимізований метод: Число ділиться на 15" << endl;
        }
        else {
            cout << "Оптимізований метод: Число не ділиться на 15" << endl;
        }

        if (checkDivisibilityBy15Normal(binaryNumber)) {
            cout << "Звичайний метод: Число ділиться на 15" << endl;
        }
        else {
            cout << "Звичайний метод: Число не ділиться на 15" << endl;
        }

    return 0;
}
