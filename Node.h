#ifndef NODE_H
#define NODE_H

#include<iostream>
using namespace std;

class Node{
private:
    int data;
    int weight;
    Node* lchild;
    Node* rchild;

public:
    Node(int k);
    Node* insertR(int k);
    Node* insertI(int k);
    Node* searchR(int k);
    Node* searchI(int k);
    void inOrder();
    void postOrder();
    void preOrder();
    bool isBst();
    Node* deleteNode(int k); 
    friend istream& operator>>(istream& is, Node& n);
    friend ostream& operator<<(ostream& os, const Node& n);
};

#endif