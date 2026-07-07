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
    vector<int> ans;
    queue<TreeNode*> q;
    int maxval = -101;

    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr){
            return ans;
        }
        else{
            q.push(root);
            while(!q.empty()){
                int size = q.size();
                maxval = -101;
                for(int i=0; i<size; i++){
                    TreeNode* curr = q.front();
                    q.pop();
                    if(curr != nullptr){
                        maxval = curr->val;
                        q.push(curr->left);
                        q.push(curr->right);
                    }
                }
                if(maxval > -101){
                    ans.push_back(maxval);
                }
            }
            return ans;
        }
    }
};
