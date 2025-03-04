#include "bstLink.cpp"

// Part A
/*
    0:  quit
    1:  insert
    -1: delete
    2:  search
    3:  preorder
    4:  inorder
    5:  postorder
    7:  print # of nodes in tree
    8:  print height of tree
    9:  print which side is bigger
*/

void menu(){
    cout << "1: Insert" << endl;
    cout << "-1: Delete" << endl;
    cout << "2: Search" << endl;
    cout << "3: Preorder" << endl;
    cout << "4: Inorder" << endl;
    cout << "5: Postorder" << endl;
    cout << "7: # of Nodes" << endl;
    cout << "8: Height" << endl;
    cout << "9: Bigger Side" << endl;
}

int main(){
    bstree t;

    t.insert(1);
    t.in();

    return 0;
}