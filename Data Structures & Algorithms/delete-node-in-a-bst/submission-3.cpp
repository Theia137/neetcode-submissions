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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return root;
        }
        else if(root->val == key){
            if(root->right == nullptr){
                root = root->left;
            }
            else if(root->left == nullptr){
                root = root->right;
            }
            else{
                TreeNode* newnode = findminNode(root->right);
                root->val = newnode->val;
                root->right = deleteNode(root->right, newnode->val);
            }
        }
        else if(root->val < key){
            root->right = deleteNode(root->right, key);
        }
        else{
            root->left = deleteNode(root->left, key);
        }
        return root;
    }

    TreeNode* findminNode(TreeNode* node){
        if(node == nullptr){
            return nullptr;
        }
        else{
            if(node->left == nullptr){
                return node;
            }
            else{
                return findminNode(node->left);
            }
        }
    }
};