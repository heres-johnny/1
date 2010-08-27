#include <stdio.h>
#include <stdlib.h>

struct listNode {                
    char data; 
    struct listNode *nextPtr;  
}; 

typedef struct listNode ListNode; 
typedef ListNode *ListNodePtr; 

// [h]elp           DONE        [e]mpty                     [i]nsert        DONE   
// [d]elete         DONE        [r]eplace                   [c]ount    
// [p]rint          DONE        re[v]erse                   [x] placehoder  DONE
// [s]earch                     to[l]ower                   [w]here    
// [z] error                    [q]uit          DONE

void insert(ListNodePtr *sPtr, char value);
char delete(ListNodePtr *sPtr, char value);
int isEmpty(ListNodePtr sPtr);
void printList(ListNodePtr currentPtr);
void empty(ListNodePtr currentPtr);
void help(void);

int main(void)
{ 
    ListNodePtr startPtr = NULL; 
    int choice; 
    char item;  

    printf("? ");
    while ((choice = getchar()) != 'Q') {
        if (choice == 'I') {                                // Insert
            printf("Enter a character: ");
            scanf("\n%c", &item);
            insert(&startPtr, item); 
            printList(startPtr);

        } else if (choice == 'D') {                         // Delete
            if (!isEmpty(startPtr)) { 
                printf("Enter character to be deleted: ");
                scanf("\n%c", &item);

                if (delete(&startPtr, item)) { 
                    printf("%c deleted.\n", item);
                    printList(startPtr);
                } else {
                    printf("%c not found.\n\n", item);
                } 
            } else {
                printf("List is empty.\n\n");
            }

        } else if (choice == 'E') {                         // Empty
            // NOT DONE YET
            // DON'T FORGET TO FREE MEMORY

        } else if (choice == 'H') {                         // Help
            help();

        } else if (choice == 'P') {                         // Print
                printList(startPtr);

        } else if (choice == 'X') {                         // Dummy command

        } else {                                            // Invalid command
                printf("<E0>Invalid command.\n");
        } 

        printf("? ");
        scanf("%d", &choice);
    } 

    printf("BYE\n");
    
    return 0; 
} 

void help(void)
{ 
    printf("H-help E-empty I-insert D-delete R-replace C-count P-print\n"
           "V-reverse X-dummy S-search L-lower W-where Z-error Q-quit\n");
} 

void insert(ListNodePtr *sPtr, char value)
{ 
    ListNodePtr newPtr;        
    ListNodePtr previousPtr; 
    ListNodePtr currentPtr;  

    newPtr = malloc(sizeof(ListNode));  

    if (newPtr != NULL) { 
        newPtr->data = value; 
        newPtr->nextPtr = NULL; 

        previousPtr = NULL;
        currentPtr = *sPtr;

        while (currentPtr != NULL && value > currentPtr->data) { 
            previousPtr = currentPtr;             
            currentPtr = currentPtr->nextPtr;  
        } 
        
        if (previousPtr == NULL) { 
            newPtr->nextPtr = *sPtr;
            *sPtr = newPtr;
        } else { 
            previousPtr->nextPtr = newPtr;
            newPtr->nextPtr = currentPtr;
        } 
    
    } else {
        printf("%c not inserted. No memory available.\n", value);
    } 
} 

char delete(ListNodePtr *sPtr, char value)
{ 
    ListNodePtr previousPtr; 
    ListNodePtr currentPtr;  
    ListNodePtr tempPtr;      

    if (value == (*sPtr)->data) { 
        tempPtr = *sPtr; 
        *sPtr = (*sPtr)->nextPtr; 
        free(tempPtr); 
        return value;
    } else { 
        previousPtr = *sPtr;
        currentPtr = (*sPtr)->nextPtr;

        while (currentPtr != NULL && currentPtr->data != value) { 
            previousPtr = currentPtr;            
            currentPtr = currentPtr->nextPtr;    
        } 

        if (currentPtr != NULL) { 
            tempPtr = currentPtr;
            previousPtr->nextPtr = currentPtr->nextPtr;
            free(tempPtr);
            return value;
        } 
    } 

    return '\0';
} 

int isEmpty(ListNodePtr sPtr)
{ 
    return sPtr == NULL;
} 

void printList(ListNodePtr currentPtr)
{ 
    if (currentPtr == NULL) {
        printf("Empty.\n\n");
    } else { 
        printf("The list is:\n");

        while (currentPtr != NULL) { 
            printf("%c --> ", currentPtr->data);
            currentPtr = currentPtr->nextPtr;    
        } 

        printf("NULL\n\n");
    } 

} 

void empty(ListNodePtr currentPtr)
{
    while (currentPtr != NULL) {

}
