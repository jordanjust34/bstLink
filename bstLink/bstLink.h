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
        bstree();
        void in();
        void pre();
        void post();
        void insert(int x);
        void remove(int x);
        bool search(int x);
        int numnodes();
        int height();
    private:
        void in(treenode* root);
        void pre(treenode* root);
        void post(treenode* root);
        void insert(int x, treenode* root);
        bool search(int x, treenode* root);
        int numnodes(treenode* root);
        int height(treenode* root);
        treenode* root;
};