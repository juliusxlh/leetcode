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
    unordered_map<int,int> iposmap;
    TreeNode* dfs(int lp,int rp,int li,int ri,vector<int>& preorder, vector<int>& inorder){
        if (rp<lp ||ri<li)
            return nullptr;
        TreeNode* p = new TreeNode(preorder[lp]);
        int pos = iposmap[preorder[lp]];
        p->left = dfs(lp+1,lp+(pos-li),li,pos-1,preorder,inorder);
        p->right = dfs(rp-(ri-pos-1),rp,pos+1,ri,preorder,inorder);
        return p;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        iposmap.clear();
        for (int i=0;i!=inorder.size();i++)
            iposmap[inorder[i]]=i;
        return dfs(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder);
    }
};
