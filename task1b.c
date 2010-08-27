// Author: Johnny Wong (jwon145)
// Class : tue13-clavier, JohnGarland
// Date created: Wed Aug  4 17:36:19 EST 2010
// Description: list manipulation

#include <stdio.h>
#include <stdlib.h>

struct listNode {
    char data;
    struct listNode *nextPtr;
};

typedef struct listNode ListNode;
typedef ListNode *ListNodePtr;

// function prototypes here

// [h]elp, [e]mpty, [i]nsert, [d]elete, [r]eplace, [c]ount, [p]rint
// re[v]erse, [x] placehoder, [s]earch, to[l]ower, [w]here, [z] error, [q]uit

void menu(void);
void insert(ListNodePtr *sPtr, char value);
char delete(ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currPtr);

int main(void)
{
    ListNodePtr startPtr = NULL;
    int cmd;
    int data;

    menu();
    while ((cmd = getchar()) != 'Q') {
        switch (cmd) {
            case 'I':                                       // [I]nsert
                printf("Enter a character:\n");
                data = getchar();
                insert(&startPtr, data) ;
                printList(startPtr);
                break;
            case 'D':                                       // [D]elete
                if (!isEmpty(startPtr)) {
                    printf("Enter the character to be deleted: \n");
                    data = getchar();
                    printList(startPtr);
                
                    if (delete(&startPtr, data)) {
                        printf("%c deleted.\n", data);
                        printList(startPtr);
                    } else {
                        printf("%c not found.\n\n",data);
                    }
                } else {
                    printf("List is empty.\n\n");
                }
                break;
            default:
                printf("Invalid choice.\n\n");
                menu();
                break;
        }
    }
    printf("End of run.\n");

    return 0;
}

void menu(void)
{
   printf( "Enter your choice:\n"
      "   1 to insert an element into the list.\n"
      "   2 to delete an element from the list.\n"
      "   3 to end.\n" 
      "? ");
}

void insert(ListNodePtr *sPtr, char value)
{
    ListNodePtr newPtr;
    ListNodePtr prevPtr;
    ListNodePtr currPtr;

    newPtr = malloc(sizeof(ListNode));

    if (newPtr != NULL) {
        newPtr->data = value;
        newPtr->nextPtr = NULL;
        prevPtr = NULL;
        currPtr = *sPtr;

        while (currPtr != NULL && value > currPtr->data) {
            prevPtr = currPtr;
            currPtr = currPtr->nextPtr;
        }

        if (prevPtr == NULL) {
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        } else {
            prevPtr->nextPtr = newPtr;
            newPtr->nextPtr = currPtr;
        }
    } else {
        printf("%c not inserted. No memory available.\n", value);
    }
}

char delete(ListNodePtr *sPtr, char value)
{
    ListNodePtr prevPtr;
    ListNodePtr currPtr;
    ListNodePtr tempPtr;

    if (value == (*sPtr)->data) {
        tempPtr = *sPtr;
        *sPtr = (*sPtr)->nextPtr;
        free(tempPtr);

        return value;
    } else {
        prevPtr = *sPtr;
        currPtr = (*sPtr)->nextPtr;

        while (currPtr != NULL && currPtr->data != value) {
            prevPtr = currPtr;
            currPtr = currPtr->nextPtr;
        }

        if (currPtr != NULL) {
            tempPtr = currPtr;
            prevPtr->nextPtr = currPtr->nextPtr;
            free(tempPtr);

            return value;
        }
    }

    return '\0';
}

int isEmpty(ListNodePtr sPtr)
{
    return sPtr == NULL; // returns 1 if empty, 0 if not empty
}

void printList(ListNodePtr currPtr)
{
    if (currPtr == NULL) {
        printf("The list is empty.\n\n");
    } else {
        printf("The list is:\n");

        while (currPtr != NULL) {
            printf("%c --> ", currPtr->data);
            currPtr = currPtr->nextPtr;
        }

        printf("NULL\n\n");
    }
}
