#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main() {
#ifdef _WIN32

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    int a, b;
    int c;

    cout << "Введите катет a (высота): ";
    cin >> a;

    cout << "Введите катет b (основание): ";
    cin >> b;

    if (a || b <= 0 )
    {
        cout << "Ошибка. Кактет должен являться не отрицательный положительным числом и быть больше 0.";
        return 1;
    }

    int i = 1;

    while (i <= a) {
        double raw = 1 + (i - 1) * (b - 1) / double(a - 1);
        c = int(raw + 0.5);

        int u = 1;

        while (u <= c) {
            cout << "*";
            u++;
        }

        cout << endl;
        i++;
    }

    return 0;
}