#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    return;
}
//make a function that instantiates the list given a number of nodes
node* make_list(int n){
    //make a new node
    node *head = NULL;
    node *current = NULL;
    node *previous = NULL;
    //loop through n times
    for (int i = 0; i < n; i++){
        //allocate memory for the node
        current = malloc(sizeof(node));
        //assign data to the node
        current->data = i;
        //link the node to the previous node
        if (i == 0){
            head = current;
        }
        else{
            previous->next = current;
        }
        //set the current node to be the previous node
        previous = current;
    }
    //set the last node to point to NULL
    current->next = NULL;
    //return the head of the list
    return head;
}

//make a function that sets the data in a given node of a list
void set_data(node *head, int index, int data){
    //loop through the list until we get to the index
    node *current = head;
    for (int i = 0; i < index; i++){
        current = current->next;
    }
    //set the data in the node
    current->data = data;
}

//function that reverses the linked list 
node* reverse(node* head){
    //make a new node
    node *current = head;
    node *previous = NULL;
    node *next = NULL;
    //loop through the list
    while (current != NULL){
        //set the next node
        next = current->next;
        //set the current node to point to the previous node
        current->next = previous;
        //set the previous node to be the current node
        previous = current;
        //set the current node to be the next node
        current = next;
    }
    //return the new head of the list
    return previous;

}

int main(){
    //set up a list
    node *head = make_list(10);
    //print the list
    print_list(head);
    //set the data in the 5th node to be 100
    set_data(head, 5, 100);
    //print the list again
    print_list(head);
    //reverse the list
    node *new_head = reverse(head);
    //print the list again
    print_list(new_head);
    return 0;
}


