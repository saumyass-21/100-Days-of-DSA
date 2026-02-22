#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

int main() {
    int n, item;
    struct node *head = NULL, *tail = NULL, *newnode;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &item);
        
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->info = item;
        newnode->next = NULL;
        
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
    }
    
    struct node* current = head;
    while (current != NULL) {
        printf("%d ", current->info);
        current = current->next;
    }
    
    current = head;
    while (current != NULL) {
        struct node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}