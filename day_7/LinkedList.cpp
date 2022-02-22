#include <iostream>

using namespace std;

class Node {
    public:

        int data;
        Node* next;

        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

Node* insertNode(Node* head, int i, int data) {

    Node* newNode = new Node(data);
    Node* temp = head;
    int count = 0;

    // En caso de que se inserte al inicio
    if(i == 0) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    // En caso de que se inserte en una posicion en especifico
    //  o al final de la lista
    while(temp != NULL && count < i-1) {
        temp = temp->next;
        count++;
    }

    if(temp != NULL) {
        Node *a = temp->next;
        temp->next = newNode;
        newNode->next = a;
    }

    return head;
}

Node* insertAtEnd(Node* head, int data) {

    Node* newNode = new Node(data);
    Node* temp = head;
    
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;

    return head;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}