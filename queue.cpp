#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class Queue {
private:
    Node *front, *back;
public:
    Queue() {
        front = NULL;
        back = NULL;
    }

    // returns true/false on whether the queue is empty 
    bool isEmpty() {
        return front==NULL;
    }
    
    // returns length of the queue
    int length() {
        int len = 0;
        Node *temp = front;
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

    // returns the front element of the queue
    int peek() {
        if(this->isEmpty()) {
            cout << "Queue is Empty" << "\n";
            exit(0);
        } else {
            return front->data;
        }
    }

    // adds element at the back of the queue
    void Enqueue(int key) {
        Node *newNode = createNode(key);
        if(this->isEmpty()) {
            front = back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
    }

    // removes the element from the front of the queue
    void Dequeue() {
        if(this->isEmpty()) {
            cout << "Queue is Empty" << "\n";
            return;
        } else {
            front = front->next;
        }
    }

    // returns true/false on whether the key is present in the queue
    bool contains(int key) {
        Node *newNode = front;
        while(newNode) {
            if(newNode->data == key)
                return true;
            newNode = newNode->next;
        }
        return false;
    }

    // displays the elements of the stack 
    void print() {
        Node *temp = front;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        delete temp;
    }
};

int main() {
    Queue q;
    q.Enqueue(1);
    q.Enqueue(2);
    q.print();
    q.Dequeue();
    cout << q.peek();
    cout << q.contains(2);
}