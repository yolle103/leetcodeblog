#include<iostream>
#include<stdio.h>
using namespace std;
/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(ContainOne(root))
            return root;
        else
            return NULL;
    }
    bool ContainOne(TreeNode * node){
        if(node == NULL)
            return false;
        bool l = ContainOne(node->left);
        bool r = ContainOne(node->right);
        if(!l)
            node->left = NULL;
        if(!r)
            node->right = NULL;
        return (node->val == 1) || l || r;
    }
};
