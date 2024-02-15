#include <stdio.h>
#include <stdlib.h>

typedef struct node {
        int data;
        struct node *next;
        struct node *prev;
} node;
node *start = NULL, *new_node = NULL, *temp = NULL, *prev = NULL, *next = NULL;

void create();
void insert_begn();
void insert_end();
void insert_pos();
void delete_begn();
void delete_end();
void delete_pos();
void display();
int count();

int main() {
        printf(" 1. Insert at Beginning\n");
        printf(" 2. Insert at End\n");
        printf(" 3. Insert at Position\n");
        printf(" 4. Delete from Beginning\n");
        printf(" 5. Delete from End\n");
        printf(" 6. Delete at Position\n");
        printf(" 7. Display\n");
        printf(" 8. Count\n");
        printf(" 9. Exit\n");
        while (1) {
                int c; printf("\nEnter choice: "); scanf("%d", &c);
                switch (c) {
                        case 1: insert_begn(); break;
                        case 2: insert_end(); break;
                        case 3: insert_pos(); break;
                        case 4: delete_begn(); break;
                        case 5: delete_end(); break;
                        case 6: delete_pos(); break;
                        case 7: display(); break;
                        case 8: count(); break;
                        case 9: printf("Goodbye!\n"); exit(1);
                        default: printf("Wrong choice!\n");
                }
        }
        return 0;
}

void create() {
        int n; printf("Enter data: "); scanf("%d", &n);
        new_node = (node*)malloc(sizeof(node)); 
        new_node->data = n;
        new_node->next = NULL;
        new_node->prev = NULL;
}

void display() {
        if (start == NULL) {
                printf("Underflow!");
        } else {
                temp = start;
                printf("Linked list elements (forward): START <=> ");
                while (temp != NULL) {
                        printf("%d <=> ", temp->data);
                        prev = temp;
                        temp = temp->next;
                }
                printf("NULL");
        printf("\n");
}
}

int count() {
        int c = 0;
        temp = start;
        while (temp != NULL) {
                c++;
                temp = temp->next;
        }
        printf("Item count: %d\n", c);
        return c;
}

void insert_begn() {
        create();
        if (start == NULL) {
                start = new_node;
        } else {
                new_node->next = start;
                start->prev = new_node;
                start = new_node;
        }
      
}

void insert_end() {
        create();
        if (start == NULL) {
                start = new_node;
        } else {
                temp = start;
                while (temp->next != NULL) {
                        temp = temp->next;
                }
                temp->next = new_node;
                new_node->prev = temp;
        }         
}

void insert_pos() {
        int c = count();
        int pos; printf("Enter position to insert at: "); scanf("%d", &pos);
        if (pos == 0) {
                insert_begn();
        } else if (pos == c) {
                insert_end();
        } else if (pos > 0 && pos < c) {
                int i = 1;
                temp = start;
                while (temp != NULL && i < pos - 1) { 
                        temp = temp->next;
                        i++;
                }
                create();
                new_node->next = temp->next; 
                new_node->prev = temp;
                temp->next = new_node;
                temp->next->prev = new_node;
        } else {
                printf("Invalid postion!\n");
        }
}

void delete_begn() {
        if (start == NULL) {
                printf("Underflow!\n");
        } else {
                temp = start;
                printf("Deleted: %d\n", temp->data);
                start = temp->next;
                free(temp);
        }
}

void delete_end() {
        if (start == NULL) {
                printf("Underflow!\n");
        } else {
                if (start->next == NULL) { 
                        printf("Deleted: %d\n", start->data);
                        start = NULL;
                } else {
                        temp = start;
                        while (temp->next != NULL) {
                                prev = temp;
                                temp = temp->next;
                        }
                        printf("Deleted: %d\n", temp->data);
                        prev->next = NULL;
                        free(temp);
                }
        }
}

void delete_pos() {
        int c = count();
        int pos; printf("Enter position to delete at: "); scanf("%d", &pos);
        if (pos == 0) {
                delete_begn();
        } else if (pos == c) {
                delete_end();
        } else if (pos > 0 && pos < c) {
                int i = 0;
                temp = start;
                while (temp != NULL && i < pos) {
                		prev = temp;
                        temp = temp->next;
                    	i++;
                }
                printf("Deleted: %d\n", temp->data);
                prev->next = temp->next;
                temp->next->prev = prev;
                free(temp);
        } else {
                printf("Invalid postion!\n");
        }
}