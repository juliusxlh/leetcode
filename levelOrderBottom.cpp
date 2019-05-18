/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ret;
    int maxdeep;
    int getTreeDeep(TreeNode* root){
        if (root==nullptr)
            return 0;
        return max(getTreeDeep(root->left),getTreeDeep(root->right))+1;
        
    }
    
    void dfs(int deep,TreeNode* p){
        if (p==nullptr)
            return;
        dfs(deep+1,p->left);
        dfs(deep+1,p->right);
        ret[maxdeep-deep].push_back(p->val);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        ret.clear();
        maxdeep = getTreeDeep(root);
        for (int i=0;i!=maxdeep;i++)
            ret.push_back(vector<int>());
        dfs(1,root);
        return ret;
    }
};
