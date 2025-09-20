#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};


void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteFromStart(Node*& head) {
    if (head == NULL) {
        cout << "List is empty. No node to delete." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    delete temp;
    cout << "Node deleted from start!" << endl;
}

// Delete from any position
void deleteAtPosition(Node*& head, int pos) {
    if (head == NULL) {
        cout << "List is empty. No node to delete." << endl;
        return;
    }

    if (pos == 1) {
        deleteFromStart(head);
        return;
    }

    Node* temp = head;
    int count = 1;
    while (temp != NULL && count < pos) {
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        cout << "Position out of range!" << endl;
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    delete temp;
    cout << "Node deleted from position " << pos << "!" << endl;
}


void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;


    insertAtEnd(head, 10);
    insertAtEnd(head, 20);
    insertAtEnd(head, 30);
    insertAtEnd(head, 40);
    insertAtEnd(head, 50);

    cout << "Original List: ";
    display(head);


    deleteAtPosition(head, 1);
    display(head);

  
    deleteAtPosition(head, 3);
    display(head);

   
    deleteAtPosition(head, 10);
    display(head);

    return 0;
}
