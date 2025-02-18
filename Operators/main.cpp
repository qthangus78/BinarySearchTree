#include <iostream>
using namespace std;
#include "operators.h"

int main(){
    node root = new Node(10);
    insert(root,5);
    insert(root,2);
    insert(root,15);
    insert(root,20);
    insert(root,25);
    insert(root,30);
    getSubnode(root);
    BinaryBalanced(root);
    preorder(root);
}




    
