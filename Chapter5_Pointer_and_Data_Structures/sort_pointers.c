#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void selection_sort(struct node **start);
void displaylist(struct node *q);
void append(struct node **q, int num);
void bubble_sort(struct node **start);

int main() {
    struct node *start = NULL;
    append(&start, 1);
    append(&start, 4);
    append(&start, 2);
    append(&start, 3);

    printf("Linked List Before Sorting:\n");
    displaylist(start);

    selection_sort(&start);
    printf("\nLinked List After Selection Sorting:\n");
    displaylist(start);

    // Recreate the list for bubble sort test
    // start = NULL;
    append(&start, 8);
    append(&start, 6);
    append(&start, 9);
    append(&start, 10);

    printf("\nLinked List Before Bubble Sorting:\n");
    displaylist(start);

    bubble_sort(&start);
    printf("\nLinked List After Bubble Sorting:\n");
    displaylist(start);

    return 0;
}

void append(struct node **q, int num) {
    struct node *temp = *q;
    if (*q == NULL) {
        *q = malloc(sizeof(struct node));
        temp = *q;
    } else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = malloc(sizeof(struct node));
        temp = temp->next;
    }
    temp->data = num;
    temp->next = NULL;
}

void displaylist(struct node *q) {
    struct node* temp = q;
    while (temp != NULL) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Selection sort using pointer manipulation
void selection_sort(struct node **start) {
    struct node **p, **q, **min, *temp;

    for (p = start; *p && (*p)->next; p = &(*p)->next) {
        min = p;
        for (q = &(*p)->next; *q; q = &(*q)->next) {
            if ((*q)->data < (*min)->data) {
                min = q;
            }
        }
        if (min != p) {
            // Swap the nodes by manipulating pointers
            temp = *p;
            *p = *min;
            *min = temp;

            temp = (*p)->next;
            (*p)->next = (*min)->next;
            (*min)->next = temp;
        }
    }
}

// Bubble sort using pointer manipulation
void bubble_sort(struct node **start) {
    int swapped;
    struct node **p, *temp;

    if (*start == NULL)
        return;

    do {
        swapped = 0;
        p = start;

        while ((*p)->next != NULL) {
            if ((*p)->data > (*p)->next->data) {
                // Swap the nodes by pointer manipulation
                temp = *p;
                *p = (*p)->next;
                temp->next = (*p)->next;
                (*p)->next = temp;

                swapped = 1;
            }
            p = &(*p)->next;
        }
    } while (swapped);
}
