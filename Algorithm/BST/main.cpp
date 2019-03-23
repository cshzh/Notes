#include <iostream>
#include "BST.h"

int main() {
    BST bst;

    bst.Add(20);
    bst.Add(10);
    bst.Add(21);
    bst.Add(9);
    bst.Add(11);

    bst.Traverse();

    bst.Delete(10);

    bst.Traverse();

    std::cout << BST::IsBST(bst.root) << std::endl;

    return 0;
}