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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root)
            return ret;
        vector<TreeNode*> zigzag;
        vector<int> tmpv;
        zigzag.push_back(root);
        int m=0;
        int n=0;
        int now=0;
        int l=0;
        while (now!=zigzag.size()){
            TreeNode* tmp = zigzag[now];
            if (tmp->left){
                zigzag.push_back(tmp->left);
                ++n;
            }
            if (tmp->right){
                zigzag.push_back(tmp->right);
                ++n;
            }
            tmpv.push_back(tmp->val);
            if (now==m){
                if (l%2==0){
                    ret.push_back(tmpv);
                    tmpv.clear();
                } else{
                    vector<int> p;
                    ret.push_back(p);
                    vector<int>& last= ret[ret.size()-1];
                    while (tmpv.size()>0){
                        last.push_back(tmpv[tmpv.size()-1]);
                        tmpv.pop_back();
                    }
                }
                ++l;
                m=n;
            }
            ++now;
        }
        return ret;
    }
};
