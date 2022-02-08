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

void printList(Node* node) {
    while(node != NULL) {
        cout << node->data << endl;
        node = node->next; 
    }
}

int main() {

    Node* head = new Node(5);

    insertNode(head, 1, 5);
    insertNode(head, 2, 2);
    insertNode(head, 3, 3);
    insertNode(head, 4, 8);
    insertNode(head, 5, 9);

    printList(head);

    system("pause");
}