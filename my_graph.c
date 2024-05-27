#include "my_mat.h"
#include <stdio.h>
#define LENGTH 10
int main(){
    int matrix[LENGTH][LENGTH]={0};
    char ans='A';
    while (ans != 'D'){
        scanf("%c", &ans);
        if (ans=='A'){
            foo1(matrix);
        }
        if (ans == 'B'){
            int i ,j;
            scanf("%d %d", &i ,&j);
            int ans = foo2(matrix, i, j);
            if (ans && ans != 99999999){
                printf("True\n");
           }
            else{
                printf("False\n");
            }
        }
        if (ans == 'C'){
            int i ,j;
            scanf("%d %d", &i ,&j);
             int ans = foo2(matrix, i, j);
            if (ans && ans != 99999999){
                printf("%d\n", ans);
            }
            else{
                printf("-1\n");
            }
        }
    }
    

    return 0;
}