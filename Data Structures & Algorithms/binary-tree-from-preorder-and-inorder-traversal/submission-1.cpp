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
    unordered_map<int, int> container;
    int st = 0;

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i = 0; i<n; i++){
            container.insert({inorder[i], i});
        }
        
        return dfs(preorder, 0, n-1);
    }

    TreeNode* dfs(vector<int>& preorder, int l, int r){
        if(l > r){
            return nullptr;
        }

        int rootval = preorder[st++];
        int mid = container[rootval];
        
        TreeNode* root = new TreeNode(rootval);

        root->left = dfs(preorder, l, mid-1);
        root->right = dfs(preorder, mid+1, r);
        return root;
    }
};

