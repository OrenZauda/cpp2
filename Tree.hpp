#include <iostream>
#include <stdexcept>
using namespace std;

struct Node{
        Node(int value): data(value), left(NULL),right(NULL),parent(NULL) {}
        int data;
        Node *left;
        Node *right;
	Node *parent;
};
namespace ariel{

class Tree{

private:
	Node *_root ;
	int size(Node *root);
	void insert(Node *root, int data);
	bool contains(Node *root,int data);
	void deleteNode(Node *&root, int data);
	Node* minValueNode(Node *root);
	void deleteTree(Node *root);
	int parent(Node *root, int data);
	int left(Node* pRoot, int data);
	int right(Node* pRoot, int data);
	void print(Node *root);
	void searchData(Node* &curr, int data, Node* &parent);
	
public:
	Tree();  // constructor     
	~Tree(); // destructor
	void deleteTree() {deleteTree(_root);}
        void insert(int data){insert(_root, data);} 
 	void remove(int data){deleteNode(_root,data);};
	int size(){return size(_root);};
	bool contains(int data){return contains(_root,data);};
	int root();
	int parent(int data){return parent(_root, data);};
	int left(int data){return left(_root, data);};
	int right(int data){return right(_root, data);};
	void print(){print(_root);};
	

};
};
