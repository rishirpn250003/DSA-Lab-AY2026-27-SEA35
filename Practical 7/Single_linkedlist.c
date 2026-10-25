
#include <stdio.h>
#include <stdlib.h>

typedef struct SLL
{
    char data[10];
    struct SLL *next;
}
SLL;

SLL *head, *p, *q, *nw;
int ans, ch, pos, i;

int main()
{
    head = NULL;

    //create
    do
    {
        nw = (SLL*) malloc(sizeof(SLL));

        printf("\n Enter college name: ");
        scanf("%s", nw->data);
        nw->next = NULL;

        if (head == NULL)
        {
            p = head = nw;
        }
        else
        {
            p->next = nw;
            p = p->next;
        }

        printf("\n Enter 1 to continue: ");
        scanf("%d", &ans);

    } while(ans == 1);

    //menu
    do
    {
        printf("\n\n1. Display");
        printf("\n2. Insert");
        printf("\n3. Delete");
        printf("\n4. Exit");

        printf("\n\n Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            //display
            case 1:
                printf("\n College List: ");

                for(p = head; p != NULL; p = p->next)
                {
                    printf("%s->", p->data);
                }

                printf("NULL");
                break;

            //insert
            case 2:
                nw = (SLL*) malloc(sizeof(SLL));

                printf("\n Enter college name: ");
                scanf("%s", nw->data);

                printf("\n Enter position: ");
                scanf("%d", &pos);

                if(pos == 1)
                {
                    nw->next = head;
                    head = nw;
                }
                else
                {
                    p = head;

                    for(i = 1; i < pos - 1 && p != NULL; i++)
                    {
                        p = p->next;
                    }

                    if(p == NULL)
                    {
                        printf("\n Invalid position");
                        free(nw);
                    }
                    else
                    {
                        nw->next = p->next;
                        p->next = nw;
                    }
                }
                break;

            //delete
            case 3:
                printf("\n Enter position: ");
                scanf("%d", &pos);

                if(head == NULL)
                {
                    printf("\n List is empty");
                }
                else if(pos == 1)
                {
                    p = head;
                    head = head->next;
                    free(p);
                }
                else
                {
                    p = head;

                    for(i = 1; i < pos - 1 && p != NULL; i++)
                    {
                        p = p->next;
                    }

                    if(p == NULL || p->next == NULL)
                    {
                        printf("\n Invalid position");
                    }
                    else
                    {
                        q = p->next;
                        p->next = q->next;
                        free(q);
                    }
                }
                break;

            case 4:
                printf("\n Exit");
                break;

            default:
                printf("\n Invalid choice");
        }

    } while(ch != 4);

    return 0;
}