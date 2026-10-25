#include <stdio.h>
#include <string.h> 
#define MAX 3 
struct Passenger {
    int id;
    char name[50];
};
/* Confirmed queue */ 
struct Passenger confirmed[MAX]; 
int frontC = 0, rearC = -1;
 /* Waiting queue */
  struct Passenger waiting[MAX]; 
  int frontW = 0, rearW = -1;
/* Add passenger to confirmed queue */ 
void bookTicket() 
{     
    struct Passenger p;     
    printf("\nEnter Passenger ID: ");     
    scanf("%d", &p.id);     
    printf("Enter Passenger Name: ");     
    scanf("%s", p.name);    
     if (rearC < MAX - 1) {         
        rearC++;       
        confirmed[rearC] = p;         
        printf("Ticket CONFIRMED for %s\n", p.name);
    }
    else if (rearW < MAX - 1) {         
        rearW++;         
        waiting[rearW] = p;         
        printf("No seats available.\n");         
        printf("%s added to WAITING LIST.\n", p.name);
    }     else {         
        printf("Waiting list is also full.\n");
    }
}
/* Cancel a confirmed ticket */ 
void cancelTicket() {     
    int id, i, found = 0;     
    printf("\nEnter Passenger ID to cancel: ");     
    scanf("%d", &id);     
    for (i = 0; i <= rearC; i++) {         
        if (confirmed[i].id == id) 
        {             
            found = 1;             
            printf("Ticket cancelled for %s\n", confirmed[i].name);            
             /* Shift remaining confirmed passengers */
            for (int j = i; j < rearC; j++) {           
                confirmed[j] = confirmed[j + 1];
            }             
            rearC--;
            /* Move first waiting passenger to confirmed */             
            if (frontW <= rearW) {                 
                confirmed[++rearC] = waiting[frontW];                 
                printf("%s moved from WAITING to CONFIRMED.\n",waiting[frontW].name);                
                 /* Shift waiting queue */                 
                 for (int j = frontW; j < rearW; j++) {                     
                    waiting[j] = waiting[j + 1];
                }
          rearW--;
            }             
            break;
        }    
    }
    if (!found) 
    {         
        printf("Passenger ID not found.\n");
    }
}
/* Display confirmed passengers */
void displayConfirmed() 
{     
    printf("\n--- CONFIRMED PASSENGERS ---\n");
    if (rearC < frontC) {         
        printf("No confirmed passengers.\n");
        return;
    }
    for (int i = frontC; i <= rearC; i++) 
    {         
        printf("ID: %d  Name: %s\n",confirmed[i].id, confirmed[i].name);
    }
}
/* Display waiting passengers */ 
void displayWaiting() {     
    printf("\n--- WAITING LIST ---\n");
    if (rearW < frontW) {         
        printf("Waiting list is empty.\n");         
        return;
    }
    for (int i = frontW; i <= rearW; i++) {         
        printf("ID: %d  Name: %s\n",waiting[i].id, waiting[i].name);
    }
}
int main() {    
    int choice;     
    do {
        printf("\n===== TRAIN TICKET BOOKING SYSTEM =====\n");         
        printf("1. Book Ticket\n");         
        printf("2. Cancel Ticket\n");         
        printf("3. Display Confirmed Passengers\n");         
        printf("4. Display Waiting List\n");         
        printf("5. Exit\n");         
        printf("Enter your choice: ");         
        scanf("%d", &choice);         
        switch (choice) {             
            case 1:                 
            bookTicket();                 
            break;             
            case 2:                 
            cancelTicket();                 
            break;             
            case 3:                 
            displayConfirmed();                 
            break;             
            case 4:                 
            displayWaiting();                
             break;             
             case 5:
                printf("Exiting program...\n");                 
                break;             
                default:
                printf("Invalid choice!\n");
        }
    } while (choice != 5);     
    return 0;
}