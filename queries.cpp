#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *prev;

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

bool insert_at_index(Node* &head, Node* &tail, int index, int value)
{
    Node* newNode = new Node(value);

    if (index == 0)
    {
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        return true;
    }

    Node* temp = head;
    int count = 0;

    while (temp != NULL && count < index - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        delete newNode;
        return false;
    }

    if (temp->next == NULL)
    {
        temp->next = newNode;
        newNode->prev = temp;
        tail = newNode;
    }
    else
    {
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
    return true;
}

void print_left_to_right(Node* head)
{
    cout << "L -> ";
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void print_right_to_left(Node* tail)
{
    cout << "R -> ";
    Node* temp = tail;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    int Q;
    cin >> Q;

    while (Q--)
    {
        int X, V;
        cin >> X >> V;

        if (X < 0 || !insert_at_index(head, tail, X, V))
        {
            cout << "Invalid" << endl;
        }
        else
        {
            print_left_to_right(head);
            print_right_to_left(tail);
        }
    }

    return 0;
}
