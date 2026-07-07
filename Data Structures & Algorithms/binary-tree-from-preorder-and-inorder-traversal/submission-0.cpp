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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        if(n == 0){
            return nullptr;
        }

        unordered_map<int, int> container;
        for(int i = 0; i<n; i++){
            container.insert({inorder[i], i});
        }
        int rootval = preorder[0];
        int rootidx = container[rootval];
        int leftnum = rootidx;
        int rightnum = n - leftnum - 1;
        
        TreeNode* root = new TreeNode(rootval);
        vector<int> preorderleft(preorder.begin()+1, preorder.begin()+1+leftnum);
        vector<int> preorderright(preorder.begin()+1+leftnum, preorder.begin()+n);
        vector<int> inorderleft(inorder.begin(), inorder.begin()+leftnum);
        vector<int> inorderright(inorder.begin()+1+leftnum, inorder.begin()+n);

        root->left = buildTree(preorderleft, inorderleft);
        root->right = buildTree(preorderright, inorderright);

        return root;
    }
};

