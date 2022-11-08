#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *left;
    Node *middle;
    Node *right;
    
}

int main(){
    Node *root = nullptr;
    root->data  = 1;
    root->right->data  = 4;
    root->middle->data  = 3;
    root->middle->left  = nullptr;
    root->middle->middle = nullptr;
    root->middle->right  = nullptr;
    root->left->data  = 2;
    root->left->left->data  = 5;
    root->left->left->left->data  = 9;
    root->left->left->middle->data  = 10;
    root->left->left->right  = nullptr;
    root->left->middle->data  = 6;
    root->left->middle->left = nullptr;
    root->left->middle->middle  = nullptr;
    root->left->middle->right = nullptr;
    root->left->right=nullptr;
    root->right->data  = 4;
    root->right->right->data  = 8;
    root->right->middle->data  = 8;
    root->middle->data  = 4;
    root->left->data  = 2;

    return 0;
}