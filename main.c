//interactive Example use of Queue API

#include "include/Queue.h"
#include <stdio.h>
#include <windows.h>

static Queue Q1;

int main(void) {
    setbuf(stdout, 0);
    int value, op = 0;

    printf("Enter the Size of queue =>");
    scanf("%d", &Q1.Size);
    printf("Creating Queue.... Please wait!\n");
    /*Sleep(3 * 1000);*/
    CreateQueue(&Q1);
    if (&Q1.Q_Data == NULL) {
        printf("\n%s", _FATAL_OUT_OF_MEMORY);
        Sleep(3 * 1000);
        exit(EXIT_SUCCESS);
    }
    printf("\nDone!\n");
    /*Sleep(1.5 * 1000);*/
    beg:
    do {
        printf("\nEnter data =>");
        scanf("%d", &value);
        EnQueue(&Q1, value);
        if ((Q1.rear+1)%Q1.Size == Q1.front)
            break;
        printf("\nMore? Enter 1 to add more data =>");
        scanf("%d", &op);
    } while (op == 1);

    printf("\nThe data you have in Queue are =>");
    DisplayQueue(&Q1);

    while (1) {
        printf("\nWant to delete? 1 for yes =>");
        scanf("%d", &op);
        if (op != 1)
            break;
        printf("\n%d is deleted!\n", DeQueue(&Q1));
    }

    printf("\nThe data you have in Queue are =>\n");
    DisplayQueue(&Q1);

    printf("\nEnter more? 1 for yes =>");
    scanf("%d", &op);
    if (op == 1) goto beg;

    return 0;
}