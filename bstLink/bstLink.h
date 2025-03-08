#include <iostream>
#include <fstream>
using namespace std;

struct treenode{
    int data;
    treenode* lchild;
    treenode* rchild;
};

class bstree{
    public:
        bstree();               //  DONE
        void in();              //  DONE
        void pre();             //  DONE
        void post();            //  DONE
        void insert(int x);     //  DONE
        void remove(int x);     //  TODO
        bool search(int x);     //  DONE
        int numnodes();         //  DONE
        int height();           //  DONE
        char bigger();          //  DONE
    private:
        void in(treenode* root);
        void pre(treenode* root);
        void post(treenode* root);
        void insert(int x, treenode* root);
        treenode* remove(int x, treenode* root);
        bool search(int x, treenode* root);
        int numnodes(treenode* root);
        int height(treenode* root);
        char bigger(treenode* root);
        treenode* root;
};