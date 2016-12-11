#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>

#define KEY 2000000000

#define stop_1 "\nРешения нет, т.к. система уравнений\nнесовместима с неравенствами!\n\
p.s. При отсутствии отрицательных\nэлементов в строке вся правая часть\n\
соответсвующего уравнения может быть\nтолько отрицательной, а это противоречит условиям\n\
неотрицательности переменных."

#define stop_2 "\nОДР не ограничена сверху.\n"

#define stop_3 "\nОДР не ограничена снизу.\n"

#define help_in_array()\
    cout << "Введите массив вида:" << endl;\
    cout << "\t   |Св|x1|x2|..." << endl;\
    cout << "\t   -------------" << endl;\
    cout << "\t  L|..|..|..|..." << endl;\
    cout << "\t   -------------" << endl;\
    cout << "\t y1|..|..|..|..." << endl;\
    cout << "\t   -------------" << endl;\
    cout << "\t y2|..|..|..|..." << endl;\
    cout << "\t   -------------" << endl;\
    cout << "\t y3|..|..|..|..." << endl;\
    cout << "\t   -------------" << endl;\
    cout << "\t...|..|..|..|..." << endl;

void info_input(int*, int*, std::string*); //ввод количество строк и столбцов
void input_data_in_table(float**, float**, int*, int*); //ввод матрицы
void check_for_solutions(float**, const int*, const int*); //проверка на наличие решения
int proverka(float**, int*, int*, bool*, bool*);
float search_lambda(float**, int*, int*); //поиск лямбда
void first_conversion(float**, float*, int*, int*, int*);
void second_conversion(float**, float*, int*, int*, int*);
void temp_copy(float**, float**, int*, int*);
void third_conversion(float**, float**, int*, int*, int*, int*);
void output_table (float**, int*, int*); //вывод таблицы
void copying (float**, float**, int*, int*);
void raschet(float**, int*, int*);
void vibor(float**, int*, int*, int*, int*, std::string*);
void oporniy_vibor(float**, int*, int*, int*, int*);

#endif // TABLE_H_INCLUDED
