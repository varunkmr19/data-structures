#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

class Stack {
private:
    Node *top;
public:
    Stack() {
        top = NULL;
    }

    // returns true/false on whether the stack is empty 
    bool isEmpty() {
        return top==NULL;
    }
    
    // returns length of the stack
    int length() {
        int len = 0;
        Node *temp = top;
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

    // insert node at the top of the stack
    void push(int key) {
        Node *newNode = createNode(key);
        if(this->isEmpty()) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
    }

    // returns the top element of the stack
    int getTop() {
        if(this->isEmpty()) {
            cout << "Stack is Empty" << "\n";
            exit(0);
        } else {
            return top->data;
        }
    }

    // removes the top element
    void pop() {
        if(this->isEmpty()) {
            cout << "Stack is Empty" << "\n";
            exit(0);
        } else {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }

    // displays the elements of the stack 
    void print() {
        Node *temp = top;
        while(temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        delete temp;
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    cout << s.getTop() << "\n";
    s.pop();
    cout << s.getTop() << "\n";
}