// Task2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Задача №2
//«Длинная арифметика»
//Даны 2 числа A и B, количество цифр в которых может достигать 1000.
//Необходимо реализовать операцию сложения и умножения над этими числами.
//Будет засчитана только честная реализация(без спецбиблиотек и т.п.).
//

#include <iostream>;
#include <algorithm>;

char* coolest_addition( char a[], char b[]) {
    int a_len = strlen(a);
    int b_len = strlen(b);
    int res_len = a_len + b_len + 1;


    if ((a_len == 1 && a[0] == '0') && (b[0] == '0' && b_len == 1)) {
        char* result = new char[2];
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    char* result = new char[res_len];

    for (int i = 0; i < res_len - 1; i++) {
        result[i] = '0';
    }
    result[res_len - 1] = '\0';

    char a_n, b_n, sum;
    char carry_over = 0;

    for (int i = 0; i < res_len; i++) {
        a_n = i < a_len ? a[a_len - i - 1] - '0' : 0;
        b_n = i < b_len ? b[b_len - i - 1] - '0' : 0;

        sum = a_n + b_n + carry_over;
        result[res_len - i - 1] = sum % 10 + '0';
        carry_over = sum / 10;
    }
    std::cout << result << "\n";

    if ((res_len > 1) && (result[0] == '0')) {
        int zero_offset = 0;
        for (int i = 0; i < res_len; i++) {
            if (result[i] == '0') {
                zero_offset += 1;
            }
            else {
                break;
            }
        }
        char* tmp = new char[res_len - zero_offset + 1];
        memcpy(tmp, result + zero_offset, (res_len - zero_offset) * 4);
        tmp[res_len - zero_offset] = '\0';
        delete[] result;
        result = tmp;
    }
    return result;
}


char* multiplication(char a[], char b[]) {

    int a_len = strlen(a);
    int b_len = strlen(b);

    int res_len = a_len * b_len + 2;


    if ((a_len == 1 && a[0] == '0') or (b[0] == '0' && b_len == 1)) {
        char* result = new char[2];
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    char* result = new char[res_len];
    for (int i = 0; i < res_len-1; i++) {
        result[i] = '0';
    }
    result[res_len - 1] = '\0';

    char a_n, b_n, res_n, sum;
    char carry_over = 0;

    //for every number in b
    for (int i = 0; i < b_len; i++) {

        b_n = i < b_len ? b[b_len - i - 1] - '0' : 0;

        //multiply number in a by b
        for (int j = 0; j < a_len + 1; j++) {
            a_n = j < a_len ? a[a_len - j - 1] - '0' : 0;
            res_n = result[res_len - i - j - 2] - '0';

            //and add it to result
            sum = res_n + a_n * b_n + carry_over;
            result[res_len - i - j - 2] = sum % 10 + '0';
            carry_over = sum / 10;
        }
    }
    std::cout << result << "\n";

    //Remove zeroes from the beggining 
    if ((res_len > 1) && (result[0]=='0')) {
        int zero_offset= 0;
        for (int i = 0; i < res_len -1; i++) {
            if (result[i] == '0') {
                zero_offset += 1;
            }
            else {
                break;
            }
        }
        char* tmp = new char[res_len-zero_offset + 1];
        memcpy(tmp,result+zero_offset,(res_len - zero_offset - 1)*4);
        tmp[res_len - zero_offset] = '\0';
        delete[] result;
        result = tmp;
    }
    return result;
}



char a[] = "99";
char b[] = "11";

int main()
{

    char* ares;
    char* mres;

    ares = coolest_addition( a, b);
    mres = multiplication( a, b);

    std::cout << ares << "\n";
    std::cout << mres << "\n";

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
