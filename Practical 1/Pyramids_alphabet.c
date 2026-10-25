#include<stdio.h>
void main(){
    int n = 4;
    for(int i = 0; i < n; i++){
        char ch = 'A';
        for(int j = n-1; j > i; j--){
            printf(" ");
        }
        for(int j = 0; j <= i; j++){
            printf("%c", ch+j);
        }
        for(int j = i; j > 0; j--){
            printf("%c", ch+j-1);
        }
        printf("\n");
    }
}