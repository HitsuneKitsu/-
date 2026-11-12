#include <iostream>
#include <iomanip> // Для setprecision и fixed
#include <cmath>   // Для функции sqrt

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main() {
#ifdef _WIN32
    // Переключаем консоль Windows на UTF-8
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    double a, b, c; // Коэффициенты уравнения
    double prom_res, x1, x2, perestav; // Дискриминант, корни и временная переменная

    // Ввод коэффициентов
    cout << "Введите параметр a: " << endl;
    cin >> a;

    cout << "Введите параметр b: " << endl;
    cin >> b;

    cout << "Введите параметр c: " << endl;
    cin >> c;

    // Установка вывода чисел с точностью до сотых
    cout << fixed << setprecision(2);

    // Случай 0 = 0: решений бесконечно много
    if (a == 0 && b == 0 && c == 0) {
        cout << "Infinite solutions" << endl;
        return 0;
    }
    // Случай c = 0, где c != 0: решений нет
    else if (a == 0 && b == 0 && c != 0) {
        cout << "No solution" << endl;
        return 0;
    }
    // Линейное уравнение: b*x + c = 0
    else if (a == 0) {
        x1 = -c / b;
        cout << "x= " << x1 << endl;
        return 0;
    }

    // Вычисление дискриминанта
    prom_res = (b * b) - 4 * a * c;

    // Один корень, если дискриминант равен нулю
    if (prom_res == 0) {
        x1 = -b / (2 * a);
        cout << "x= " << x1 << endl;
        return 0;
    }
    // Нет действительных корней, если дискриминант меньше нуля
    else if (prom_res < 0) {
        cout << "No solution" << endl;
        return 0;
    }
    // Два различных корня
    else {
        x1 = (-b + sqrt(prom_res)) / (2 * a);
        x2 = (-b - sqrt(prom_res)) / (2 * a);

        if (x1 > x2) {
            perestav = x1;
            x1 = x2;
            x2 = perestav;
        }

        cout << "x1= " << x1 << ", x2= " << x2 << endl;
    }

    return 0;
}