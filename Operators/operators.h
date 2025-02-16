#pragma once
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int x){
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
typedef Node* node;

void insert(node& root, int key);
node searchkey(node& root, int key);
void deletionBST(node& root, int key);
void printlevelk(node& root, int k);
void inorder(node& root);
void preorder(node& root);
void postorder(node& root);
void floorx(node& root, int& floor, int x);
node findClosest(node root, int x);
void printFollowLevel(node root);
void topViewFromRoot(node root);
void sumofksmallest(node root, int& k, int& result);
void printKeyInGivenRange(node root, int smaller, int larger);
// Neu cho phep ban sao nua thi trong struct ta them bien count de dem so lan xuat hien