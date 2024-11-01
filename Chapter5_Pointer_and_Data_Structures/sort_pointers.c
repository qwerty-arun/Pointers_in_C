#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void append(struct Node** head, int data);
void display(struct Node* head);
void selectionSort(struct Node* head);
void bubbleSort(struct Node* head);

int main() {
    struct Node* head = NULL;
    int choice, data;

    // Sample input for the linked list
    append(&head, 5);
    append(&head, 2);
    append(&head, 9);
    append(&head, 1);
    append(&head, 7);

    printf("Original list:\n");
    display(head);

    // Prompt user to choose sorting method
    printf("\nChoose sorting technique:\n1. Selection Sort\n2. Bubble Sort\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        selectionSort(head);
        printf("\nList after Selection Sort:\n");
    } else if (choice == 2) {
        bubbleSort(head);
        printf("\nList after Bubble Sort:\n");
    } else {
        printf("Invalid choice!\n");
        return 1;
    }

    display(head);

    return 0;
}

// Function to append a new node to the end of the list
void append(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head;

    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Selection Sort on a linked list
void selectionSort(struct Node* head) {
    struct Node *temp1 = head, *temp2, *minNode;

    while (temp1 != NULL && temp1->next != NULL) {
        minNode = temp1;
        temp2 = temp1->next;

        // Find the minimum node in the remaining list
        while (temp2 != NULL) {
            if (temp2->data < minNode->data) {
                minNode = temp2;
            }
            temp2 = temp2->next;
        }

        // Swap the data if a smaller element is found
        if (minNode != temp1) {
            int temp = temp1->data;
            temp1->data = minNode->data;
            minNode->data = temp;
        }

        temp1 = temp1->next;
    }
}

// Bubble Sort on a linked list
void bubbleSort(struct Node* head) {
    int swapped;
    struct Node *ptr1;
    struct Node *lptr = NULL;

    // Check for empty list
    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap the data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}
