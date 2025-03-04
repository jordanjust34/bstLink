#include "bstlink.h"

// create a node for the tree
// adds the data to the node
// returns the node with it's data
treenode* makeatreenode(int x){
    treenode* box = new treenode;

    box->data = x;
    box->lchild = NULL;
    box->rchild = NULL;

    return box;
}

bstree::bstree(){
    root = new treenode;
}

void bstree::in(){
    cout << "Inorder: ";

    in(root);

    cout << endl;
}

void bstree::in(treenode* root){
    if(root == NULL){
        return;
    }

    in(root->lchild);
    cout << root->data << " ";
    in(root->rchild);
}

void bstree::pre(){
    cout << "Preorder: ";
    
    pre(root);

    cout << endl;
}

void bstree::pre(treenode* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " ";
    pre(root->lchild);
    pre(root->rchild);
}

void bstree::post(){
    cout << "Postorder: ";

    pre(root);

    cout << endl;
}

void bstree::post(treenode* root){
    if(root == NULL){
        return;
    }
    
    post(root->rchild);
    post(root->lchild);
    cout << root->data << " ";
}

void bstree::insert(int x){
    insert(x, root);
}

void bstree::insert(int x, treenode* root){
    
}

void bstree::remove(int x){

}

bool bstree::search(int x){
    return search(x, root);
}

bool bstree::search(int x, treenode* root){
    if(root == NULL){
        return false;
    }

    if(x == root->data){
        return true;
    }

    if(x < root->data){
        search(x, root->lchild);
    }else{
        search(x, root->rchild);
    }
}

int bstree::numnodes(){
    return numnodes(root);
}

int bstree::numnodes(treenode* root){
    if(root == NULL){
        return 0;
    }

    int leftNum, rightNum;
    leftNum = numnodes(root->lchild);
    rightNum = numnodes(root->rchild);

    return leftNum + rightNum + 1;
}

int bstree::height(){
    return height(root);
}

int bstree::height(treenode* root){
    
}