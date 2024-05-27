#include "my_mat.h"
#include <stdio.h>
#define LENGTH 10
int min(int a, int b){
    if (a<b)return a;
    return b;
}
void foo1(int matrix[LENGTH][LENGTH]){
    for (int i = 0 ; i < LENGTH ; i++){
        for (int j = 0 ; j < LENGTH ; j++){
            scanf("%d", &matrix[i][j]);
            if (i != j && matrix[i][j] == 0){
                matrix[i][j] = 99999999;
            }
        }
    }
}
int foo2(int matrix[LENGTH][LENGTH], int i, int j){
    int tempMatrix1[LENGTH][LENGTH];
    int tempMatrix2[LENGTH][LENGTH];
    for (int h = 0 ; h < LENGTH ; h++){
        for (int g = 0 ; g < LENGTH ; g++){
            tempMatrix1[h][g]=matrix[h][g];
            tempMatrix2[h][g]=matrix[h][g];
        }
    }
    for (int k = 0 ; k < LENGTH ; k++){
        for (int h = 0 ; h < LENGTH ; h++){
            for (int g = 0 ; g < LENGTH ; g++){
                tempMatrix1[h][g]=min(tempMatrix2[h][g], tempMatrix2[h][k] + tempMatrix2[k][g]);
            }
        }
        for (int h = 0 ; h < LENGTH ; h++){
            for (int g = 0 ; g < LENGTH ; g++){
                tempMatrix2[h][g]=tempMatrix1[h][g];
            }
        }
    }
    return tempMatrix1[i][j];
}