    #include "NumClass.h"
    #include <stdio.h>
int main(){
    int first, last;
    scanf("%d" , &first);
    scanf("%d" , &last);
    if (first > last || last < 0){
    printf("your input is invalid");
    return 0;
    }
    if (first < 0){
        first=0;
    }
    printf("The Armstrong numbers are:");
    for (int i = first; i <= last; i++){
        if (isArmstrong(i)){
            printf(" %d" , i);
        }
    }
    printf("\nThe Palindromes are:");
    for (int i = first; i <= last; i++){
        if (isPalindrome(i)){
            printf(" %d" , i);
        }
    }
    printf("\nThe Prime numbers are:");
    for (int i = first; i <= last; i++){
        if (isPrime(i)){
            printf(" %d" , i);
        }
    }
    printf("\nThe Strong numbers are:");
    for (int i = first; i <= last; i++){
        if (isStrong(i)){
            printf(" %d" , i);
        }
    }
    printf("\n");
    return 0;
    
}
