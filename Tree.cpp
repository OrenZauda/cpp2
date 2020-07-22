//source code : https://www.geeksforgeeks.org/binary-search-tree-set-2-delete/

#include <iostream>
#include "Tree.hpp"
#include <stdexcept>
using namespace std;





namespace ariel{
Tree::Tree()
{  
_root = nullptr;   
}
void Tree::insert(Node *root,int data)
{ 
	
   
   //check if the number already exist
   if(contains(root,data)){throw std::invalid_argument( "number is already exist" );}
    
   if (root == nullptr)
        {
	//initilize the tree if t is the first node
                Node *root = new Node(data);           
                _root = root;           
        }
        else
        {
                if (data < root->data)
                {
                        if (root->left == nullptr)
                        {
                                Node *temp = new Node(data);
                                root->left = temp;
                        }
                        else
                                insert(root->left, data);
                }
                else
                {
                        if (root->right==nullptr)
                        {
                                Node *temp = new Node(data);                         
                                root->right = temp;
                        }
                        else
                                insert(root->right, data);
                }
        }
	
}
Node * Tree::minValueNode(Node *root) 
{ 
    
    Node *current = root; 
  
    /* loop down to find the leftmost leaf */
    while (current->left != nullptr) 
        current = current->left; 
  
    return current; 
} 
void Tree::searchData(Node* &curr, int data, Node* &parent)
{
	// traverse the tree and search for the key
	while (curr != nullptr && curr->data != data)
	{
		// update parent node as current node
		parent = curr;

		// if given key is less than the current node, go to left subtree
		// else go to right subtree
		if (data < curr->data)
			curr = curr->left;
		else
			curr = curr->right;
	}
}
void Tree::deleteNode(Node * &root, int data){
	
	if(contains(root,data)==false)
		throw std::invalid_argument("a runtime error");



// base case 
  
	// pointer to store parent node of current node
	Node* parent = nullptr;

	// start with root node
	Node* curr = root;

	// search key in BST and set its parent pointer
	searchData(curr, data, parent);

	// return if key is not found in the tree
	if (curr == nullptr)
		return;

	// Case 1: node to be deleted has no children i.e. it is a leaf node
	if (curr->left == nullptr && curr->right == nullptr)
	{
		// if node to be deleted is not a root node, then set its
		// parent left/right child to null
		if (curr != root)
		{
			if (parent->left == curr)
				parent->left = nullptr;
			else
				parent->right = nullptr;
		}
		// if tree has only root node, delete it and set root to null
		else
			root = nullptr;

		// deallocate the memory
		delete curr;	 
	}

	// Case 2: node to be deleted has two children
	else if (curr->left && curr->right)
	{
		// find its in-order successor node
		Node* successor = minValueNode(curr->right);

		// store successor value
		int val = successor->data;

		// recursively delete the successor. Note that the successor
		// will have at-most one child (right child)
		deleteNode(root, successor->data);

		// Copy the value of successor to current node
		curr->data = val;
	}

	// Case 3: node to be deleted has only one child
	else
	{
		// find child node
		Node* child = (curr->left)? curr->left: curr->right;

		// if node that should removed is not a root node, then set its parent
		// to its child
		if (curr != root)
		{
			if (curr == parent->left)
				parent->left = child;
			else
				parent->right = child;
		}

		// if node to be deleted is root node, then set the root to child
		else
			root = child;

		// deallocate the memory
		delete curr;
	}
}

int Tree::size(Node *root){
	
	if(root==nullptr){
		return 0 ;
}
	else 
		return 1+size(root->left)+size(root->right);
}
bool Tree::contains(Node *root,int data){
	
  if (root == nullptr) {return false;}
  else {
    if (data == root->data)
        return true;
    else if (data < root->data)
             return contains(root->left, data);      
    else if (data > root->data)
             return contains(root->right, data);
    else
    	return false;	
  }

	
}
void Tree::deleteTree(Node *root) 
{
	
	
        if (!root)
                return;

        Node * curroot = root;
        Node * leftroot = root->left;
        Node * rightroot = root->right;
        delete curroot;
        deleteTree(leftroot);
        deleteTree(rightroot);
}
Tree::~Tree()
{

        deleteTree(_root);
}
int Tree::root(){
	
  if(_root==nullptr){throw std::invalid_argument("a runtime error");}
  return _root->data;
}

int Tree::parent(Node* root, int data)
{
	
    if(!contains(root,data)){ throw std::invalid_argument("a runtime error");}
    if((root->left == nullptr && root->right == nullptr) || (_root->data ==data))
       throw std::invalid_argument( "node has no parent" );
    int currentVal = root->data;	
    // if the root is the parent
    if( (root->left != nullptr && root->left->data == data)
        || (root->right != nullptr && root->right->data == data))
       return root->data;

    if(root->data > data)
       return parent(root->left,data);

    if(root->data < data)
       return parent(root->right,data);
    return currentVal;
}



int Tree::left(Node* root, int data){
	
   if(!contains(root,data)){
throw std::invalid_argument("a runtime error such node does not exist");}
   int currentVal = root->data;
    if(root->left != nullptr && root->data == data)
       return root->left->data;

    if(root->data > data)
       return left(root->left,data);

    if(root->data < data)
       return left(root->right,data);

    if(root->left == nullptr)
       {throw std::invalid_argument("a runtime error, no left child");};
 return currentVal;
}

int Tree::right(Node* root, int data){
	
 if(!contains(root,data)){
  throw std::invalid_argument("a runtime error, such node does not exist");
}
int currentVal = root->data;
     if(root->right != nullptr && root->data == data)
       return root->right->data;

     if(root->data > data)
       return right(root->left,data);

    if(root->data < data)
       return right(root->right,data);
 
    if(root->right == nullptr) {
throw std::invalid_argument("a runtime error");
         }
     
 return currentVal;
}
void Tree::print(Node *root){
	
   if (root != nullptr) {   
      print(root->left);
      cout<<root->data<<" ";
      print(root->right);
   }
 
}
};



