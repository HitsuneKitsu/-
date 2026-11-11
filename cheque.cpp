/*
Программа предствлена как для работы в виндовс с кодировкой utf 8 так и на unix
в ней есть недоработки ввиде бессконечного ввода цены от чего чек теряет условие в 40 символов
основное условие - кроссплатформенность - выполнено

основные материалы
-microsoft - сайт с документацие где указан был способ решения для виндовс
-youtube   - для просмотра видеоуроков для понимания что выполняет оператор и неизвестная мне лексема
-stackoverflow - для просмотра примеров как реализуют данную проблему
-хабр Q&A - для вопросов по устройству программы
-perplexety  - ии для помощи в написании кода для виндовс и помощи в понимании логики функций
*/
#include <iostream>
#include <string>


#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

#ifdef _WIN32
string readLineUtf8() {
    HANDLE input = GetStdHandle(STD_INPUT_HANDLE);
    wchar_t wideBuffer[512];
    DWORD readChars = 0;

    if (!ReadConsoleW(input, wideBuffer, 512, &readChars, nullptr)) {
        return "";
    }

    while (readChars > 0 &&
        (wideBuffer[readChars - 1] == L'\r' ||
         wideBuffer[readChars - 1] == L'\n')) {
        readChars--;
    }

    int utf8Size = WideCharToMultiByte(
        CP_UTF8, 0, wideBuffer,
        static_cast<int>(readChars),
        nullptr, 0, nullptr, nullptr
    );

    string result(utf8Size, '\0');



    return result;
}
#else
//сохраняем в строке line, getline принимает ввод с пробелами возращаем line
string readLineUtf8() {
    string line;
    getline(cin, line);
    return line;
}
#endif

/*
функция получает данные в виде строки и введёт подсчёт символов
Она поочередно проверяет первые два бита каждого байта, если первые два бита = 10 то условие ложно и count 
не выполняется, если истинно то выполняем инкремент
*/
int countLetters(const string& text) {
    int count = 0;
    for (unsigned char c : text) {
        if ((c & 0xC0) != 0x80) count++;
    }
    return count;
}

/*
функция space выполняет блок проверки где проверятся что введённые
пользоватеоем символы(used) >= ширины строки. оператор ? если истина а : значение если ложь
*/
int spaces(int width, int used) {
    return used >= width ? 0 : width - used;
}

// валидация ввода, проверяет чтобы числа не были отрицательными
void validateNonNegative(int value, const string& fieldName) {
    if (value < 0) {
        cout << "Ошибка: " << fieldName << " должно быть неотрицательным числом.\n";
        exit(1); //exit выход из программы с ошибкой
    }
}
// вывод готового тела чека
//передаём к примеру label = цена: value = 3 suffix = k width = 40
void printReceiptRow(const string& label, const string& value,const string& suffix, int width) {
    int used = countLetters(label) + countLetters(value) + countLetters(suffix); // Получаем общее число символов. передаём три значения label название, value число в колонки, suffix  суффикс на конце
    int padding = spaces(width, used); // функция вычесления пробелов
    cout << label << string(padding, ' ') << value << suffix << '\n'; //выводим
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    const int width = 40;
    const string k = "руб";

    string product;
    int price, howmon, weiprod, total, change;

    cout << "Укажите продукт: ";
    product = readLineUtf8();

    cout << "Укажите цену товара: ";
    cin >> price;
    validateNonNegative(price, "Цена"); 

    cout << "Укажите вес товара: ";
    cin >> weiprod;
    validateNonNegative(weiprod, "Вес");

    cout << "Укажите, сколько у вас денег: ";
    cin >> howmon;
    validateNonNegative(howmon, "Количество денег");

    //блок вычесление сдачи, с проверкой на хватает ли денег
    total = weiprod * price;

    if (total > howmon) {
        cout << "Ошибка: вам не хватает средств.\n";
        return 1;
    }

    change = howmon - total;
    
    //переводим переменные в string для того чтобы подсчитать количество символов
    string price_str = to_string(price);
    string howmon_str = to_string(howmon);
    string total_str = to_string(total);
    string change_str = to_string(change);

    //вычитаем из общей длины 40 количество символов 3 и делим на 2, (40-3)/2 = 18
    int check_len = (width - countLetters("чек")) / 2;
    //вычитаем из обзей длины 40 количество символов 3 и вычитаем 18, для правильного отображения правых символов
    int check_right_len = width - countLetters("чек") - check_len;

    //вывод всей информации
    cout << string(check_len, '=') << "чек" << string(check_right_len, '=') << '\n';

    printReceiptRow("Товар:", product, "", width);
    printReceiptRow("Цена:", price_str, "руб/кг", width);
    printReceiptRow("Итого:", total_str, k, width);
    printReceiptRow("Внесено:", howmon_str, k, width);
    printReceiptRow("Сдача:", change_str, k, width);

    cout << string(width, '=') << '\n';
    return 0;
}