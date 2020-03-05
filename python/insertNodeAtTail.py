from typing import Type, Optional
import sys


class SinglyLinkedListNode:
    def __init__(self, node_data: int):
        self.data = node_data
        self.n: Optional[SinglyLinkedListNode] = None


class SinglyLinkedList:
    def __init__(self):
        self.head: Optional[SinglyLinkedListNode] = None


def print_singly_linked_list(node, sep, fptr):
    while node:
        fptr.write(str(node.data))

        node = node.n

        if node:
            fptr.write(sep)


def insertNodeAtTail(
    head: Optional[SinglyLinkedListNode], data: int
) -> SinglyLinkedListNode:
    node = SinglyLinkedListNode(data)
    if head is None:
        return node
    else:
        curr = head
        while curr.n is not None:
            curr = curr.n
        curr.n = node
        return head


arr = [141, 302, 164, 530, 474]

llist = SinglyLinkedList()

for item in arr:
    llHead = insertNodeAtTail(llist.head, item)
    llist.head = llHead

print_singly_linked_list(llist.head, "\n", sys.stdout)

