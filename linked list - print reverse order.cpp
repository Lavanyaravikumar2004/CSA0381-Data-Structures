#include <stdio.h>
#include <stdlib.h>

// Define a Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to print a linked list in reverse order
void printReverse(struct Node* head) {
    if (head == NULL) {
        return;
    }
    printReverse(head->next);
    printf("%d ", head->data);
}

int main() {
    // Creating nodes manually for demonstration
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->next->data = 3;
    head->next->next->next = NULL;

    // Printing the linked list in reverse order
    printf("Printing in reverse order: ");
    printReverse(head);
    printf("\n");

    // Freeing allocated memory
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}

