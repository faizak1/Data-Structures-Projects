/* Tree Operations */

#include <iostream>
#include <queue>
#include <stack>

using namespace std;
 
class Node{
public:
    Node* leftChild;
    Node* rightChild;
    int data;
    Node() {};
    Node(int data);
};
 
Node::Node(int data) {
    leftChild = nullptr;
    this->data = data;
    rightChild = nullptr;
}
 
class Tree{
private:
    Node* root;
public:
    Tree();
    ~Tree();
    void Preorder(Node* p);
    void Preorder() { Preorder(root); }
    void Inorder(Node* p);
    void Inorder() { Inorder(root); }
    void Postorder(Node* p);
    void Postorder() { Postorder(root); }
    Node* generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd);
    int Height(Node* p);
    int Height() { return Height(root); }
    int Count(Node* p);
    int Count(){ Count(root); }
    int Sum(Node* p);
    int Sum(){ Sum(root); }
    int deg2NodeCount(Node* p);
    int deg2NodeCount(){ deg2NodeCount(root); }
    int leafNodeCount(Node* p);
    int deg1NodeCount(Node* p);
    void DestroyTree(Node* p);
};
 
Tree::Tree() {
    root = nullptr;
}
 
Tree::~Tree() {
    DestroyTree(root);
}
 
void Tree::Preorder(Node *p) {
    if (p){
        cout << p->data << ", ";
        Preorder(p->leftChild);
        Preorder(p->rightChild);
    }
}
 
void Tree::Inorder(Node *p) {
    if (p){
        Inorder(p->leftChild);
        cout << p->data << ", ";
        Inorder(p->rightChild);
    }
}
 
void Tree::Postorder(Node *p) {
    if (p){
        Postorder(p->leftChild);
        Postorder(p->rightChild);
        cout << p->data << ", ";
    }
}
 
int searchInorder(int inArray[], int inStart, int inEnd, int data){
    for (int i=inStart; i<=inEnd; i++){
        if (inArray[i] == data){
            return i;
        }
    }
    return -1;
}
 
Node* Tree::generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd) {
    static int preIndex = 0;
 
    if (inStart > inEnd){
        return nullptr;
    }
 
    Node* node = new Node(preorder[preIndex++]);
    if (inStart == inEnd){
        return node;
    }
 
    int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
    node->leftChild = generateFromTraversal(inorder, preorder, inStart, splitIndex-1);
    node->rightChild = generateFromTraversal(inorder, preorder, splitIndex+1, inEnd);
 
    return node;
}
int Tree::Height(Node *p) {
    int l = 0;
    int r = 0;
 
    if (p != nullptr){
        l = Height(p->leftChild);
        r = Height(p->rightChild);
        if (l > r){
            return l + 1;
        } else {
            return r + 1;
        }
    }
    return 0;
}
 
int Tree::Count(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = Count(p->leftChild);
        y = Count(p->rightChild);
        return x + y + 1;
    }
    return 0;
}
 
int Tree::Sum(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = Sum(p->leftChild);
        y = Sum(p->rightChild);
        return x + y + p->data;
    }
    return 0;
}
 
int Tree::deg2NodeCount(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = deg2NodeCount(p->leftChild);
        y = deg2NodeCount(p->rightChild);
        if (p->leftChild && p->rightChild){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}
 
int Tree::leafNodeCount(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = leafNodeCount(p->leftChild);
        y = leafNodeCount(p->rightChild);
        if (p->leftChild == nullptr && p->rightChild == nullptr){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}
 
int Tree::deg1NodeCount(Node *p) {
    int x;
    int y;
    if (p != nullptr){
        x = deg1NodeCount(p->leftChild);
        y = deg1NodeCount(p->rightChild);
        if (p->leftChild != nullptr ^ p->rightChild != nullptr){
            return x + y + 1;
        } else {
            return x + y;
        }
    }
    return 0;
}
 
void Tree::DestroyTree(Node *p) {
    if (p != nullptr){
        DestroyTree(p->leftChild);
        DestroyTree(p->rightChild);
        delete p;
    }
}
 
int main() {
 
    Tree binary_tree;
 
    int preorder[] = {10,5,3,1,4,7,6,9,15,12,11,16};
    int inorder[] = {1,3,4,5,6,7,9,10,11,12,15,16};
 
    int size = sizeof(inorder)/sizeof(inorder[0]);

    Node* T = binary_tree.generateFromTraversal(inorder, preorder, 0, size-1);
    cout << "Preorder Traversal: ";
    binary_tree.Preorder(T);
    cout << endl;
    cout << "Inorder Traversal: ";
    binary_tree.Inorder(T);
    cout << endl;
    cout << "Postorder Traversal: ";
    binary_tree.Postorder(T);
    cout << endl;
    cout << "Height: " << binary_tree.Height(T) << endl;
    cout << "Sum of Node Values: " << binary_tree.Sum(T) << endl;
    cout << "Number of Degree 2 Nodes: " << binary_tree.deg2NodeCount(T) << endl;
    cout << "Number of Degree 1 Nodes: " << binary_tree.deg1NodeCount(T) << endl;
    cout << "Number of Leaf Nodes: " << binary_tree.leafNodeCount(T) << endl;
 
    binary_tree.DestroyTree(T);
    return 0;
}
