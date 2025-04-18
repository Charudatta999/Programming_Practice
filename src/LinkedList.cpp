#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}  // Default constructor initializing value to 0
    ListNode(int x, ListNode *nextNode = nullptr) : val(x), next(nextNode) {}
};

// Function to print the linked list
void printList(ListNode *node) {
    while (node != nullptr) {
        std::cout << node->val << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {
    // Initialize the head of the linked list with the first node
    ListNode *head = new ListNode(0);  // Initialize head with value 0
    ListNode *tempNode = head;

    // Loop to add 5 new nodes to the linked list
    for (int i = 1; i < 6; ++i) {
        auto newNode = new ListNode(i);  // Create a new node with value i
        tempNode->next = newNode;        // Link the new node to the current list
        tempNode = newNode;              // Move the tempNode pointer to the new node
    }

    // Print the linked list to verify the output
    std::cout << "Linked List Content: ";
    printList(head);

    // Clean up allocated memory
    while (head != nullptr) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
