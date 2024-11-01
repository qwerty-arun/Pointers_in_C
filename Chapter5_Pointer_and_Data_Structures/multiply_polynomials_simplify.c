#include <stdio.h>
#include <stdlib.h>

struct polynode {
    float coeff;
    int exp;
    struct polynode *link;
};

void poly_append(struct polynode **, float, int);
void poly_multiply(struct polynode *, struct polynode *, struct polynode **);
void padd(float, int, struct polynode **);
void display_poly(struct polynode *);
void simplify_poly(struct polynode **);

int main() {
    struct polynode *first, *second, *mult;
    first = second = mult = NULL;
    int i = 1;

    poly_append(&first, 3, 5);
    poly_append(&first, 2, 4);
    poly_append(&first, 1, 2);

    display_poly(first);

    poly_append(&second, 1, 6);
    poly_append(&second, 2, 5);
    poly_append(&second, 3, 4);

    printf("\n\n");
    display_poly(second);

    printf("\n");
    while (i++ < 60)
        printf("-");
    printf("\n\n");

    poly_multiply(first, second, &mult);
    simplify_poly(&mult);
    display_poly(mult);
    return 0;
}

void poly_append(struct polynode **q, float x, int y) {
    struct polynode *temp;
    temp = *q;

    if (*q == NULL) {
        *q = malloc(sizeof(struct polynode));
        temp = *q;
    } else {
        while (temp->link != NULL)
            temp = temp->link;
        temp->link = malloc(sizeof(struct polynode));
        temp = temp->link;
    }
    temp->coeff = x;
    temp->exp = y;
    temp->link = NULL;
}

void display_poly(struct polynode *q) {
    while (q != NULL) {
        printf("%.1fx^%d", q->coeff, q->exp);
        q = q->link;
        if (q != NULL)
            printf(" + ");
    }
    printf("\n");
}

void poly_multiply(struct polynode *x, struct polynode *y, struct polynode **m) {
    struct polynode *y1;
    float coeff1;
    int exp1;
    y1 = y;

    if (x == NULL || y == NULL)
        return;

    while (x != NULL) {
        y = y1;  // Reset y to the start of the second polynomial
        while (y != NULL) {
            coeff1 = x->coeff * y->coeff;
            exp1 = x->exp + y->exp;
            padd(coeff1, exp1, m);
            y = y->link;
        }
        x = x->link;
    }
}

void padd(float c, int e, struct polynode **s) {
    struct polynode *r, *temp = *s;
    if (*s == NULL || e > (*s)->exp) {
        r = malloc(sizeof(struct polynode));
        r->coeff = c;
        r->exp = e;
        r->link = *s;
        *s = r;
    } else {
        while (temp->link != NULL && temp->link->exp > e)
            temp = temp->link;

        if (temp->exp == e) {
            temp->coeff += c;
        } else {
            r = malloc(sizeof(struct polynode));
            r->coeff = c;
            r->exp = e;
            r->link = temp->link;
            temp->link = r;
        }
    }
}

// Function to simplify the polynomial by combining like terms
void simplify_poly(struct polynode **poly) {
    struct polynode *p1, *p2, *prev;

    p1 = *poly;
    while (p1 != NULL && p1->link != NULL) {
        prev = p1;
        p2 = p1->link;
        while (p2 != NULL) {
            if (p1->exp == p2->exp) {
                p1->coeff += p2->coeff;  // Add coefficients
                prev->link = p2->link;   // Remove duplicate node
                free(p2);                // Free memory of duplicate node
                p2 = prev->link;         // Move to the next node
            } else {
                prev = p2;
                p2 = p2->link;
            }
        }
        p1 = p1->link;
    }
}

