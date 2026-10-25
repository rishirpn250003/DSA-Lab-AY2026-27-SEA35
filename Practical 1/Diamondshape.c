#include<stdio.h>
void main(){
    int n = 4;
    for(int i = 1; i <= n; i++){
        for(int j = n-1; j >= i; j--){
            printf(" ");
        }
        for(int j = i; j > 0; j--){
            printf("%d ", i);
        }
        printf("\n");
    }
    for(int i = n-1; i > 0; i--){
        for(int j = i; j < n; j++){
            printf(" ");
        }
        for(int j = 0; j < i; j++){
            printf("%d ", i);
        }
        printf("\n");
    }
}