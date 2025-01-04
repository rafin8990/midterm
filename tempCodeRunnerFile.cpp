#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    string val;
    Node* next;
    Node* prev;

    Node(string val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node* &head, Node* &tail, string val)
{
    Node* newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

bool check_start_word_with_visit(string &command)
{
    string prefix = "visit ";
    if (command.size() < prefix.size()) return false;

    for (int i = 0; i < prefix.size(); i++)
    {
        if (command[i] != prefix[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    string address;

    while (true)
    {
        cin >> address;
        if (address == "end")
        {
            break;
        }
        insert_at_tail(head, tail, address);
    }

    int Q;
    cin >> Q;
    cin.ignore();

    Node *current = head;
    string command;

    for (int i = 0; i < Q; i++)
    {
        getline(cin, command);

        if (check_start_word_with_visit(command))
        {
            string target = "";
            for (int j = 6; j < command.size(); j++)
            {
                target += command[j];
            }

            Node* tmp = head;
            bool found = false;

            while (tmp != NULL)
            {
                if (tmp->val == target)
                {
                    current = tmp;
                    cout << current->val << endl;
                    found = true;
                    break;
                }
                tmp = tmp->next;
            }

            if (!found)
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "next")
        {
            if (current != NULL && current->next != NULL)
            {
                current = current->next;
                cout << current->val << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (command == "prev")
        {
            if (current != NULL && current->prev != NULL)
            {
                current = current->prev;
                cout << current->val << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}
