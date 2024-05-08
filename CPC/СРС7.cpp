#include <iostream>
#include <bitset>

// Функция для определения являются ли числа соседними по коду Грэя
bool areGrayNeighbors(int num1, int num2) {
    std::bitset<4> bits1(num1);
    std::bitset<4> bits2(num2);

    int diffCount = 0;

    for (int i = 0; i < 4; ++i) {
        if (bits1[i] != bits2[i]) {
            ++diffCount;
        }
    }

    return diffCount == 1;
}

int main() {
    setlocale(LC_ALL, "Ru");
    int number1, number2;

    std::cout << "Вводите два 4-битных числа в виде единого целого числа (например, 0101)\nВведите первое число: ";
    std::cin >> number1;

    std::cout << "Введите второе число: ";
    std::cin >> number2;

    bool result = areGrayNeighbors(number1, number2);

    if (result) {
        std::cout << "Введенные числа являются соседними по коду Грэя.\n";
    }
    else {
        std::cout << "Введенные числа не являются соседними по коду Грэя.\n";
    }

    return 0;
}