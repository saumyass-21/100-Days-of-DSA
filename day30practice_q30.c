#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct term {
    int coefficient;
    int exponent;
    struct term* next;
};

struct term* create_term(int coeff, int exp) {
    struct term* new_term = (struct term*)malloc(sizeof(struct term));
    if (new_term == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    new_term->coefficient = coeff;
    new_term->exponent = exp;
    new_term->next = NULL;
    return new_term;
}

struct term* insert_term(struct term* head, int coeff, int exp) {
    struct term* new_term = create_term(coeff, exp);
    
    if (head == NULL || exp > head->exponent) {
        new_term->next = head;
        return new_term;
    }
    
    struct term* current = head;
    while (current->next != NULL && current->next->exponent > exp) {
        current = current->next;
    }
    
    new_term->next = current->next;
    current->next = new_term;
    
    return head;
}

struct term* create_polynomial() {
    struct term* head = NULL;
    int n, coeff, exp;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        head = insert_term(head, coeff, exp);
    }
    
    return head;
}

void print_polynomial(struct term* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    
    struct term* current = head;
    int is_first_term = 1;
    
    while (current != NULL) {
        if (current->coefficient < 0) {
            printf(" - ");
        } else if (!is_first_term) {
            printf(" + ");
        }
        
        int abs_coeff = abs(current->coefficient);
        
        if (current->exponent == 0) {
            printf("%d", abs_coeff);
        } else if (current->exponent == 1) {
            if (abs_coeff == 1) {
                printf("x");
            } else {
                printf("%dx", abs_coeff);
            }
        } else {
            if (abs_coeff == 1) {
                printf("x^%d", current->exponent);
            } else {
                printf("%dx^%d", abs_coeff, current->exponent);
            }
        }
        
        is_first_term = 0;
        current = current->next;
    }
    printf("\n");
}

void free_polynomial(struct term* head) {
    struct term* current = head;
    while (current != NULL) {
        struct term* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct term* poly = create_polynomial();
    print_polynomial(poly);
    free_polynomial(poly);
    
    return 0;
}