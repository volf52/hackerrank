#include <stdio.h>
#include <stdlib.h>

typedef struct SinglyLinkedListNode SinglyLinkedListNode;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* createNode(int);
void printCycleList(SinglyLinkedListNode* node, char* sep, FILE* fptr, int n1, int n2);
SinglyLinkedListNode* createCycleList(int* arrOne, int n1, int* arr2, int n2);
int cyclePresent(SinglyLinkedListNode* head);

void print(SinglyLinkedListNode* node, int n1, int n2)
{
    printCycleList(node, "->", stdout, n1, n2);
    printf("\n\n");
}

int main()
{
    SinglyLinkedListNode* head;
    int res;
    int arr1[] = { 1, 2, 3 };
    int arr2[] = { 4, 5, 6 };

    head = createCycleList(arr1, 3, arr2, 3);
    print(head, 3, 3);

    res = cyclePresent(head);
    printf("Cycle present: %d\n", res);

    return 0;
}

int cyclePresent(SinglyLinkedListNode* head)
{
    SinglyLinkedListNode *slow, *fast;

    if (!head)
        return 0;

    fast = head;
    slow = head;

    while (fast && slow && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            return 1;
    }

    return 0;
}

SinglyLinkedListNode* createCycleList(int* arrOne, int n1, int* arr2, int n2)
{
    int i;
    SinglyLinkedListNode *head, *curr, *tmp;

    if (!(n1 && n2))
        return NULL;

    head = createNode(arrOne[0]);
    curr = head;
    for (i = 1; i < n1; i++) {
        curr->next = createNode(arrOne[i]);
        curr = curr->next;
    }

    tmp = curr;

    for (i = 0; i < n2; i++) {
        curr->next = createNode(arr2[i]);
        curr = curr->next;
    }

    curr->next = tmp;

    return head;
}

SinglyLinkedListNode* createNode(int nodeData)
{
    SinglyLinkedListNode* node = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));

    node->data = nodeData;
    node->next = NULL;

    return node;
}

void printCycleList(SinglyLinkedListNode* node, char* sep, FILE* fptr, int n1, int n2)
{
    int i;
    char *s1, *s2;

    if (!node)
        return;

    i = 0;
    s1 = "{Cycle start}";
    s2 = "{Cycle end}";

    while (i < n1) {
        fprintf(fptr, "%d", node->data);

        node = node->next;

        if (node) {
            fprintf(fptr, "%s", sep);
        }
        i++;
    }
    fprintf(fptr, "%s", s1);

    i = 0;
    while (i < n2) {
        fprintf(fptr, "%d", node->data);

        node = node->next;

        if (node) {
            fprintf(fptr, "%s", sep);
        }
        i++;
    }
    fprintf(fptr, "%s", s2);
}
