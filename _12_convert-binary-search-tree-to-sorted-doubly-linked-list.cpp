/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node *first = nullptr;
    Node *last = nullptr;
    
    void recur(Node *root) {
        if (!root) return ;
        recur(root->left);
        if (last) {
            last->right = root;
            root->left = last;
        } else {
            first = root;
        }
        last = root;
        recur(root->right);

    }
    
    Node* treeToDoublyList(Node* root) {
        if (!root) return nullptr;

        recur(root);
        last->right = first;
        first->left = last;
        return first;
    }
};
