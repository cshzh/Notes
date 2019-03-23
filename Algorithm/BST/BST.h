//
// Created by hui on 19-3-23.
//

#ifndef BST_BST_H
#define BST_BST_H

#include <iostream>
#include <queue>
#include <stack>

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) : left(nullptr), right(nullptr) {
        this->data = data;
    }
};

class BST {
public:
    Node *root;

    // 插入节点
    void Add(int item);

    // 删除节点
    bool Delete(int item);

    // 中序遍历
    void Traverse();

    // 判断一颗树是不是二叉搜索树
    static bool IsBST(Node *root);

    static int Max(Node *root);

    static int Min(Node *root);

    virtual ~BST();
};


#endif //BST_BST_H
