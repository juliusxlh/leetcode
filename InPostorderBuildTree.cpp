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
    TreeNode* dfs(int lp,int rp,int li,int ri,vector<int>& postorder, vector<int>& inorder){
        if (rp<lp ||ri<li)
            return nullptr;
        TreeNode* p = new TreeNode(postorder[rp]);
        int pos = iposmap[postorder[rp]];
        p->left = dfs(lp,lp+(pos-li-1),li,pos-1,postorder,inorder);
        p->right = dfs(rp-(ri-pos),rp-1,pos+1,ri,postorder,inorder);
        return p;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        iposmap.clear();
        for (int i=0;i!=inorder.size();i++)
            iposmap[inorder[i]]=i;
        return dfs(0,postorder.size()-1,0,inorder.size()-1,postorder,inorder);
    }
};
