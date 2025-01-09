#include<stdio.h>
#include<stdlib.h>

/* Linked list node */
struct node {
    int data;
    struct node *next;
};

void enigma(struct node **head_ref, int data) {
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = *head_ref;
    *head_ref = temp;
}

void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf(" %d", current->data);
        current = current->next;
    }
    printf("\n");
}
 
int main() {
    struct node *head = NULL;
    enigma(&head, 1);
    enigma(&head, 2);
    enigma(&head, 3);
    print_list(head);
    return 0;
}

