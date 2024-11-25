#include<iostream>
using namespace std;

struct node {
    int key;
    node* lchild;
    node* rchild;         
    node(int value) {
        key = value;     
        lchild = nullptr;  
        rchild = nullptr;  
    }
};



node* insert(node* root, int key) {
    if (root == nullptr) {
        return new node(key);
    }

    if (key < root->key) {
        root->lchild = insert(root->lchild, key); 
    }
   
    else if (key > root->key) {
        root->rchild = insert(root->rchild, key); 
    }
    return root;
}



node* search(node* root, int key) {
   
    if (root == nullptr || key == root->key) {
        return root;  
    }

   
    if (key < root->key) {
        return search(root->lchild, key);  
    } else if (key > root->key) {
        return search(root->rchild, key);  
    }

    return nullptr;
}

void inorder(node* root) {
if (root == nullptr) {
return; 
}
inorder(root->lchild);
cout << root->key << " ";
inorder(root->rchild);
}


void preorder(node* root) {
if (root == nullptr) {
return; 
}
cout << root->key << " ";
preorder(root->lchild);
preorder(root->rchild);
}

void postorder(node* root) {
if (root == nullptr) {
return; 
}
postorder(root->lchild);

postorder(root->rchild);

cout << root->key << " ";
}



node* delete_l(node* root, int key) {
if (root == nullptr) {
return nullptr; 
}

if (key < root->key) {
root->lchild = delete_l(root->lchild, key); 
} else if (key > root->key) {
root->rchild = delete_l(root->rchild, key);
} else {

if (root->lchild == nullptr && root->rchild == nullptr) {

delete root; 
return nullptr;
}
}
return root; 
}



node* delete_whitchild(node* root, int key) {
if (root == nullptr) {
return nullptr; 
}

if (key < root->key) {
root->lchild = delete_whitchild(root->lchild, key); 
} else if (key > root->key) {
root->rchild = delete_whitchild(root->rchild, key);
} else {if (root->lchild == nullptr && root->rchild == nullptr) {
delete root; 
return nullptr;
}

if (root->lchild == nullptr) { 
node* temp = root->rchild;
delete root; 
return temp; 
} else if (root->rchild == nullptr) { 
node* temp = root->lchild;
return temp; 
}
}
return root;
}

bool is_bst(node* node){
    if(node == NULL) return true;

    if((  node->lchild->key < node->key && node->lchild != NULL) && (node->rchild != NULL && node->rchild->key > node->key)){
        is_bst(node->lchild);
        is_bst(node->rchild);
    }else{
        return false;
    }

    return true;
}


int height(node* root){
    if(root == NULL) return 0;

    int hleft = height(root->lchild);
    int hright = height(root->rchild);
if(hleft>hright){
    return 1+hleft;

}else{
    return 1+hright;
}
}