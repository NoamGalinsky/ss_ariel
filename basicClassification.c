#include "NumClass.h"
#define TRUE 1
#define FALSE 0

int isPrime(int number){
    for (int i = 2 ; i*i <= number ; i++){
        if (number % i == 0 && i != number){
            return FALSE;
        }
    } 
    return TRUE;
}
int factorial(int number){
    int i=number-1;
    while (i > 0){
        number=number*i;
        i--;
    }
    return number;
}
int isStrong(int number){
    if (number < 1){
        return FALSE;
    }
    int sum=0;
    int temp=number;
    int lastBit=number%10;
    while (temp > 0){
        sum+=factorial(lastBit);
        temp=temp/10;
        lastBit=temp%10;
    }
    if (number == sum){
        return TRUE;
    }
    return FALSE;
}
