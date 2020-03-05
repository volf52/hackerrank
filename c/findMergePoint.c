#include <stdio.h>
#include <stdlib.h>

typedef struct SinglyLinkedListNode SinglyLinkedListNode;
typedef struct SinglyLinkedList SinglyLinkedList;

struct SinglyLinkedListNode {
    int data;
    SinglyLinkedListNode* next;
};

SinglyLinkedListNode* createNode(int);
void printList(SinglyLinkedListNode* node, char* sep, FILE* fptr);
SinglyLinkedListNode* createList(int* arr, int n, SinglyLinkedListNode* atEnd);
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2);

void print(SinglyLinkedListNode* node)
{
    printList(node, "->", stdout);
    printf("\n\n");
}

int main()
{
    SinglyLinkedListNode *head1, *head2, *mergeNode;
    int ret;

    int arr1[] = { 1, 2, 3 };
    int arr2[] = { 5, 6 };
    int arr3[] = { 4, 7, 8, 9 };

    mergeNode = createList(arr3, 4, NULL);
    head1 = createList(arr1, 3, mergeNode);
    head2 = createList(arr2, 2, mergeNode);

    print(mergeNode);
    print(head1);
    print(head2);

    ret = findMergeNode(head1, head2);
    printf("Merge node point: %d\n", ret);

    return 0;
}

int getLength(SinglyLinkedListNode* node)
{
    if (!node)
        return 0;
    return 1 + getLength(node->next);
}

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
    // http://techieme.in/merge-point-of-two-linked-lists/
    SinglyLinkedListNode *longList, *shortList, *fast, *slow;
    int len1, len2;

    if (!(head1 && head2))
        return -1;

    len1 = getLength(head1);
    len2 = getLength(head2);

    if (len1 > len2) {
        longList = head1;
        shortList = head2;
    } else {
        longList = head2;
        shortList = head1;
    }

    slow = longList;
    while (slow->next)
        slow = slow->next;
    slow->next = longList;

    slow = shortList;
    fast = shortList;

    while (fast && fast->next && slow) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow)
            break;
    }

    if (fast == slow) {
        fast = shortList;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return fast->data;
    }

    return -1;
}

SinglyLinkedListNode* createList(int* arr, int n, SinglyLinkedListNode* atEnd)
{
    int i;
    SinglyLinkedListNode *head, *curr;

    if (!n)
        return NULL;

    head = createNode(arr[0]);
    curr = head;
    for (i = 1; i < n; i++) {
        curr->next = createNode(arr[i]);
        curr = curr->next;
    }

    curr->next = atEnd;

    return head;
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
