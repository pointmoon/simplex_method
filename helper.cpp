#include "table.h"

using namespace std;
bool flg = false;

void info_input(int *N, int *K){
    cout << "Введите количство строк: " << endl;
    cin >> *N;
    cout << "Введите количство столбцов: " << endl;
    cin >> *K;
}

void input_data_in_table(float **array, float **temp_array, int *N, int *K){
    for (register int i=0; i<*N; i++){
        for (register int j=0; j<*K; j++){
            cin >> array[i][j];
            temp_array[i][j] = array[i][j];
        }
    }
}

void help_input(){
    cout << "Введите массив вида:" << endl;
    cout << "\t   |sv x1 x2 ..." << endl;
    cout << "\t   |------------" << endl;
    cout << "\t  L|.. .. .. ..." << endl;
    cout << "\t y1|.. .. .. ..." << endl;
    cout << "\t y2|.. .. .. ..." << endl;
    cout << "\t y3|.. .. .. ..." << endl;
    cout << "\t...|.. .. .. ..." << endl;

}

int proverka(float **array, int *N, int *K){
    for (register int i=0; i<*K; i++){
        if (array[0][i] > 0){
            flg = true;
            return i;
        }
    }
    raschet(array, N);
    return KEY;
}

void raschet(float **array, int *N){
    cout << "resheniye naydeno:" << endl;
    if (flg == true){
        for (register int i=1; i<*N; i++){
           cout << array[i][0] << " ";
        }
        cout << endl;
    }
    else{
    //do it
    }
}

void vibor(float **array, int *N, int *K, int *index_plus_elem, int *number_str){
    int arr[*K];
    int count = 0;
    for (register int i=1; i<*N; i++){
        if (array[i][*index_plus_elem] > 0){
            arr[count] = i;
            count++;
        }
    }

    float temp[count];

    for (register int i=0; i<count; i++){
       float chisl = array[arr[i]][0];
       float znam = array[arr[i]][*index_plus_elem];
       temp[i] = chisl / znam;
    }

    int out_st = 0;

    for (register int i=0; i<count-1; i++){
        if (temp[i] < temp[i+1]){
            out_st = arr[i];
        }
        else{
            out_st = arr[i+1];
        }
    }

    *number_str = out_st;

    if (count == 1){
        *number_str = arr[count-1];
    }
}

void check_for_solutions(float **array, const int *N, const int *K){
    bool flag = false;
    for (register int i=0; i<*K; i++){
        if(array[0][i] > 0){
            for (register int j=1; j<*N; j++){
                if(array[i][j] > 0){
                    flag = true;
                }
            }
        }
    }
    if (flag == false){
        cout << endl <<"Решения нет." << endl;
        exit(EXIT_FAILURE);
    }
}

void copying (float **array, float **array_temp, int *N, int *K){
    for (register int i=0; i<*N; i++){
        for (register int j=0; j<*K; j++){
            array_temp[i][j] = array[i][j];
        }
    }
}
