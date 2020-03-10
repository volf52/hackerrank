#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLinkedListNode DoublyLinkedListNode;

struct DoublyLinkedListNode {
    int data;
    DoublyLinkedListNode* next;
    DoublyLinkedListNode* prev;
};

DoublyLinkedListNode* createNode(int nodeData);
void printList(DoublyLinkedListNode* node, char* sep, FILE* fptr);
DoublyLinkedListNode* createList(int* arr, int n, DoublyLinkedListNode* atEnd);
DoublyLinkedListNode* freeList(DoublyLinkedListNode* node);
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data);
int isSorted(DoublyLinkedListNode* head);

void print(DoublyLinkedListNode* head)
{
    if (!head) {
        printf("Empty list\n\n");
        return;
    }

    printList(head, "<->", stdout);
    printf("\n\n");
}

int main()
{
    DoublyLinkedListNode* head;
    int i, n, toAdd;
    int arr[] = { 7,
        7,
        8,
        28,
        32,
        33,
        39,
        48,
        48,
        53,
        55,
        62,
        64,
        66,
        68,
        68,
        76,
        81,
        87,
        88,
        90,
        91,
        92,
        94,
        95,
        97 };
    toAdd = 94;

    n = sizeof(arr) / sizeof(int);

    head = createList(arr, n, NULL);
    print(head);
    printf("Head pointer: %p\n", head);
    i = isSorted(head);
    printf("Is sorted: %d\n", i);
    head = sortedInsert(head, toAdd);
    // print(head);
    i = isSorted(head);
    printf("Is sorted: %d\n", i);
    print(head);

    freeList(head);

    return 0;
}

int isSorted(DoublyLinkedListNode* head)
{
    if (!head)
        return 0;

    while (head->next && head->data <= head->next->data)
        head = head->next;

    return (head->next == NULL);
}

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data)
{
    DoublyLinkedListNode *node, *curr;

    node = createNode(data);

    if (!head)
        return node;

    curr = head;

    while ((curr->data < data) && (curr->next))
        curr = curr->next;

    if (data <= curr->data) {
        node->prev = curr->prev;
        curr->prev = node;
        node->next = curr;
        if (node->prev)
            node->prev->next = node;
        else
            head = node;
    } else {
        curr->next = node;
        node->prev = curr;
    }

    return head;
}

DoublyLinkedListNode* createList(int* arr, int n, DoublyLinkedListNode* atEnd)
{
    int i;
    DoublyLinkedListNode *head, *curr, *prev;

    if (!n)
        return NULL;

    head = createNode(arr[0]);
    curr = head;
    prev = head;
    for (i = 1; i < n; i++) {
        prev = curr;
        curr->next = createNode(arr[i]);
        curr = curr->next;
        curr->prev = prev;
    }

    curr->next = atEnd;

    return head;
}

DoublyLinkedListNode* createNode(int nodeData)
{
    DoublyLinkedListNode* node;

    node = (DoublyLinkedListNode*)malloc(sizeof(DoublyLinkedListNode));

    node->data = nodeData;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void printList(DoublyLinkedListNode* node, char* sep, FILE* fptr)
{
    while (node) {
        fprintf(fptr, "%d", node->data);

        node = node->next;

        if (node) {
            fprintf(fptr, "%s", sep);
        }
    }
}

DoublyLinkedListNode* freeList(DoublyLinkedListNode* node)
{
    DoublyLinkedListNode* tmp;
    while (node) {
        tmp = node;
        node = node->next;

        free(tmp);
    }

    return NULL;
}