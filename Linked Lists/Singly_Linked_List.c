#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *create(struct node *start){
    int num; 
    struct node *current, *new_node;
    printf("Enter -1 to finish\n");
    printf("Enter your data in list\n");
    scanf("%d", &num);
    while(num != -1){
        new_node = (struct node*)malloc(sizeof(struct node));
        new_node -> data = num;
        new_node -> next = NULL;
        if(start == NULL){
            start = new_node;
            current = start;
        } else {
            current -> next = new_node;
            current = current->next;
        }
        scanf("%d", &num);
    }
    /*
        Or define insertAtEnd and use insertAtEnd(start, num) in while loop
        Using insertAtEnd will take time, since
        We will have to traverse till the last node FROM START everytime.
    */
    return start;
}
struct node *insertAtStart(struct node *start, int data){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = start;
    start = new_node;
    return start;
}
struct node *insertAtIndex(struct node *start, int data, int index){
    if(index == 0){return insertAtStart(start, data);}
    struct node *current = start;
    for(int i = 0; i < index-1; i++){
        current = current -> next;
        if(current == NULL){
            printf("Error! Length exceeded!\n");
            return start;
        }
    }
    /*
        To Add node at index:
        Add new node between node_before_index and node_at_index
    */ 
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = current -> next;
    current -> next = new_node;
    return start;
}
struct node *insertAtEnd(struct node *start, int data){
    if(start == NULL){return insertAtStart(start, data);}
    struct node *current = start;
    while(current -> next != NULL){
        current = current->next;
    }
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = data;
    new_node -> next = NULL;
    current -> next = new_node;
    return start;
}
struct node *deleteAtStart(struct node *start){
    if(start == NULL){return start;}
    struct node *ptr = start;
    start = start -> next;
    free(ptr);
    return start;
}
struct node *deleteAtIndex(struct node *start, int index){
    if(start == NULL){return start;}
    if(index==0){return deleteAtStart(start);}
    struct node *current = start;
    for(int i = 0; i < index-1; i++){
        current = current -> next;
        if(current == NULL){
            printf("Error! Length exceeded!\n");
            return start;
        }
    }   //Arrive at node before index
    struct node *ptr = current -> next;
    current -> next = ptr -> next;
    free(ptr);
    return start;
}
struct node *deleteAtEnd(struct node *start){
    if(start == NULL){return start;}
    if(start -> next == NULL){return deleteAtStart(start);}

    struct node *current = start;
    while(current -> next -> next != NULL){
        current = current -> next;
    } //Arrive at second last node
    struct node *ptr = current->next; //ptr is last node now
    current -> next = NULL;
    free(ptr);
    return start;

}
void print_list(struct node *start){
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
    printf("1. Create a linked list\n");
    printf("2. Insert new element at beginning\n");
    printf("3. Insert new element at some index\n");
    printf("4. Insert new element at end\n");
    printf("5. Delete first element\n");
    printf("6. Delete element at some index\n");
    printf("7. Delete last element\n");
    int option, num, index, active = 1;
    while(active){
        printf("Enter an operation: ");
        scanf("%d", &option);
        switch(option){
            case 0:
                active = 0;
                break;
            case 1:
                start = NULL; //in case we use start operation twice
                start = create(start); 
                break;
            case 2:
                printf("Enter number to be inserted\n");
                scanf("%d", &num);
                start = insertAtStart(start, num);
                break;
            case 3:
                printf("Enter number to be inserted\n");
                scanf("%d", &num);
                printf("Enter index\n");
                scanf("%d", &index);
                start = insertAtIndex(start, num, index);
                break;
            case 4:
                printf("Enter number to be inserted\n");
                scanf("%d", &num);
                start = insertAtEnd(start, num);
                break;
            case 5:
                start = deleteAtStart(start);
                break;
            case 6:
                printf("Enter index to be deleted\n");
                scanf("%d", &index);
                start = deleteAtIndex(start, index);
                break;
            case 7:
                start = deleteAtEnd(start);
                break;
            default:
                printf("Invalid Choice");
        }
        printf("Output: ");
        print_list(start);
        printf("\n");
        
    }
}