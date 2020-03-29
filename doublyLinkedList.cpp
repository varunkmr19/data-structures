#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

class doublyLinkedList {
private:
    Node *head, *tail;
public:
    doublyLinkedList() {
        head = NULL;
        tail = NULL;
    }

    // create and returns a node with key as it's data
    Node* createNode(int key) {
        Node *newNode = new Node;
        newNode->prev = NULL;
        newNode->next = NULL;
        newNode->data = key;

        return newNode;
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
            newNode->prev = tail;
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
            newNode->prev = traverse;
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
            head->prev = NULL;
        } else if(index == this->length()-1) {  // delete tail
            tail = tail->prev;
            tail->next = NULL;
        } else {     // delete at the given index
            Node *temp = head;
            for(int i=1;i<=index;i++) {
                temp = temp->next;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            delete temp;
        }
    }

    // displays the list
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
    doublyLinkedList dll;
    dll.push_back(5);
    dll.push_front(1);
    dll.push_back(10);
    dll.push_in_between(1,2);
    dll.removeAt(1);
    dll.print();
}