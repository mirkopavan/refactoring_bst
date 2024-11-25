#include"Node.h"
using namespace std;

Node::Node(int key)
: data(key), weight(1), lchild(nullptr), rchild(nullptr){}



Node* Node::insertR(int key) {
    if(key==data){
        weight++;
        return this;
    }else if (key < data) {
        if (lchild == nullptr){
            lchild = new Node(key);
        }else{
            lchild=lchild->insertR(key);
        }
    
    }else{ 
        if (rchild == nullptr){
            rchild = new Node(key);
        }else{
            rchild=rchild->insertR(key);
        }
    }
    return this;
}

void Node::inOrder() {

    if (lchild != nullptr){
        lchild->inOrder();
        }
        
    cout << data << " ";                      
    
    if (rchild != nullptr){ 
        rchild->inOrder(); 
        }
        
}