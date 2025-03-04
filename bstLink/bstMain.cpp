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
    cout << "0: Close Program" << endl;
}

int main(int argc, char* argv[]){
    bstree t;
    string line;

    if(argc != 2){
        cerr << "Usage: " << argv[0] << "<BSTCommandFile>" << endl;
        return 1;
    }

    ifstream commandFile(argv[1]);

    if(!commandFile.is_open()){
        cerr << "Unable to open file" << argv[1] << endl;
        return 1;
    }

    while(getline(commandFile, line)){
        stringstream ss(line);
        int mode, x;
        ss >> mode;

        switch (mode){
            case 1:
                ss >> x;
                t.insert(x);
                break;

            case 2:
                ss >> x;
                t.search(x);
                break;

            case 3:
                t.pre();
                break;

            case 4:
                t.in();
                break;

            case 5:
                t.post();
                break;

            case 7:
                t.numnodes();
                break;

            case 8:
                t.height();
                break;

            case 9:
                t.bigger();
                break;

            case 0:
                return 0;
                break;

            default:
                cout << "please input the listed numbers." << endl;
                break;
        }
    }

    return 0;
}