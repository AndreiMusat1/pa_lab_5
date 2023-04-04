#include "stive.h"

int main(void) {
     Node* head = NULL;
     Node* temp = NULL;
     char stackTopValue;

     push(&head, 'a');
     push(&head, 'n');
     push(&head, 'u');
     push(&head, 'b');
     push(&head, 'x');

     stackTopValue = pop(&head);

     printf("Valoarea din inceputul stivei:%c\n", stackTopValue);

     temp = head;
     while(!isEmpty(temp)) {
         printf("%c", temp->val);
         temp = temp->next;
     }

     deleteStack(&head);
     printf(" %d", isEmpty(head));

    correctlyClosedParentheses();
 
    return 0;
}