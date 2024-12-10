#include"Node.h"
using namespace std;

Node::Node(int k)
: data(k), weight(1), lchild(nullptr), rchild(nullptr){}



Node* Node::insertR(int k) {
    if(this==nullptr){
        return new Node(k);
    }
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
        return new Node(k);
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

Node* Node::searchI(int k){

       Node* current = this;
     
    while (current != nullptr) {
        if (k == current->data) {
            return this;

        } else if (k < current->data) {
            
            current = current->lchild;
        } else {
            current = current->rchild;
        }
    }
    return nullptr;
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

void Node::preOrder(){

    cout << data << " "; 
        if (lchild != nullptr){
        lchild->preOrder();
    }
        
    if (rchild != nullptr){ 
        rchild->preOrder(); 
    }
}

void Node::postOrder(){
      
        if (lchild != nullptr){
        lchild->preOrder();
    }
        
    if (rchild != nullptr){ 
        rchild->preOrder(); 
    }
      cout << data << " "; 
}

bool Node::isBst(){

    if (this==nullptr){
        return true;
    }
    if(rchild==nullptr){
        return false;
    }else if(rchild->data>data){
        rchild->isBst();
    }


      if(lchild==nullptr){
        return false;
    }else if(lchild->data<data){
        lchild->isBst();
    }
    }



Node* Node::deleteNode(int k) {
    if (k < data) {
        if (lchild != nullptr) {
            lchild = lchild->deleteNode(k);
        }
    } else if (k > data) {
        if (rchild != nullptr) {
            rchild = rchild->deleteNode(k);
        }
    } else {
        if (lchild==nullptr && rchild==nullptr) {
            delete this;
            return nullptr;

        } else if (lchild == nullptr) {
            Node* t = rchild;
            delete this;
            return t;

        } else if (rchild == nullptr) {
            Node* t = lchild;
            delete this;
            return t;

        } else {
            Node* minNode = rchild;
            while (minNode->lchild != nullptr) {
                minNode = minNode->lchild;
            }
            data = minNode->data;  
            rchild = rchild->deleteNode(minNode->data); 
        }
    }
    return this;
}