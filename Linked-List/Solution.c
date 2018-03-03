#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdlib.h>

#define SIZE_OF_ARRAY 200
typedef struct Node node;

struct Node {
    int data;
    node *next;
};

///*prototypes*//
void skipJremoveK(node *head, int p, int q);

void addData(node **head2, int newData);

void printList(node *head);

///**///
node *head = NULL;

void addData(node **head2, int newData) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->data = newData;
    newNode->next = (*head2);
    (*head2) = newNode;
}

void skipJremoveK(node *head, int p, int q) {
    node *current = head, *np;
    int i, j;
    while (current) {
        for (i = 0; i < p - 1 && current != NULL; ++i)
            current = current->next;
        if (current == NULL)return;
        //  printf(">%d, ", current->data);
        //printf(">%d, ", current->next->data);
        np = current->next;
        for (j = 0; j < q && np != NULL; ++j) {
            node *tmp = np;
            np = np->next;
            free(tmp);
        }
        current->next = np; //link ic ic ferahla.
        current = np;//baya iyi anladim hatirlamazsan hatirlamaya calis bu satiri.
    }


}

void printList(node *head) {
    node *tmp = head;
    while (tmp != NULL) {
        printf("%d, ", tmp->data);
        tmp = tmp->next;
    }

}

int main() {
    int i, j, k;
    srand(time(NULL));
    printf("how many numbers you want to skip: ");
    scanf("%d", &j);
    while ((j > SIZE_OF_ARRAY) || (j <= 0)) {
        perror("Error");
        while (((j = getchar()) != '\n'))
            continue;
        printf("Please enter a value less than Size_of_Array:  ");
        scanf("%d", &j);
    }
    printf("How many numbers you want to delete: ");
    scanf("%d", &k);
    while ((k > SIZE_OF_ARRAY) || (k <= 0)) {
        perror("Error");
        while ((k = getchar()) != '\n')
            continue;
        printf("Please enter a value less than Size_of_Array:  ");
        scanf("%d", &k);
    }
    for (i = 0; i < SIZE_OF_ARRAY; ++i) {
        addData(&head, rand() % 100);
    }
    printf("j = %d, k = %d \nGiven Linked list: \n", j, k);
    printList(head);
    skipJremoveK(head, j, k);
    printf("\nLinked list after deletion: \n");
    printList(head);
    return 0;
}