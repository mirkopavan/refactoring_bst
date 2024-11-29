#include"Node.h"
using namespace std;

Node::Node(int k)
: data(k), weight(1), lchild(nullptr), rchild(nullptr){}



Node* Node::insertR(int k) {
    if(k==data){
        weight++;
        return this;
    }else if (k < data) {
        if (lchild == nullptr){
            lchild = new Node(k);
        }else{
            lchild=lchild->insertR(k);
        }
    
    }else{ 
        if (rchild == nullptr){
            rchild = new Node(k);
        }else{
            rchild=rchild->insertR(k);
        }
    }
    return this;
}

Node* Node::insertI(int k){
    if(this==nullptr){
        return this;
    }

    Node* current=this;

    while (current!=nullptr)
    {
        if(k>current->data){
            if(current->rchild==nullptr){
                current->rchild=new Node(k);
                return this;
            }
            current=current->rchild;
        }else if(k<current->data){
            if(current->lchild==nullptr){
                current->lchild=new Node(k);
            }
            current=current->lchild;
        }else{
            current->weight++;
            return this;
        }
    }

    return this;
}


Node* Node::searchR(int k){
    if(this==nullptr){
        return this;
    }
    if(k==data){
        return this;
    }
    if(k<data){
        return lchild->searchR(k);
    }else{
        return rchild->searchR(k);
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