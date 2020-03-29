#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
private:
    Node *head, *tail;
public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    // returns true/false on whether the list is empty 
    bool isEmpty() {
        return head==NULL;
    }
    
    // returns length of the list
    int length() {
        int len = 0;
        Node *temp = head;
        while(temp) {
            len++;
            temp = temp->next;
        }
        delete temp;
        return len;
    }

    // create and returns a node with key as it's data
    Node* createNode(int key) {
        Node *newNode = new Node;
        newNode->data = key;
        newNode->next = NULL;
        return newNode;
    }

    // inserts node at the front of the list
    void push_front(int key) {
        Node *newNode = createNode(key);
        if(this->isEmpty()) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    // inserts node at the back of the list
    void push_back(int key) {
        if(this->isEmpty()) {
            push_front(key);
        } else {
            Node *newNode = createNode(key);
            tail->next = newNode;
            tail = newNode;
        }
    }

    void push_in_between(int index, int key) {
        if(index < 0 || index > this->length()) {
            cout << "Index out of bounds" << "\n";
            return;
        }
        if(index == 0) {    // insert at front
            push_front(key);
        } else if(index  == this->length()) {   // insert at the back
            push_back(key);
        } else {    // insert at the given index
            Node *newNode = createNode(key);
            Node *traverse = head;
            for(int i=1;i<index;i++) {
                traverse->next;
            }
            newNode->next = traverse->next;
            traverse->next = newNode;
        }
    }

    void removeAt(int index) {
        if(index < 0 || index >= this->length()) {
            cout << "Index out of bounds" << "\n";
            return;
        } else if (this->isEmpty()) {
            cout << "No Node to delete." << "\n";
            return;
        } else if(index == 0) { //delete head
            head = head->next;
        } else if(index == this->length()-1) {  // delete tail
            Node *temp = head;
            for(int i=1;i<index;i++) {
                temp = temp->next;
            }
            temp->next = NULL;
            tail = temp;
        } else {    // delete at the given index
            Node *temp = head;
            for(int i=1;i<index;i++) {
                temp = temp->next;
            }
            temp->next = temp->next->next;
        }
    }

    void print() {
        Node *temp = head;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        delete temp;
    }
};

int main() {
    LinkedList l;
    l.push_back(5);
    l.push_front(1);
    l.push_back(10);
    l.push_in_between(1,2);
    l.removeAt(1);
    l.print();
}