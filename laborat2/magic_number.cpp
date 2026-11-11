#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main() {
#ifdef _WIN32
    // Включаем UTF-8 для вывода и ввода в консоли Windows
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    int a, b, c, d, num_one, num_two;
    int min1, min2, min, max1, max2, max, mid, mid1, mid2;

    cout << "Введите первое защитное число Зерона: " << endl;
    cin >> num_one;

    cout << "Введите второе защитное число Зерона: " << endl;
    cin >> num_two;

    //проверка введённых чисел на трёхзначность и отрицательное значение
    if (num_one > 99 || num_one < 0 || num_two > 99 || num_two < 0) {
        cout << "Ошибка. Введите два двузначных неотрицательных числа.";
        return 1;
    }

    a = num_one / 10;
    b = num_one % 10;

    c = num_two / 10;
    d = num_two % 10;
    // Максимум и минимум из первого числа
    if (a < b) {
        max1 = b;
        min1 = a;
    }
    else {
        max1 = a;
        min1 = b;
    }
    // Максимум и минимум из второго числа
    if (c < d) {
        max2 = d;
        min2 = c;
    }
    else {
        max2 = c;
        min2 = d;
    }
    // Общий максимум
    if (max1 > max2) {
        max = max1;
        mid1 = max2;
    }
    else {
        max = max2;
        mid1 = max1;
    }
    // Общий минимум
    if (min1 > min2) {
        min = min2;
        mid2 = min1;
    }
    else {
        min = min1;
        mid2 = min2;
    }
    // Средняя цифра: сумма двух оставшихся цифр без переноса
    mid = (mid1 + mid2) % 10;

    cout << "Магическое число: " << max << mid << min << endl;

    return 0;
}