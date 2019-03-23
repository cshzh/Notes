//
// Created by hui on 19-3-23.
//

#include "BST.h"

void BST::Add(int item) {
    if (nullptr == this->root) {
        this->root = new Node(item);
    } else {
        Node *pCurNode = this->root;
        Node *pPreNode = this->root;

        while (pCurNode) {
            if (item < pCurNode->data) {
                pPreNode = pCurNode;
                pCurNode = pCurNode->left;
            } else if (item > pCurNode->data) {
                pPreNode = pCurNode;
                pCurNode = pCurNode->right;
            } else {
                return;
            }
        }

        if (pPreNode->data < item) {
            pPreNode->right = new Node(item);
        } else {
            pPreNode->left = new Node(item);
        }
    }
}

// 非递归实现
bool BST::Delete(int item) {
    if (nullptr != root) {
        Node *pCurNode = root;
        Node *pPreNode = nullptr;

        while (pCurNode) {
            if (item > pCurNode->data) {
                pPreNode = pCurNode;
                pCurNode = pCurNode->right;
            } else if (item < pCurNode->data) {
                pPreNode = pCurNode;
                pCurNode = pCurNode->left;
            } else {
                break;
            }
        }

        // can't find
        if (nullptr == pCurNode) {
            return false;
        }

        if (!pCurNode->right) {
            // right tree is null

            if (nullptr == pPreNode) {
                // is root
                Node *old = this->root;

                root = root->left;
                delete old;
                old = nullptr;
            } else {
                // not root
                if (pPreNode->right == pCurNode) {
                    pPreNode->right = pCurNode->left;
                } else {
                    pPreNode->left = pCurNode->left;
                }

                delete pCurNode;
                pCurNode = nullptr;
            }
        } else if (!pCurNode->left) {
            // left tree is null

            if (nullptr == pPreNode) {
                // is root
                Node *old = this->root;

                root = root->right;
                delete old;
                old = nullptr;
            } else {
                // not root
                if (pPreNode->right == pCurNode) {
                    pPreNode->right = pCurNode->right;
                } else {
                    pPreNode->left = pCurNode->right;
                }

                delete pCurNode;
                pCurNode = nullptr;
            }

        } else {
            // both child isn't null

            // max item of left child tree
            Node *pMaxNode = pCurNode->left;
            Node *pParentMaxNode = pCurNode;

            while (pMaxNode->right) {
                pParentMaxNode = pMaxNode;
                pMaxNode = pMaxNode->right;
            }

            pCurNode->data = pMaxNode->data;

            //delete max value node of left tree

            if (pParentMaxNode == pCurNode) {
                pCurNode->left = pMaxNode->left;
            } else {
                pParentMaxNode->right = pMaxNode->left;
            }
            delete pMaxNode;
            pMaxNode = nullptr;
        }

        return true;

    }
    return false;
}

/**
 * 中序遍历非递归实现
 */
void BST::Traverse() {
    if (nullptr != root) {
        std::stack<Node *> stack;
        Node *pCurNode = root;

        while (!stack.empty() || pCurNode) {
            if (nullptr != pCurNode) {
                stack.push(pCurNode);
                pCurNode = pCurNode->left;
            } else {
                pCurNode = stack.top();
                std::cout << pCurNode->data << " ";
                stack.pop();

                pCurNode = pCurNode->right;
            }
        }

        std::cout << std::endl;
    }
}

bool BST::IsBST(Node *root) {
    if (nullptr == root) {
        return true;
    }

    int leftFlag = true, rightFlag = true;
    if (root->left) {
        leftFlag = Max(root->left) <= root->data;
    }
    if (root->right) {
        rightFlag = Min(root->right) >= root->data;
    }

    return IsBST(root->left) && IsBST(root->right) && leftFlag && rightFlag;
}


BST::~BST() {
    if (nullptr != root) {
        // 层次遍历实现
        std::queue<Node *> queue;

        queue.push(root);

        while (!queue.empty()) {
            if (queue.front()->left) {
                queue.push(queue.front()->left);
            }
            if (queue.front()->right) {
                queue.push(queue.front()->right);
            }
            delete queue.front();
            queue.pop();
        }
    }
}

int BST::Max(Node *root) {
    while (root->right) {
        root = root->right;
    }
    return root->data;
}

int BST::Min(Node *root) {
    while (root->left) {
        root = root->left;
    }
    return root->data;
}

