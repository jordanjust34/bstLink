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
    root = makeatreenode(0);
    
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

    post(root);

    cout << endl;
}

void bstree::post(treenode* root){
    if(root == NULL){
        return;
    }
    
    post(root->lchild);
    post(root->rchild);
    cout << root->data << " ";
}

void bstree::insert(int x){
    insert(x, root);
}

void bstree::insert(int x, treenode* root){
    if(root->data == 0){
        root->data = x;
        return;
    }

    if(root->data == x){
        return;
    }

    if(x < root->data){
        if(root->lchild == NULL){
            root->lchild = makeatreenode(x);
        }else{
            insert(x, root->lchild);
        }
    }else if(x > root->data){
        if(root->rchild == NULL){
            root->rchild = makeatreenode(x);
        }else{
            insert(x, root->rchild);
        }
    }
}

void bstree::remove(int x){

}

bool bstree::search(int x){
    return search(x, root);
}

bool bstree::search(int x, treenode* root){
    if(root == NULL){
        cout << "No" << endl;
        return false;
    }

    if(x == root->data){
        cout << "Yes" << endl;
        return true;
    }

    if(x < root->data){
        search(x, root->lchild);
    }else{
        search(x, root->rchild);
    }

    return false;
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
    return 0;
}

char bstree::bigger(){
    return bigger(root);
}

char bstree::bigger(treenode* root){
    return 'a';
}