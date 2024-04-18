#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initStack(Stack* stack) {
    stack->top = NULL;
}

void destroyStack(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        Node *tmp = current;
        current = current->next;
	    free(tmp);
    }
}

void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

Node* pop(Stack* stack) {
    Node* temp = stack->top;
    stack->top = temp->next;
    
    stack->top->next = NULL;

    return temp;
}

Node* searchByValue(Stack* stack, int value) {
    Node* current = stack->top;
    while (current != NULL) {
        if (current->data == value) {
            return current;
        }
    }
    return NULL;
}

Node* searchByIndex(Stack* stack, int index) {
    Node* current = stack->top;
    int count = 0;
    while (current != NULL) {
        if (count == index) {
            return current;
        }
        count++;
        current = current->next;
    }
    return NULL;
}

Node* getTop(Stack* stack) {
    return stack->top;
}

char* traverseStack(Stack* stack) {
    Node* current = stack->top;
    printf("Stack elements: ");
    size_t len = 0;

    while (current != NULL) {
        len++;
        current = current->next;
    }

    if (!len) return "";

    char *output = malloc((sizeof(int) + 1) * len); 

    current = stack->top;
  
    while (len > 0) {
        char *buffer = malloc(sizeof(int) + 1);

        (len == 1) ? sprintf(buffer,"%d", current->data) : sprintf(buffer,"%d ", current->data);
        
        strcat(output, buffer);

        free(buffer);
        len--;

        current = current->next;
    }

    return output;
}

bool isEmpty(Stack* stack) {
    // free(stack->top);
    return stack->top == NULL;
}
