/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int number = nodenum(root->left);
        if(number < k-1){
            return kthSmallest(root->right, k-number-1);
        }
        else if(number == k-1){
            return root->val;
        }
        else{
            return kthSmallest(root->left, k);
        }
    }

    int nodenum(TreeNode* root){
        int ans = 0;
        if(root == nullptr){
            return 0;
        }
        else{
            return nodenum(root->left) + nodenum(root->right) + 1;
            return ans;
        }
    }
};
