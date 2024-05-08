#include <typeinfo>
#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <string>
#include <clocale>
#include <iomanip>
#include <windows.h>
using namespace std;

clock_t get_time_clock() {
    return clock();
}

long get_time_asm() {
    _asm rdtsc;
}

clock_t test1_char() {
    char a = '1';
    clock_t start = get_time_clock();
    for (size_t i = 0; i < 10000; i++) {
        printf("%c", a);
    }
    return (get_time_clock() - start);
}

clock_t test1_int() {
    clock_t start = get_time_clock();
    for (size_t i = 0; i < 10000; i++) {
        printf("%i", i);
    }
    return (get_time_clock() - start);
}

clock_t test1_double() {
    clock_t start = get_time_clock();
    for (size_t i = 0; i < 10000; i++) {
        printf("%lf", (double)i);
    }
    return (get_time_clock() - start);
}

clock_t test1_chararr() {
    char a[] = "PKIMS RULEZ";
    clock_t start = get_time_clock();
    for (size_t i = 0; i < 10000; i++) {
        printf("%s", a);
    }
    return (get_time_clock() - start);
}

clock_t test2_char() {
    char a = 'a';
    clock_t start = get_time_clock();
    for (size_t i = 0; i < 10000; i++) {
        cout << a;
    }
    return (get_time_clock() - start);
}

clock_t test2_int() {
    clock_t start = get_time_clock();
    for (size_t i = 0; i < 10000; i++) {
        cout << i;
    }
    return (get_time_clock() - start);
}

clock_t test2_double() {
    clock_t start = get_time_clock();
    for (size_t i = 0; i < 10000; i++) {
        cout << (double)i;
    }
    return (get_time_clock() - start);
}

clock_t test2_chararr() {
    char a[] = "PKIMS RULEZ";
    clock_t start = get_time_clock();
    for (size_t i = 0; i < 10000; i++) {
        cout << a;
    }
    return (get_time_clock() - start);
}

long sort1(vector<int> q) {
    long start = get_time_asm();
    sort(q.begin(), q.end());
    return (get_time_asm() - start);
}

long sort2(vector<int>& q) {
    long start = get_time_asm();
    int n = q.size();
    for (int i = 1; i < n; ++i) {
        int key = q[i];
        int j = i - 1;

        while (j >= 0 && q[j] > key) {
            q[j + 1] = q[j];
            j = j - 1;
        }
        q[j + 1] = key;
    }
    return (get_time_asm() - start);
}

void test_sort() {
    vector<int> v1, v2, v3;

    for (size_t i = 0; i < 3; i++) {
        v1.push_back(rand());
    }

    for (size_t i = 0; i < 5; i++) {
        v2.push_back(rand());
    }

    for (size_t i = 0; i < 10; i++) {
        v3.push_back(rand());
    }

    vector<int> v1Copy = v1;
    vector<int> v2Copy = v2;
    vector<int> v3Copy = v3;

    long sort1_a = sort1(v1Copy);
    long sort1_b = sort1(v2Copy);
    long sort1_c = sort1(v3Copy);

    long sort2_a = sort2(v1);
    long sort2_b = sort2(v2);
    long sort2_c = sort2(v3);

    cout << "\n";
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "\t\tРЕЗУЛЬТАТЫ СОРТИРОВКИ\n";
    cout << "                 " << "3" << setw(10) << "5" << setw(8) << "10" << setw(8) << endl;
    cout << "std::sort" << "\t" << sort1_a << "\t" << sort1_b << "\t" << sort1_c << "\t" << endl;
    cout << "insertion_sort" << "\t" << sort2_a << "\t" << sort2_b << "\t" << sort2_c << "\t" << endl;
    cout << "---------------------------------------------------------------------------------------\n";
}

int main() {
    setlocale(LC_ALL, "Rus");
    // Объявление и инициализация вектора
    vector<int> numbers = { 1, 2, 3, 4, 5 };

    // Добавление элементов в вектор
    numbers.push_back(6);
    numbers.push_back(7);

    // Вставка элемента на определенную позицию
    numbers.insert(numbers.begin() + 2, 8);

    // Удаление элемента на определенной позиции
    numbers.erase(numbers.begin() + 4);

    // Использование алгоритма for_each для вывода элементов
    cout << "Элементы вектора: ";
    for_each(numbers.begin(), numbers.end(), [](int число) {
        cout << число << " ";
        });
    cout << endl;

    // Использование алгоритма random_shuffle для перемешивания элементов
    random_shuffle(numbers.begin(), numbers.end());

    // Вывод перемешанных элементов
    cout << "Перемешанные элементы: ";
    for_each(numbers.begin(), numbers.end(), [](int число) {
        cout << число << " ";
        });
    cout << endl;

    clock_t test1_a = test1_char();
    clock_t test1_b = test1_int();
    clock_t test1_c = test1_double();
    clock_t test1_d = test1_chararr();

    clock_t test2_a = test2_char();
    clock_t test2_b = test2_int();
    clock_t test2_c = test2_double();
    clock_t test2_d = test2_chararr();

    cout << "\n";
    cout << "---------------------------------------------------------------------------------------\n";
    cout << "\t\tРЕЗУЛЬТАТЫ ТЕСТА\n";
    cout << "\tchar\t int\tdouble\tPKIMS RULEZ" << endl;
    cout << "printf " << test1_a << "\t " << test1_b << "\t" << test1_c << "\t" << test1_d << "\t" << endl;
    cout << "cout   " << test2_a << "\t" << " " << test2_b << "\t" << test2_c << "\t" << test2_d << "\t" << endl;
    cout << "---------------------------------------------------------------------------------------";
    test_sort();
    return 0;
}