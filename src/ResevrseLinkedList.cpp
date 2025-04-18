#include<iostream>
#include<vector>

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
    Node();
};

// Helper function to print the list
void printList(Node* head) {
    while (head) {
        std::cout << head->data;
        if (head->next) std::cout << " → ";
        head = head->next;
    }
    std::cout << std::endl;
}


void resverse(Node* head)
{
    Node* previous = new Node();
    while (head->next != nullptr)
    {
        Node* temp = new Node();
        temp = head;
        previous->next  = temp;
        
    }
    

}

int main() {
    // Creating nodes
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Print the linked list
    resverse(head);
    printList(head);

    // Cleanup
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}

