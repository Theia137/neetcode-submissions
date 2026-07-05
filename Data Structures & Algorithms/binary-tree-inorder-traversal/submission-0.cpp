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
    vector<int> answer;

    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr){
            return answer;
        }
        else{
            traversal(root);
        }
        return answer;
    }

    void traversal(TreeNode* root){
        if(root == nullptr){
            
        }
        if(root->left == nullptr && root->right == nullptr){
            answer.push_back(root->val);
        }
        else{
            if(root->left != nullptr){
                traversal(root->left);
            }
            answer.push_back(root->val);
            if(root->right != nullptr){
                traversal(root->right);
            }
        }
    }
};