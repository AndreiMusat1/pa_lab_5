#include "stive.h"

char top(Node *top){
	if (isEmpty(top)) {
		return '\0';
	} 

	return top->val;
} 

void push(Node** top, char v) {
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->val = v;
	newNode->next = *top;
	*top = newNode;
}

char pop(Node** top) {
	if (isEmpty(*top)) {
		return '\0';
	}

	Node *temp = (*top);
	char aux = temp->val;

	*top = (*top)->next;

	free(temp);

	return aux;
}

int isEmpty(Node* top) {
	return top == NULL;
}
	
void deleteStack(Node** top) { 
	Node *temp;
	while (!isEmpty(*top)) {
		temp = *top;
		*top = (*top)->next;

		free(temp);
	}
}

void correctlyClosedParentheses() {
	char userInput;
	Node* head = NULL;
	int closedParanthesesNo = 0;
	int i = 0, n = 0;
	int *lastLeftParantheses = NULL, lastRightParantheses = -1;

	scanf("%c", &userInput);
	while(userInput == '(' || userInput == ')') {
		i++;

		if(userInput == '(') {
			push(&head, userInput);

			n++;
			lastLeftParantheses = (int*) realloc(lastLeftParantheses, n*sizeof(int));
			lastLeftParantheses[n - 1] = i;
		} else if(userInput == ')' && !isEmpty(head)) {
			pop(&head);
			
			n--;
			lastLeftParantheses = (int*) realloc(lastLeftParantheses, n*sizeof(int));
		} else {
			push(&head, userInput);
			lastRightParantheses = i;
		}

		scanf("%c", &userInput);
	}

	if(isEmpty(head)) {
		printf("Sirul de paranteze introdus este inchis corect\n");
	} else {
		printf("Sirul de paranteze introdus nu este inchis corect, iar pozitiile pe care se afla paranteza neinchisa este:");
		
		if(n > 0) {
			printf("%d ", lastLeftParantheses[0]);
		}

		if(lastRightParantheses != -1) {
			printf("%d\n", lastRightParantheses);
		}

		deleteStack(&head);
	}

	free(lastLeftParantheses);
}