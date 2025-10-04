#include <iostream>

using namespace std;

class Node {
private:
    int data;
    Node* left;
    Node* right;
    Node* parent;
    int colour; // 0 - black, 1 - red

    friend class Tree;
public:
    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        colour = 1;
    }

    bool operator<(Node* oth) const {
        return (this->data < oth->data);
    }
};

class Tree {
private:
    Node* root;
    bool ll; // Left-Left Rotation flag
    bool rr; // Right-Right Rotation flag
    bool lr; // Left-Right Rotation flag
    bool rl; // Right-Left Rotation flag
public:
    Tree() {
        root = nullptr;
        ll = false;
        rr = false;
        lr = false;
        rl = false;
    }
    ~Tree() {
        clear(root);
    }
    void clear(Node* node) {
        if (node->left != nullptr)
            clear(node->left);
        if (node->right != nullptr)
            clear(node->right);
        delete node;
    }

    Node* rotate_left(Node* node) {
        Node* x = node->right;
        Node* y = x->left;
        x->left = node;
        node->right = y;
        node->parent = x;
        if (y != nullptr)
            y->parent = node;
        return x;
    }

    Node* rotate_right(Node* node) {
        Node* x = node->left;
        Node* y = x->right;
        x->right = node;
        node->left = y;
        node->parent = x;
        if (y != nullptr)
            y->parent = node;
        return x;
    }

    Node* recursive_add(Node* node, Node* new_node) {
        bool f = false; // Flag to check RED-RED conflict

        if (node == nullptr)
            return new_node;
        if (new_node->data < node->data) {
            node->left = recursive_add(node->left, new_node);
            node->left->parent = node;
            if (node != this->root) {
                if (node->colour == 1 && node->left->colour == 1)
                    f = true;
            }
        } else {
            node->right = recursive_add(node->right, new_node);
            node->right->parent = node;
            if (node != this->root) {
                if (node->colour == 1 && node->right->colour == 1)
                    f = true;
            }
        }


        if (ll) {
            node = rotate_left(node);
            node->colour = 0;
            node->left->colour = 1;
            ll = false;
        } else if (rr) {
            node = rotate_right(node);
            node->colour = 0;
            node->right->colour = 1;
            rr = false;
        } else if (rl) {
            node->right = rotate_right(node->right);
            node->right->parent = node;
            node = rotate_left(node);
            node->colour = 0;
            node->left->colour = 1;
            rl = false;
        } else if (lr) {
            node->left = rotate_left(node->left);
            node->left->parent = node;
            node = rotate_right(node);
            node->colour = 0;
            node->right->colour = 1;
            lr = false;
        }

        // Handle RED-RED conflicts
        normalize(f, node);
        return node;
    }
    void normalize(bool f, Node* node) {
        if (f) {
            if (node->parent->right == node) {
                if (node->parent->left == nullptr || node->parent->left->colour == 0) {
                    if (node->left != nullptr && node->left->colour == 1)
                        rl = true;
                    else if (node->right != nullptr && node->right->colour == 1)
                        ll = true;
                } else {
                    node->parent->left->colour = 0;
                    node->colour = 0;
                    if (node->parent != this->root)
                        node->parent->colour = 1;
                }
            } else {
                if (node->parent->right == nullptr || node->parent->right->colour == 0) {
                    if (node->left != nullptr && node->left->colour == 1)
                        rr = true;
                    else if (node->right != nullptr && node->right->colour == 1)
                        lr = true;
                } else {
                    node->parent->right->colour = 0;
                    node->colour = 0;
                    if (node->parent != this->root)
                        node->parent->colour = 1;
                }
            }
            f = false;
        }
    }

    void add(const int data) {
        Node* new_node = new Node(data);
        if (root == nullptr) {
            root = new_node;
            root->colour = 0;
        }
        else
            root = recursive_add(root, new_node);
    }
};

int main() {
    Tree tree;
    int arr[] = {1, 4, 6, 3, 5, 7, 8, 2, 9};
    for (int i = 0; i < 9; i++) {
        tree.add(arr[i]);
    }
    return 0;
}
