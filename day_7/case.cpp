#include <iostream>
using namespace std;

class Node{
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
    
    if(i == 0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    
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
        cout << node->data;
        node = node->next;
    }
}

Node* sumLinkedLists(Node* l1, Node* l2) {
    Node* res = NULL;
    Node* temp;
    Node* prev = NULL;
    int carry = 0, sum;

    while(l1 != NULL || l2 != NULL) {
        sum = carry + (l1 ? l1->data : 0) + (l2 ? l2->data : 0);

        carry = (sum >= 10) ? 1 : 0;

        sum = sum % 10;

        Node* temp = new Node(sum);

        if(res == NULL)
            res = temp;
        else
            prev->next = temp;

        prev = temp;

        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;
    }

    if(carry > 0)
        insertAtEnd(temp, carry);
    
    return res;
}

Node* reverseList(Node* head) {
    if(head == NULL || head->next == NULL)
        return head;

    Node* rest = reverseList(head->next);
    head->next->next = head;

    head->next = NULL;

    return rest;
}

int main() {
	int t, n, m, i;
	int dataL1, dataL2;
	Node* l1;
	Node* l2;
    Node* lSum = NULL;
	
	cin >> t;
	
	while(t){
	    
	    cin >> n >> m;
	    
	    for(i = 0; i < n; i++) {
	        cin >> dataL1;
	        if(i == 0)
                l1 = insertNode(l1, i, dataL1);
            else
                l1 = insertAtEnd(l1, dataL1);
	    }

	    for(i = 0; i < m; i++) {
	        cin >> dataL2;
	        if(i == 0)
                l2 = insertNode(l2, i, dataL2);
            else
                l2 = insertAtEnd(l2, dataL2);
	    }

        //lSum = sumLinkedLists(l1, l2);
        //lSum = reverseList(lSum);
        //printList(lSum);
        printList(l1);
        printList(l2);
	    
	    t--;
	}
	
	return 0;
}