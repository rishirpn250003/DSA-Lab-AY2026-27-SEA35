#include<stdio.h>
void main(){
    int n;
    printf("Enter Decimal number: ");
    scanf("%d", &n);
    int s[10], top = -1, r;

    while(n != 0){
        r = n%2;
        n = n/2;
        top++;
        s[top] = r;
    }

    printf("Binary number for given decimal number is: ");
    for(int i = top; i >= 0; i--){
        printf("%d", s[i]);
    }
}