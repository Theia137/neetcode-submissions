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
    stack<TreeNode*> stk;
    TreeNode* curr;
    vector<int> ans;

    vector<int> inorderTraversal(TreeNode* root) {
        curr = root;
        if(curr == nullptr){
            return ans;
        }

        while(!stk.empty() || curr!=nullptr){
            if(curr!=nullptr){
                stk.push(curr);
                curr = curr->left;
            }
            else{
                ans.push_back(stk.top()->val);
                curr = stk.top()->right;
                stk.pop();
            }

        }
        return ans;
    }
};