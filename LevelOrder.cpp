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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root)
            return ret;
        vector<int> tmp;
        tmp.push_back(root->val);
        ret.push_back(tmp);
        vector<TreeNode*> node[2];
        node[0].push_back(root);
        int l=0;
        do {
            tmp.clear();
            for (auto p: node[l%2]){
                if (p->left){
                    tmp.push_back(p->left->val);
                    node[(l+1)%2].push_back(p->left);
                }
                if (p->right){
                    tmp.push_back(p->right->val);
                    node[(l+1)%2].push_back(p->right);
                }
            }
            node[l%2].clear();
            ++l;
            if (tmp.size()==0)
                break;
            ret.push_back(tmp);
        }while(tmp.size()!=0);
        return ret;
    }
};
