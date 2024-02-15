////////////////////////////////////////////////////////////////////////////////////

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1000 //The limit of expression length

typedef struct _listnode{
   char item;
   struct _listnode *next;
} ListNode;

typedef struct _linkedlist{
   int size;
   ListNode *head;
 } LinkedList;

////////////////////////////////// stack    ///////////////////////////////////////////////////////

typedef struct stack{
	LinkedList ll;
} Stack;

//////////////////////// function prototypes /////////////////////////////////////////////////////

// You should not change the prototypes of these functions
void infixtoPostfix(char*, char*);
int precedence(char); // you may use this function

//////////////////////////////////////////////////////////////////////////////////////////////////

void push(Stack *s, char item);
int pop(Stack *s);
int peek(Stack *s);
int isEmptyStack(Stack *s);

///////////////////////////////////////////////////////////////////////////////////////////////////
void printList(LinkedList *ll);
ListNode * findNode(LinkedList *ll, int index);
int insertNode(LinkedList *ll, int index, char item);
int removeNode(LinkedList *ll, int index);
void removeAllItems(LinkedList *ll);

///////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    char infix[SIZE];
    char postfix[SIZE];

    printf("Enter an infix expression:\n");
    scanf("%[^\n]%*c",infix);

    infixtoPostfix(infix,postfix);
    printf("The postfix expression is \n");
    printf("%s\n",postfix);
    return 0;
}

/** Reverse nodes in given linked list.
 * Such that bottom list becomes the top node, and vice versa.
 * @param [in,out] list list to reverse in place.
 * @return The reversed list.
*/
LinkedList* reverse(LinkedList *list) {
    ListNode *prev = NULL;
    ListNode *n = list->head;

    while(n != NULL) {
        // reverse linking by pointing 'next' to previous node
        ListNode *next = n->next;
        n->next = prev;
        prev = n;
        n = next;
    }

    // last node is the new head node
    list->head = prev;
    return list;
}


/** Converts the given infix expression to reverse postfix.
 *  @return the converted reverse postfix expression as a Linked List. 
 *  Caller is responsible for freeing the returned list.
*/
LinkedList *toReversePostfix(const char *infix) {
    LinkedList *reversePostfix = calloc(1, sizeof(LinkedList));
    Stack stack;
    // zero postfix & stack into defined state
    memset(&stack, 0,  sizeof(Stack));

    for (size_t i = 0; i < strnlen(infix, SIZE); i++) {
        char c = infix[i];
        switch (c) {
            case '(':
                // push onto stack
                push(&stack, c);
                break;
            case ')':
                // pop stack into postfix until '('
                while (stack.ll.size > 0 && stack.ll.head->item != '(') {
                    insertNode(reversePostfix, 0, pop(&stack));
                }
                // discard '('
                pop(&stack);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                // pop higher or equal precedence operators into postfix
                while (stack.ll.size > 0 && precedence(stack.ll.head->item) >= precedence(c)) {
                    insertNode(reversePostfix, 0, pop(&stack));
                }
                // push operator onto the stack
                push(&stack, c);
                break;
            default:
                // assume its an operand: copy to postfix expression
                insertNode(reversePostfix, 0, c);  
        }
    }
    // pop any remaining elements in stack into postfix expression
    while (stack.ll.size > 0) {
        char op = pop(&stack);
        if(op != '(') {
            insertNode(reversePostfix, 0, op);
        }
    }
    return reversePostfix;
}

void infixtoPostfix(char *infix, char *postfix)
{
   LinkedList *postfixList = reverse(toReversePostfix(infix));
   ListNode *n = postfixList->head;
   for (int i = 0; i < postfixList->size; i++) {
      postfix[i] = n->item;
      n = n->next;
   }
   postfix[postfixList->size] = '\0';
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////

void push(Stack *s, char item){
   insertNode(&(s->ll), 0, item);
}

int pop(Stack *s){
   char item;
   if(!isEmptyStack(s)){
    item = ((s->ll).head)->item;
    removeNode(&(s->ll), 0);
    return item;
   }
    return INT_MIN;
}

int peek(Stack *s){
   return ((s->ll).head)->item;
}

int isEmptyStack(Stack *s){
   if ((s->ll).size == 0)
      return 1;
   return 0;
}

//////////////////////////////////////////////////////////////////////////////////

void printList(LinkedList *ll){

	ListNode *cur;
	if (ll == NULL)
		return;
	cur = ll->head;

	if (cur == NULL)
		printf("Empty");
	while (cur != NULL)
	{
		printf("%c ", cur->item);
		cur = cur->next;
	}
	printf("\n");
}

ListNode * findNode(LinkedList *ll, int index){

	ListNode *temp;

	if (ll == NULL || index < 0 || index >= ll->size)
		return NULL;

	temp = ll->head;

	if (temp == NULL || index < 0)
		return NULL;

	while (index > 0){
		temp = temp->next;
		if (temp == NULL)
			return NULL;
		index--;
	}

	return temp;
}

int insertNode(LinkedList *ll, int index, char value){

	ListNode *pre, *cur;

	if (ll == NULL || index < 0 || index > ll->size + 1)
		return -1;

	// If empty list or inserting first node, need to update head pointer
	if (ll->head == NULL || index == 0){
		cur = ll->head;
		ll->head = malloc(sizeof(ListNode));
		ll->head->item = value;
		ll->head->next = cur;
		ll->size++;
		return 0;
	}


	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->item = value;
		pre->next->next = cur;
		ll->size++;
		return 0;
	}

	return -1;
}


int removeNode(LinkedList *ll, int index){

	ListNode *pre, *cur;

	// Highest index we can remove is size-1
	if (ll == NULL || index < 0 || index >= ll->size)
		return -1;

	// If removing first node, need to update head pointer
	if (index == 0){
		cur = ll->head->next;
		free(ll->head);
		ll->head = cur;
		ll->size--;

		return 0;
	}

	// Find the nodes before and after the target position
	// Free the target node and reconnect the links
	if ((pre = findNode(ll, index - 1)) != NULL){

		if (pre->next == NULL)
			return -1;

		cur = pre->next;
		pre->next = cur->next;
		free(cur);
		ll->size--;
		return 0;
	}

	return -1;
}
