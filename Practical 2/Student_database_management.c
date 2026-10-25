#include<stdio.h>

typedef struct stud{
    int rn;
    char name[20];
    char program[20];
    char sub1[10], sub2[10];
    int sub1_mk, sub2_mk, total;
    float avg;
}stud;

void main(){
    stud s[20];
    int n, op, key;
    void create(stud[], int);
    void display(stud[], int);
    void search(stud[], int, int);
    printf("STUDENTS DATABASE MANAGEMENT\n");

    do{
        printf("\n1. Create\n2. Display\n3. Search\n");
        printf("Enter option no. : ");
        scanf("%d", &op);
        switch(op){
            case 1:
            printf("\nEnter no. of students: ");
            scanf("%d", &n);
            create(s, n);
            break;
            case 2:
            display(s, n);
            break;
            case 3:
            search(s, n, key);
            break;
        }
    }while(op < 3);
}

void create(stud s[], int n){
    printf("\n---//ENTER STUDENTS DATA//---\n");
    for(int i = 1; i <= n; i++){
        printf("\n~~~Student %d Data~~~\n", i);
        printf("Enter student's name: ");
        scanf("%s", s[i].name);
        printf("Enter student's roll no. : ");
        scanf("%d", &s[i].rn);
        printf("Enter student's program: ");
        scanf("%s", s[i].program);
        printf("Enter subject1: ");
        scanf("%s", s[i].sub1);
        printf("Enter subject2: ");
        scanf("%s", s[i].sub2);
        printf("Enter subject 1's marks: ");
        scanf("%d", &s[i].sub1_mk);
        printf("Enter subject 2's marks: ");
        scanf("%d", &s[i].sub2_mk);

        s[i].total = s[i].sub1_mk + s[i].sub2_mk;
        s[i].avg = s[i].total/2;
    }
}

void display(stud s[], int n){
    printf("\n---//DISPLAYING STUDENTS DATA//---");
    for(int i = 1; i <= n; i++){
        printf("\n\n~~~Student %d Data~~~", i);
        printf("\nName: %s", s[i].name);
        printf("\nRoll no. : %d", s[i].rn);
        printf("\nProgram: %s", s[i].program);
        printf("\nSubject 1: %s", s[i].sub1);
        printf("\nSubject 2: %s", s[i].sub2);
        printf("\nSubject 1's marks: %d", s[i].sub1_mk);
        printf("\nSubject 2's marks: %d", s[i].sub2_mk);
        printf("\nTotal: %d", s[i].total);
        printf("\nAverage: %.2lf", s[i].avg);
    }
    printf("\n\n---//END//---\n");
}

void search(stud s[], int n, int key){
    int flag = 0;
    printf("\nEnter student's roll no. to search: ");
    scanf("%d", &key);
    for(int i = 1; i <= n; i++){
        if(s[i].rn == key){
            printf("STUDENT FOUND\n");
            flag++;
            break;
        }
    }
    if(flag == 0){
        printf("STUDENT NOT FOUND\n");
    }
}