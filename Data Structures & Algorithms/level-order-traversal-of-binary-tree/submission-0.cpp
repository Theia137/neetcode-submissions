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
    vector<vector<int>> ans;
    vector<int> floor;
    queue<pair<TreeNode*, int>> q;

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return ans;
        }
        else{
            int depth = 0;
            q.push({root, 0});
            while(!q.empty()){
                if(q.front().second == depth){
                    if(q.front().first != nullptr){
                        floor.push_back(q.front().first->val);
                        q.push({q.front().first->left, q.front().second + 1});
                        q.push({q.front().first->right, q.front().second + 1});
                        q.pop();
                    }
                    else{
                        q.pop();
                    }
                }
                else{
                    ans.push_back(floor);
                    floor.clear();
                    depth += 1;
                    if(q.front().first != nullptr){
                        floor.push_back(q.front().first->val);
                        q.push({q.front().first->left, q.front().second + 1});
                        q.push({q.front().first->right, q.front().second + 1});
                        q.pop();
                    }
                    else{
                        q.pop();
                    }
                }
            }
            return ans;
        }
    }
};
