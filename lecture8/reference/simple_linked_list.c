#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    struct node *head = NULL;
    struct node first;
    first.data = 10;
    first.next = NULL;
    
    struct node second;
    second.data = 20;
    second.next = NULL;

    first.next = &second;
    head = &first;

    printf("| %d | %p | -> | %d | %p |\n", first.data, first.next, second.data, second.next);
    printf("| %d | %p | -> | %d | %p |\n", head->data, head->next, second.data, second.next);

    return 0;
}

