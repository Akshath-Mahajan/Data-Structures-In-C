#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX 10 // Altering this value changes size of stack created
int stack[MAX], top=-1;
/* 
    Since there is only one global "top" variable, which is being accessed in
    every function [push, pop, peek], there can only exist one stack at a time
    [since a second stack will require it's own top variable and must not change
    the top variable for the first stack]
    Therefore, defining the functions with stack as a parameter is unnecessary
*/
void push(int element){
    if(top+1 >= MAX){
        printf("Error! Stack Overflow\n");
    } else {
    stack[top+1] = element;
    top++;
    }
}
int pop(){
    if(top == -1){
        printf("Error! Stack Underflow\n");
        return -1;
    } else {
        top--;
        return stack[top+1];
    }
}
int peek(){
    if(top == -1){
        printf("Stack is empty!\n");
    } else {
        return stack[top];
    }
}
void print_stack(){
    printf("[");
    if(top == -1){
        printf("]");
    } else {
        for(int i = top; i>=0 ;i--)
        {printf("%d, ",stack[i]);}
        printf("\b\b]");
    }
}
void main(){
    printf("There exists an empty stack. Please choose one of the options to perform:\n");
    printf("0. Exit Program\n");
    printf("1. Push to stack\n");
    printf("2. Pop from stack\n");
    printf("3. Peek in stack\n");
    int option, num, active = 1;
    while(active){
        printf("Enter an operation: ");
        scanf("%d", &option);
        switch(option){
            case 0:
                active = 0;
                break;
            case 1:
                printf("Enter element to be pushed to stack: ");
                scanf("%d", &num);
                push(num);
                break;
            case 2:
                printf("Popped: %d\n", pop());
                break;
            case 3:
                printf("The element on top is: %d\n", peek());
                break;
            default:
                printf("Invalid Choice\n");
        }
        printf("Stack: ");
        print_stack();
        printf("\n");
    }
}