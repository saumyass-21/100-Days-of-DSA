#include <stdio.h>
#include <stdlib.h>

// Node structure for singly linked list
struct node {
    int data;
    struct node* next;
};

// Function to create a new node
struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to insert at the end
struct node* insertend(struct node* head, int data) {
    struct node* newnode = createnode(data);
    
    if (head == NULL) {
        return newnode;
    }
    
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

// Function to get the length of a linked list
int getlength(struct node* head) {
    int length = 0;
    struct node* current = head;
    
    while (current != NULL) {
        length++;
        current = current->next;
    }
    
    return length;
}

// Function to find the intersection point of two linked lists
int findinter(struct node* head1, struct node* head2) {
    int len1 = getlength(head1);
    int len2 = getlength(head2);
    
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    
    // Calculate the difference in lengths
    int diff = abs(len1 - len2);
    
    // Advance the pointer of the longer list by 'diff' steps
    if (len1 > len2) {
        for (int i = 0; i < diff; i++) {
            ptr1 = ptr1->next;
        }
    } else {
        for (int i = 0; i < diff; i++) {
            ptr2 = ptr2->next;
        }
    }
    
    // Traverse both lists simultaneously until intersection is found
    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1 == ptr2) {
            return ptr1->data;  // Intersection found
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
    return -1;  // No intersection (using -1 as sentinel, but problem might want specific output)
}

// Function to create an intersection between two lists for testing
// Note: In a real problem, the lists would already have an intersection
struct node* createinter(struct node* head1, struct node* head2, int intersectval) {
    // This is just for testing - in actual problem, lists are given with intersection
    struct node* temp1 = head1;
    struct node* temp2 = head2;
    
    // Find the node with intersectVal in first list
    while (temp1 != NULL && temp1->data != intersectval) {
        temp1 = temp1->next;
    }
    
    // Go to the end of second list
    while (temp2 != NULL && temp2->next != NULL) {
        temp2 = temp2->next;
    }
    
    // Create intersection
    if (temp1 != NULL && temp2 != NULL) {
        temp2->next = temp1;
    }
    
    return head2;
}

// Function to free the entire list
void freelist(struct node* head) {
    struct node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, m, value;
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    
    // Read first list
    printf("Enter number of elements in first list: ");
    scanf("%d", &n);
    
    printf("Enter elements of first list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insertend(head1, value);
    }
    
    // Read second list
    printf("Enter number of elements in second list: ");
    scanf("%d", &m);
    
    printf("Enter elements of second list: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insertend(head2, value);
    }
 
    printf("Enter intersection value: ");
    scanf("%d", &value);
    
    if (value != -1) {
        head2 = createinter(head1, head2, value);
    }
    
    // Find intersection
    int result = findinter(head1, head2);
    
    // Print result
    if (result != -1) {
        printf("%d\n", result);
    } else {
        printf("No Intersection\n");
    }
    
    return 0;
}