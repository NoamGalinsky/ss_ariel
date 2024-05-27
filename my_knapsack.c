#include <stdio.h>
#define SIZE 5
#define MAX_WEIGHTS 20


int max(int a, int b){
    if (a>b)return a;
    return b;
}
void knapSackHelper( int dinamicMatrix[SIZE+1][MAX_WEIGHTS+1] ,int weights[], int selected_bool[]){
    int sum = dinamicMatrix[SIZE][MAX_WEIGHTS];
    int i = SIZE, j = MAX_WEIGHTS;
    while (sum){
        if (sum != dinamicMatrix[i-1][j]){
            selected_bool[i-1] = 1;
            j-=weights[i-1];
            
            sum = dinamicMatrix[i-1][j];
        }
        i--;
    }
}
int knapSack(int weights[], int values[] , int selected_bool[]){
    int dinamicMatrix[SIZE+1][MAX_WEIGHTS+1] = {0};
    for (int i = 1 ; i <= SIZE ; i++){
        for (int j = 1 ; j <= MAX_WEIGHTS ; j++){
            if (weights[i-1] > j){
                dinamicMatrix[i][j] = dinamicMatrix[i-1][j];
            }
            if(weights[i-1] == j){
                dinamicMatrix[i][j] = max(values[i-1], dinamicMatrix[i-1][j]);
            }
            if (weights[i-1] < j){
                dinamicMatrix[i][j] = max(dinamicMatrix[i-1][j], values[i-1] + dinamicMatrix[i-1][j-weights[i-1]]);

            }
        }
    }
   
    knapSackHelper(dinamicMatrix, weights, selected_bool);
    return dinamicMatrix[SIZE][MAX_WEIGHTS];
}

int main(){
    char result[SIZE][50];
    int weights[SIZE] = {0};
    int values[SIZE] = {0};
    
    int ans[SIZE]={0};
    for (int i=0; i<SIZE; i++){
        scanf("%49s", result[i]);
    }
    for (int i=0; i<SIZE; i++){
        scanf("%d", &values[i]);
    }
    for (int i=0; i<SIZE; i++){
        scanf("%d", &weights[i]);
    }

    int maxResult = knapSack(weights, values, ans);
    printf("Maximum profit: %d\n", maxResult);
    printf("items that give the maximum profit: [");
    int min1 =SIZE;
    for (int i = SIZE-1 ; i >= 0; i--){
        if (ans[i]){
            min1 = i;
        }
    }
    for (int i = SIZE-1 ; i >= 0 ; i--){
        if (ans[i]){
            printf("%s", result[i]);
            if (i > min1)printf(", ");
        }
    }
    printf("]");
    return 0;
}