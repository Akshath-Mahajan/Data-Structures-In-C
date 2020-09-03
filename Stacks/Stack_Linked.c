#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create(struct node *start){
    int num;
    struct node *new_node;
    printf("Enter -1 to finish\n");
    printf("Enter your data in stack\n");
    scanf("%d", &num);
    while(num != -1){
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node -> data = num;
        new_node -> next = start;
        start = new_node;
        //Or define push and use push(start, num)
        scanf("%d", &num);
    }
    return start;
}
struct node *push(struct node *start, int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = start;
    start = new_node;
    return start;
}
struct node *pop(struct node *start){
    if(start == NULL){
        printf("ERROR! Stack already empty\n");
        return start;
    }
    printf("Popped: %d\n", start -> data);
    struct node *ptr = start;
    start = start -> next;
    free(ptr);
    return start;
}
int peek(struct node *start){
    return start -> data;
}
void print_stack(struct node *start){
    struct node *current = start;
    printf("[");
    if(start == NULL){
        printf("]\n");
    } else {
        while(current != NULL){
            printf("%d, ", current->data);
            current = current -> next;
        }
        printf("\b\b]\n");  //Remove last comma-space and end list
    }
}
void main(){
    printf("Please select one of the operations:\n");
    printf("0. Exit Program\n");
    printf("1. Create a stack\n");
    printf("2. Push to stack\n");
    printf("3. Pop from stack\n");
    printf("4. Peek in stack\n");
    int option, num, active = 1;
    while(active){
        printf("Enter an operation: ");
        scanf("%d", &option);
        switch(option){
            case 0:
                active = 0;
                break;
            case 1:
                start = NULL;
                start = create(start);
                break;
            case 2:
                printf("Enter number to push :");
                scanf("%d", &num);
                start = push(start, num);
                break;
            case 3:
                start = pop(start);
                break;
            case 4:
                printf("The element on top is: %d\n", peek(start));
                break;
            default:
                printf("Invalid Choice\n");
        }
        printf("Stack: ");
        print_stack(start);
        printf("\n");
        
    }
}