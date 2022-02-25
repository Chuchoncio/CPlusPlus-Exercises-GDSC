#include <iostream>
#include "LinkedList.cpp"
#include "doubleLinkedList.cpp"
using namespace std;

void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data;
        if (node->next != NULL)
            cout << "->";
        else
            cout << "->NULL";
        node = node->next;
    }
    cout << "\n";
}

void insertVariousNodes(Node *node)
{
    insertNode(node, 1, 5);
    insertNode(node, 2, 2);
    insertNode(node, 3, 3);
    insertNode(node, 4, 8);
    insertNode(node, 5, 9);
    insertNode(node, 6, 11);
}

void question_1()
{
    Node *head = new Node(5);

    insertVariousNodes(head);
    printList(head);
}

int countNodes(Node *head)
{
    int countNodes = 0;
    while (head != NULL)
    {
        countNodes++;
        head = head->next;
    }
    return countNodes;
}

void question_2()
{
    Node *head = new Node(5);

    insertVariousNodes(head);
    cout << "Nodes in the Linked List: " << countNodes(head) << endl;
}

Node *insertNodeAtTail(Node *head, int data)
{
    Node *temp = new Node(data);
    Node *currHead = head;
    if (head != NULL)
    {
        while (head->next != nullptr)
        {
            head = head->next;
        }
        head->next = temp;
        head = currHead;
    }
    else
    {
        head = temp;
    }

    return head;
}

void question_3()
{
    Node *head = new Node(3);
    insertVariousNodes(head);
    head = insertNodeAtTail(head, 11);
    printList(head);
}

Node *deleteNode(Node *list, int pos)
{
    Node *prev,
        *head = list;

    if (pos != 0)
    {
        while (pos)
        {
            prev = list;
            list = list->next;
            pos--;
        }

        if (list->next == nullptr)
            prev->next = nullptr;
        else
            prev->next = list->next;

        list = head;

        if (list == nullptr)
            return nullptr;
    }
    else
        list = list->next;

    return list;
}

void question_4()
{
    Node *head = new Node(1);
    int pos = 4;
    insertVariousNodes(head);
    printList(head);
    head = deleteNode(head, pos);
    printList(head);
}

Node *makeListCircular(Node *list)
{
    Node *head = list;

    while (list->next != nullptr)
    {
        list = list->next;
    }

    list->next = head;
    list = list->next;

    return list;
}

void printCircularList(Node *list)
{
    Node *head = list;

    do
    {
        cout << list->data;
        if (list->next != head)
            cout << "->";
        else
            cout << "->loop...";
        list = list->next;
    } while (head != list);
    cout << endl;
}

int isCircular(Node *list)
{
    Node *head = list;

    if (list == nullptr)
        return 1;
    else
    {
        while (list)
        {
            list = list->next;
            if (list == head)
                return 1;
        }
        return 0;
    }
}

void question_5()
{
    Node *head = new Node(1);
    int pos = 4;
    insertVariousNodes(head);
    printList(head);
    // head = makeListCircular(head);
    // printCircularList(head);
    if (isCircular(head))
        cout << "The list is circular" << endl;
    else
        cout << "The list is NOT circular" << endl;
}

Node *reverseList(Node *head)
{
    Node *curr = head,
         *next = NULL,
         *prev = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;

    return head;
}

void question_6()
{
    Node *head = new Node(1);
    insertVariousNodes(head);
    printList(head);
    head = reverseList(head);
    printList(head);
}

Node *partition(Node *&head, Node *&rear)
{
    Node *temp, *output = head;
    if (head == rear)
        return head;
    int pivot = head->data;
    Node **curr = &(head->next);
    while (*curr != rear->next)
    {
        if ((*curr)->data < pivot)
        {
            temp = *curr;
            if (*curr == rear)
            {
                Node *temp_rear = output;
                while (temp_rear->next != temp)
                    temp_rear = temp_rear->next;
                rear = temp_rear;
            }
            *curr = (*curr)->next;
            push(&head, temp->data);
            free(temp);
            temp = nullptr;
            continue;
        }
        curr = &((*curr)->next);
    }

    return output;
}

void _quickSort(Node *&head, Node *&rear)
{
    Node *middle = partition(head, rear);

    if (middle != head)
    {
        Node *curr = head;
        while (curr->next != middle)
            curr = curr->next;
        _quickSort(head, curr);
    }

    if (middle != rear)
        _quickSort(middle->next, rear);
}

void quickSort(struct Node **headRef)
{
    if ((*headRef)->next == nullptr)
        return;
    Node *tail = *headRef;
    while (tail->next != nullptr)
        tail = tail->next;

    _quickSort(*headRef, tail);
}

void question_7()
{
    Node *head = new Node(1);
    insertVariousNodes(head);
    printList(head);
    quickSort(&head);
    printList(head);
}

Node* reArrangeList(Node* head) {
    Node* temp,
        * end;
    int count;  

    if(!head) {
        return head;
    }

    end = head;
    count = 0;
    while(end->next != nullptr) {
        end = end->next;
        count++;
    }

    temp = head;
    count = count%2 == 0? count/2 : (count/2)+1;

    while(count) {
        end->next = temp->next;
        temp->next = temp->next->next;
        end->next->next = NULL;

        end = end->next;
        temp = temp->next;
        count--;
    }

    return head;
}

void question_8() {
    Node *head = new Node(1);
    insertVariousNodes(head);
    printList(head);
    head = reArrangeList(head);
    printList(head);
}

DoublyLinkedListNode *sortedInsert(DoublyLinkedListNode *llist, int data)
{
    DoublyLinkedListNode *head = llist;
    DoublyLinkedListNode *temp = new DoublyLinkedListNode(data);

    if (head == NULL || head->next == NULL)
        return llist;
    else if (head->data <= data || head->next->data <= data)
    {
        while (head->next != NULL && head->next->data <= data)
            head = head->next;

        temp->prev = head;
        temp->next = head->next;
        if (head->next != NULL)
            head->next->prev = temp;
        head->next = temp;

        while (head != llist)
            head = head->prev;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }

    return head;
}

void question_9()
{
    ofstream myfile;
    myfile.open("output.txt");

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = new DoublyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        int data;
        cin >> data;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);

        print_doubly_linked_list(llist1, myfile, " ");

        free_doubly_linked_list(llist1);
    }

    myfile.close();
}

int main()
{
    // question_1();
    // question_2();
    // question_3();
    // question_4();
    // question_5();
    // question_6();
    // question_7();
    //question_8();
    //question_9();

    system("pause");
}