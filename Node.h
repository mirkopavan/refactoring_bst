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
    Node(int key);

    Node* insertR(int k);

    void inOrder();
};

#endif