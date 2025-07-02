#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert_at_begin(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    printf("Inserted %d at the beginning.\n", new_data);
}

void insert_at_end(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        printf("Inserted %d at the end.\n", new_data);
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    printf("Inserted %d at the end.\n", new_data);
}


void delete_at_begin(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }
    struct Node* temp = *head_ref;
    *head_ref = (*head_ref)->next;
    printf("Deleted %d from the beginning.\n", temp->data);
    free(temp);
}

void delete_at_end(struct Node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }
    struct Node* temp = *head_ref;
    if ((*head_ref)->next == NULL) {
        printf("Deleted %d from the end.\n", temp->data);
        free(*head_ref);
        *head_ref = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    struct Node* last_node = temp->next;
    temp->next = NULL;
    printf("Deleted %d from the end.\n", last_node->data);
    free(last_node);
}


void traverse(struct Node* node) {
    if (node == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n--- Linked List Operations ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Traverse\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insert_at_begin(&head, value);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insert_at_end(&head, value);
                break;
            case 3:
                delete_at_begin(&head);
                break;
            case 4:
                delete_at_end(&head);
                break;
            case 5:
                traverse(head);
                break;
            case 6:
                printf("Exits\n");
                exit(0);
            default:
                printf("Invalid choice! \n");
        }
    }

    return 0;
}

