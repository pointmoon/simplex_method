#include "table.h"
#include "helper.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "Rus");
    int number_of_rows = 0; //кол-во строк
    int number_of_columns = 0; //кол-во столбцов
    string MAXorMIN;

    info_input(&number_of_rows, &number_of_columns, &MAXorMIN);

    float **ptr_array = new float *[number_of_rows];
    float **ptr_temp_array = new float *[number_of_rows];

    for (register int i=0; i<number_of_rows; i++){
        ptr_array[i] = new float[number_of_columns];
        ptr_temp_array[i] = new float[number_of_columns];
    }

    help_in_array(); //пример вводимой матрицы
    input_data_in_table(ptr_array, ptr_temp_array, &number_of_rows, &number_of_columns);

    check_for_solutions(ptr_array, &number_of_rows, &number_of_columns);

    int enumerator = 0; //счётчик
    int repository[number_of_rows * number_of_columns][2];
    int index_plus_elem;
    bool first_flag = true;

    while (1){

    bool flag = false;
    int number_str = 0;

    copying(ptr_array, ptr_temp_array, &number_of_rows, &number_of_columns);
    index_plus_elem = 0;

    index_plus_elem = proverka(ptr_array, &number_of_rows, &number_of_columns, &flag, &first_flag);
    //cout << "index_plus_elem = " << index_plus_elem << endl;
    if (index_plus_elem == KEY){
        break;
    }

    if (flag == false){
        vibor(ptr_array, &number_of_rows, &number_of_columns, &index_plus_elem, &number_str, &MAXorMIN);
    }
    else{
        oporniy_vibor(ptr_array, &number_of_rows, &number_of_columns, &index_plus_elem, &number_str);
    }

    repository[enumerator][0] = number_str;
    repository[enumerator][1] = index_plus_elem;
    enumerator++;

    float lambda = 0;
    lambda = search_lambda(ptr_array, &number_str, &index_plus_elem);
    //cout << "lambda = " << lambda << endl;
    ptr_array[number_str][index_plus_elem] = lambda;

    first_conversion(ptr_array, &lambda, &number_of_columns, &number_str, &index_plus_elem);
    second_conversion(ptr_array, &lambda, &number_of_rows, &number_str, &index_plus_elem);
    temp_copy(ptr_array, ptr_temp_array, &number_of_rows, &index_plus_elem);//&number_of_rows
    third_conversion(ptr_array, ptr_temp_array, &number_of_rows, &number_of_columns, &number_str, &index_plus_elem);
    }//while

    if (index_plus_elem == KEY){
        output_table(ptr_array, &number_of_rows, &number_of_columns);
        for (register int i=0; i<enumerator; i++){
            cout << "str: " << repository[i][0] << " stb: " << repository[i][1] << endl;
        }//for

        if (MAXorMIN == "max" || MAXorMIN == "MAX"){
            cout << "Оптимальное значение функции L_max = " << abs(ptr_array[0][0]);
        }//if
        else{
            cout << "Оптимальное значение функции L_min = " << ptr_array[0][0];
        }//else
    }//if

    for (register int i=0; i<number_of_rows; i++){
        delete []ptr_array[i];
        delete []ptr_temp_array[i];
    }//for

    delete ptr_array;
    delete ptr_temp_array;
    return 0;
}
