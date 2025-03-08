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

treenode* findMin(treenode* root){
    if(root == NULL){
        return root;
    }

    if(root->rchild != NULL){
        root = root->rchild;
    }

    while(root != NULL && root->lchild != NULL){
        root = root->lchild;
    }

    return root;
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
    remove(x, root);
}

treenode* bstree::remove(int x, treenode* root){
    if(root == NULL){
        return root;
    }

    if(x < root->data){
        root->lchild = remove(x, root->lchild);
    }else if(x > root->data){
        root->rchild = remove(x, root->rchild);
    }else{
        if(root->lchild == NULL){
            treenode* tmp = root->rchild;
            delete root;
            return tmp;
        }else if(root->rchild == NULL){
            treenode* tmp = root->lchild;
            delete root;
            return tmp;
        }

        treenode* min = findMin(root);
        root->data = min->data;
        root->rchild = remove(min->data, root->rchild);
    }
    return root;
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
    cout << numnodes(root) << endl;
    return numnodes(root);
}

int bstree::numnodes(treenode* root){
    if(root == NULL){
        return 0;
    }

    int leftNum = numnodes(root->lchild);
    int rightNum = numnodes(root->rchild);

    return leftNum + rightNum + 1;
}

int bstree::height(){
    cout << height(root) << endl;
    return height(root);
}

int bstree::height(treenode* root){
    if(root == NULL){
        return 0;
    }

    int leftH, rightH = 0;

    leftH = height(root->lchild) + 1;
    rightH = height(root->rchild) + 1;

    if(leftH > rightH){
        return leftH;
    }else{
        return rightH;
    }
}

char bstree::bigger(){
    cout << bigger(root) << endl;
    return bigger(root);
}

char bstree::bigger(treenode* root){
    if(root == NULL){
        return ' ';
    }

    int leftH, rightH = 0;

    leftH = height(root->lchild) + 1;
    rightH = height(root->rchild) + 1;

    if(leftH > rightH){
        return 'L';
    }else if(leftH < rightH){
        return 'R';
    }
    
    return 'E';
}