#include "table.h"

using namespace std;
bool flg = false;

void info_input(int *N, int *K, string *MAXorMIN){
    cout << "Максимизировать или минимизировать целевую функцию?" << endl;
    cout << "Введите max или min" << endl;
    cin >> *MAXorMIN;
    cout << "Введите количество строк: " << endl;
    cin >> *N;
    cout << "Введите количество столбцов: " << endl;
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

int proverka(float **array, int *N, int *K, bool *flag_main, bool *flag_first_or_not){
    int razresh = 0;

    if(*flag_first_or_not == true){
        *flag_first_or_not = false;
        for(register int i=1; i<*N; i++){
            if (array[i][0] < 0){
                //cout << array[i][0] << " ";
                for (register int j=1; j<*K; j++){
                    if (array[i][j] < 0){
                        razresh = j;
                        *flag_main = true;
                        break;
                    }   //if
                    if (j == *K-1){
                        cout << stop_1 << endl;
                        exit(EXIT_SUCCESS);
                    }   //if
                }   //for
            }   //if
        }   //for

        if(*flag_main == true){
            for (register int i=1; i<*N; i++){
                if (((array[i][0] < 0) && (array[i][razresh] < 0)) || ((array[i][0] > 0) && (array[i][razresh] > 0))){
                    return razresh;
                }   //if
            }   //for
        }   //if
    }   //if(*flag_first_or_not == true)

    for (register int i=1; i<*K; i++){ //i=0 past
        if (array[0][i] > 0){
            flg = true;
            return i;
        }   //if
    }   //for
    flg = true;
    raschet(array, N, K);
    return KEY;
}   //proverka()

void raschet(float **array, int *N, int *K){
    cout << "Оптимальное решение найдено:" << endl;
    if (flg == true){
        for (register int i=1; i<*N; i++){
           cout << array[i][0] << " ";
        }
        cout << endl;
    }
    //do it
}

void vibor(float **array, int *N, int *K, int *index_plus_elem, int *number_str, std::string *MAXorMIN){
    int arr[*K];
    int count = 0;

    for (register int i=1; i<*N; i++){
        if (array[i][*index_plus_elem] > 0){
            arr[count] = i;
            count++;
        }
    }

    if (count == 0){
        cout << "Решения нет!" << endl;
        if (*MAXorMIN == "max" || *MAXorMIN == "MIN"){
            cout << stop_2;
        }
        if (*MAXorMIN == "min" || *MAXorMIN == "MIN"){
            cout << stop_3;
        }
        exit(EXIT_SUCCESS);
    }

    float temp[count];

    int schitalka = 0;
    for (register int i=0; i<count; i++){
       float chisl = array[arr[i]][0];
       float znam = array[arr[i]][*index_plus_elem];
       if (znam == 0){
        continue;
       }
       else{
        temp[schitalka] = chisl / znam;
       schitalka++;
       }
    }

    int out_st = 0;

    for (register int i=0; i<schitalka-1; i++){
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
    for (register int i=1; i<*K; i++){ //i=0 redoing
        if(array[0][i] > 0){
            for (register int j=1; j<*N; j++){
                if(array[j][i] > 0){ //i <-> j
                    flag = true;
                    break;
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

void oporniy_vibor(float **array, int *N, int *K, int *index_plus_elem, int *number_str){
    int count = 0;
    int indeks[*N];
    for (register int i=0; i<*N; i++){
        if (((array[i][0] < 0) && (array[i][*index_plus_elem] < 0)) || ((array[i][0] > 0) && (array[i][*index_plus_elem] > 0))){
            indeks[count] = i;
            count++;
        }
    }

    if (count == 1){
        *number_str = indeks[0];
    }
    else{
        float temp[count];
        int schitalka = 0;
        for (register int i=0; i<count; i++){
           float chisl = array[indeks[i]][0];
           float znam = array[indeks[i]][*index_plus_elem];
           if (znam == 0){
            continue;
           }
           else{
            temp[schitalka] = chisl / znam;
           schitalka++;
           }
        }

        int out_st = 0;

        for (register int i=0; i<schitalka-1; i++){
            if (temp[i] < temp[i+1]){
                out_st = indeks[i];
            }
            else{
                out_st = indeks[i+1];
            }

        }
        *number_str = out_st;
    }
}
