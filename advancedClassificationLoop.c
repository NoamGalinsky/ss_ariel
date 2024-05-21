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
int numberOfDigit(int number){
    int ans = 0;
    while (number>0){
        ans++;
        number/=10;
    }
    return ans;
}
int isArmstrong(int number){
    if (number < 1){
        return 0;
    }
    int digit = numberOfDigit(number);
    int sum=0;
    int temp=number;
    int lastBit=number%10;
    while (temp > 0){
        sum=sum + power(lastBit, digit);
        temp=temp/10;
        lastBit=temp%10;
    }
    if (number == sum){
        return TRUE;
    }
    return FALSE;
}
int isPalindrome(int number){
    if (number < 0){
        return FALSE;
    }
    int sum=0;
    int temp = number;
    int lastBit=number%10;
    int digit= numberOfDigit(number)-1;
    while (temp > 0){
        sum+= lastBit*(power(10,digit));
        temp=temp/10;
        lastBit=temp%10;
        digit--;
    }
    if (number == sum){
        return TRUE;
    }
    return FALSE;
}
