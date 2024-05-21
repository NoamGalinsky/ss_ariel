#include "NumClass.h"
#define TRUE 1
#define FALSE 0

int power(int a, int b){
    int sum=1;
    for(int i = 0 ; i < b ; i++){
        sum=sum*a;
    }
    return sum;
}
int getSumRecursion(int number, int digit){
    if (number == 0){
        return FALSE;
    }
    return power(number%10, digit) + getSumRecursion(number/10, digit);
}
int numberOfDigit(int number){
    int ans = 0;
    while (number>0){
        ans++;
        number/=10;
    }
    return ans;
}
int isArmstrong(int number){
    int digit=numberOfDigit(number);
    if (getSumRecursion(number, digit)==number){
        return TRUE;
    }
    return FALSE;
}
int reverseRec(int number, int digit){
        if (digit == 0) return number;
    return (number % 10) * power(10, digit) + reverseRec(number / 10, digit-1);
}
int isPalindrome(int number){
    if (number >= 0 && number < 10){
        return TRUE;
    }
    return number == reverseRec(number, numberOfDigit(number)-1);
}

