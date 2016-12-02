#ifndef TABLE_H_INCLUDED
#define TABLE_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstdlib>

#define KEY 2000000000

void info_input(int*, int*); //ввод количество строк и столбцов
void help_input(); //пример вводимой матрицы
void input_data_in_table(float**, float**, int*, int*); //ввод матрицы
void check_for_solutions(float**, const int*, const int*); //проверка на наличие решения
int proverka(float**, int*, int*);
float search_lambda(float**, int*, int*); //поиск лямбда
void first_conversion(float**, float*, int*, int*, int*);
void second_conversion(float**, float*, int*, int*, int*);
void temp_copy(float**, float**, int*, int*);
void third_conversion(float**, float**, int*, int*, int*, int*);
void output_table (float**, int*, int*); //вывод таблицы
void copying (float**, float**, int*, int*);
void raschet(float**, int*);
void vibor(float**, int*, int*, int*, int*);


#endif // TABLE_H_INCLUDED
