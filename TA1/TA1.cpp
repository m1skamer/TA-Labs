#include <iostream>
#include <vector>

using namespace std;

// Функция для проверки, является ли число простым
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "RU");
    vector<int> primeNumbers; // Массив для хранения простых чисел
    int N;

    do {
        // Запрашиваем у пользователя количество простых чисел N (0 для завершения)
        cout << "Введите количество простых чисел N (0 для завершения): ";
        cin >> N;

        if (N == 0) {
            break; // Если N равно 0, завершаем программу
        }

        int count = 0;
        for (int i = 2; count < N; ++i) {
            if (isPrime(i)) {
                if (count < primeNumbers.size()) {
                    // Выводим число из массива с пометкой *, если оно уже было вычислено ранее
                    cout << "*" << primeNumbers[count] << " ";
                }
                else {
                    // Выводим рассчитанное простое число и добавляем его в массив
                    cout << i << " ";
                    primeNumbers.push_back(i);
                }
                ++count;
            }
        }
        cout << endl; // Переходим на новую строку после вывода всех чисел

    } while (N != 0); // Повторяем цикл, пока N не равно 0

    return 0;
}