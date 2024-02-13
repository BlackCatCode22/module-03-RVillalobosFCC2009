#include <iostream> 
using namespace std; 
  
struct Node { 
    int data;
    Node* next;
};

void putinside(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;
    if (*head == nullptr) { 
        *head = newNode;
    } else { 
        Node* last = *head;
        while (last->next != nullptr) { 
            last = last->next;
        }
        last->next = newNode;
    }
}

void displaylist(Node* node) { 
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout <<endl;
}

// Implement deleteNode function based on the requirements

int main() { 
    Node* head = nullptr;
    putinside(&head, 27);
    putinside(&head, 28);
    putinside(&head, 29);
    displaylist(head);
    // Call deleteNode function as required
    return 0; 
} 
