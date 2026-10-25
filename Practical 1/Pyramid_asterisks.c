#include<stdio.h>
void main(){
    int n = 4;
    for(int i = 1; i <= n; i++){
        for(int j = n-1; j >= i; j--){
            printf(" ");
        }
        for(int j = i; j > 0; j--){
            printf("* ");
        }
        printf("\n");
    }
}