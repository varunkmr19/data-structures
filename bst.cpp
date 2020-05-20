#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

class Bst {
private:
	int nodeCount;
	Node *root;
	
	Node* createNode(Node *left, Node *right, int data) {
		Node *newNode = new Node;
		newNode->data = data;
		newNode->left = left;
		newNode->right = right;
		
		return newNode;
	}
	
	bool contains(Node *node, int data) {
		if(node == NULL)
			return false;
			
		int cmp = compareTo(data, node->data);
		
		if(cmp < 0) {
			return contains(node->left, data);
		} else if(cmp > 0) {
			return contains(node->right, data);
		} else {
			return true;
		}
	}
	
	int compareTo(int childVal, int rootVal) {
		if(childVal < rootVal)
			return -1;
		else if(childVal > rootVal)
			return 1;
		else
			return 0;
	}
	
	Node* add(Node *node, int data) {
		if(node == NULL) {
			node = createNode(NULL,NULL,data);
		} else {
			if(compareTo(data, node->data) < 0) {
				node->left = add(node->left, data);
			} else {
				node->right = add(node->right, data);
			}
		}
		return node;
	}
	
	Node* remove(Node *node, int data) {
		if(node == NULL)
			return NULL;
		
		int cmp = compareTo(data, node->data);
		
		if(cmp < 0) {
			node->left = remove(node->left,data);
		} else if(cmp > 0) {
			node->right = remove(node->right, data);
		} else {
			if(node->left == NULL) {
				Node *rightChild = node->right;
				node = NULL;
				delete node;
				
				return rightChild;
			} else if(node->right == NULL) {
				Node *leftChild = node->left;
				node = NULL;
				delete node;
				
				return leftChild;
			} else {
				Node *temp = findMin(node->right);
				swap(node->data, temp->data);
				node->right = remove(node->right, temp->data);
			}
		}
		return node;
	}
	void inorder(Node *root) {
		if(root) {
			inorder(root->left);
			cout << root->data << " ";
			inorder(root->right);
		}
	}
	
public:
	Bst() {
		root = NULL;
	}
	
	bool isEmpty() {
		return size() == 0;
	}
	
	int size() {
		return nodeCount;
	}
	
	bool contains(int ele) {
		return contains(root, ele);
	}
	
	bool add(int ele) {
		if(contains(ele)) {
			return false;
		}
		else {
			root = add(root, ele);
			nodeCount++;
			return true;
		}
	}
	
	bool remove(int ele) {
		if(contains(ele)) {
			root = remove(root, ele);
			nodeCount--;
			return true;
		} else {
			return false;
		}
	}
	
	Node *findMin(Node *node) {
		while(node->left != NULL) {
			node = node->left;
		}
		return node;
	}
	
	Node *findMax(Node *node) {
		while(node->right != NULL) {
			node = node->right;
		}
		return node;
	}
	
	void display() {
		inorder(root);
	}
	
};

int main() {
	Bst b;
	b.add(10);
	b.add(3);
	b.add(20);
	
	b.display();
	
	cout << b.remove(3) << endl;
	
	b.display();
}
