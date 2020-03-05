#include <stdio.h>
#include <stdlib.h>

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

struct SinglyLinkedList {
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;
};

SinglyLinkedListNode* createNode(int);
void printList(SinglyLinkedListNode* node, char* sep, FILE* fptr);
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);

void print(SinglyLinkedListNode* node)
{
    printList(node, " ", stdout);
    printf("\n\n");
}

int main()
{
    SinglyLinkedListNode *h1, *h2, *head;

    // L1
    h1 = createNode(4);
    h1->next = createNode(5);
    h1->next->next = createNode(6);

    // L2
    h2 = createNode(1);
    h2->next = createNode(2);
    h2->next->next = createNode(10);

    print(h1);
    print(h2);

    head = mergeLists(h1, h2);
    print(head);

    return 0;
}

SinglyLinkedListNode* createNode(int node_data)
{
    SinglyLinkedListNode* node = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));

    node->data = node_data;
    node->next = NULL;

    return node;
}

void printList(SinglyLinkedListNode* node, char* sep, FILE* fptr)
{
    while (node) {
        fprintf(fptr, "%d", node->data);

        node = node->next;

        if (node) {
            fprintf(fptr, "%s", sep);
        }
    }
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{

    if (!head1)
        return head2;
    if (!head2)
        return head1;

    if (head1->data <= head2->data) {
        head1->next = mergeLists(head1->next, head2);
        return head1;
    } else {
        head2->next = mergeLists(head1, head2->next);
        return head2;
    }
}