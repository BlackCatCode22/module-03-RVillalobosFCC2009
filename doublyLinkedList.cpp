#include <iostream> 
using namespace std; 

// Node struct definition for doubly linked list
struct Node { 
    int data;
    Node* next;
    Node* prev;
};

// Function to insert a node at the end of the list
void putinside(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (*head == nullptr) { 
        *head = newNode;
    } else { 
        Node* last = *head;
        while (last->next != nullptr) { 
            last = last->next;
        }
        last->next = newNode;
        newNode->prev = last;
    }
}

// Function to display all nodes in the list
void displaylist(Node* node) { 
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Function to delete a node by value
void deleteNode(Node** head, int value) {
    if (*head == nullptr) {
        cout << "List is empty. Cannot delete.\n";
        return;
    }

    Node* current = *head;
    while (current != nullptr && current->data != value) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Node with value " << value << " not found.\n";
        return;
    }

    if (current->prev != nullptr) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }

    delete current;
}

int main() { 
    Node* head = nullptr;
    putinside(&head, 27);
    putinside(&head, 28);
    putinside(&head, 29);

    cout << "Original List: ";
    displaylist(head);

    // Call deleteNode function to delete a node with a specific value
    deleteNode(&head, 28);

    cout << "List after deleting node with value 28: ";
    displaylist(head);

    return 0; 
}