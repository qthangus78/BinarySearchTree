#include <iostream>
#include <queue>
#include <map>
#include "operators.h"
using namespace std;

void insert(node& root, int key){
    node tmp=new Node(key);
    if(!root){
        root=tmp;
        return;
    }
    node parent=nullptr;
    node curr=root;
    while(curr){
        parent=curr;
        if(parent->data>key) curr=parent->left;
        else if(parent->data<key) curr=parent->right;
        else return;
    }
    if(parent->data<key) parent->right=tmp;
    else parent->left=tmp;
}

node searchkey(node& root, int key){
    if(!root) return nullptr;
    node parent = nullptr;
    node curr = root;
    while(curr){
        parent=curr;
        if(parent->data>key) curr=parent->left;
        else if(parent->data<key) curr=parent->right;
        else return parent;
    }
    return nullptr;
}

void deletionBST(node& root, int key){
    if(!root) return;
    if(root->data<key) deletionBST(root->right,key);
    else if(root->data>key) deletionBST(root->left,key);
    else{
        if(!root->left){
            node tmp = root;
            root=root->right;
            delete tmp;
        }
        else if(!root->right){
            node tmp = root;
            root=root->left;
            delete tmp;
        }
        else{
            node tmp = root->left;
            node prev=tmp->right;
            while(prev){
                tmp=prev;
                prev=prev->right;
            }
            tmp->right=root->right;
            node cur = root;
            root=root->left;
            delete cur;
        }
    }
}

void printlevelk(node& root, int k){
    if(!root) return;
    if(k==1){
        cout << root->data << " ";
        return;
    }
    printlevelk(root->left,k-1);
    printlevelk(root->right,k-1); 
}

void inorder(node& root){
    if(!root) 
    {
    inorder(root->left);
    cout << root->data;
    inorder(root->left);
    }
}
// khong thi su dung stack

void preorder(node& root){
    if(!root) return;
    cout << root->data;
    if(root->left) preorder(root->left);
    if(root->right) preorder(root->right);
}

void postorder(node& root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data;
}

void floorx(node& root, int& floor, int x){
    if(!root) return;
    if(root->data>x) floorx(root->left,floor,x);
    else if(root->data==x){
        floor = root->data;
        return;
    } 
    else{
        floor=root->data;
        floorx(root->right,floor,x);
    }
}

node findClosest(node root, int x) {
    if(root == nullptr) return nullptr;
    if(root->data < x) {
        if(!root->right) return root;
        if(root->right->data > x) {
            return ((x - root->data) < (root->right->data - x)) ? root : root->right;
        }
        return findClosest(root->right, x);  
    }
    else if(root->data > x) {
        if(!root->left) return root;
        if(root->left->data < x) {
            return ((x - root->data) < (x - root->left->data)) ? root : root->left;
        }
        return findClosest(root->left, x); 
    }
    else return root;
}

void printFollowLevel(node root){
    if(!root) return;
    queue<node>q;
    q.push(root);
    while(!q.empty()){
        node tmp = q.front();
        q.pop();
        cout << tmp->data << " ";
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }
}
// Để xử lí các node theo thứ tự level thì ta sẽ sử dụng phương pháp BFS
//Sử dụng trong các bài xử lí node theo thứ tự level, các node phía trên rồi mới tới các node phía dưới

void topViewFromRoot(node root){
    map<int, int> mp;
    queue<pair<node, int>> q;
    q.push({root, 0});
    while(!q.empty()){
        auto tmp = q.front();
        q.pop();
        if(mp.find(tmp.second) == mp.end()){
            mp[tmp.second] = tmp.first->data;
        }
        if(tmp.first->left)
            q.push({tmp.first->left, tmp.second - 1});
        if(tmp.first->right)
            q.push({tmp.first->right, tmp.second + 1});
    }
    for(auto u : mp){
        cout << u.second << " ";  
    }
}

void sumofksmallest(node root, int& k, int& result){
    if(root->left) sumofksmallest(root->left,k,result);
    if(k>0){
        k--;
        result+=root->data;
    }
    else return;
    if(root->right) sumofksmallest(root->right,k,result);
}
