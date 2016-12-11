#include "table.h"

using namespace std;



float search_lambda(float **array, int *str, int *stb){
    float temp_lambda = 0;
    temp_lambda = 1/array[*str][*stb];
    return temp_lambda;
}

void first_conversion(float **array, float *temp_lambda, int *K, int *str, int *stb){
    for (register int i=0; i<*K; i++){
        if (i == *stb){
            continue;//
        }
        else{
           array[*str][i] *= *temp_lambda;
        }
    }
}

void second_conversion(float **array, float *temp_lambda, int *N, int *str, int *stb){
    for (register int i=0; i<*N; i++){
        if (i == *str){
            continue;
        }
        else{
            array[i][*stb] *= -(*temp_lambda);
        }
    }
}

void temp_copy(float **array, float **temp_array, int *N, int *stb){
    for (register int i=0; i<*N; i++){
        temp_array[i][*stb] = array[i][*stb];
    }
}

void third_conversion(float **array, float **temp_array, int *N, int *K, int *str, int *stb){
    for (register int i=0; i<*N; i++){
        for (register int j=0; j<*K; j++){
            if (i == *str || j == *stb){
                continue;
            }
            else{
                float multiplier_first = temp_array[i][*stb];
                float multiplier_second = temp_array[*str][j];
                array[i][j] += multiplier_first * multiplier_second;
            }
        }
    }
}

void output_table(float **array, int *N, int *K){
    for (int i=0; i<*N; i++){
        for (int j=0; j<*K; j++){
            cout << setw(5) << array[i][j] << " ";
        }
        cout << endl;
    }
}
