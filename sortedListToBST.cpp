/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    private:
    int deep=0;
    ListNode* p;
    TreeNode* buildTree(int l,int r){
        if (r<l)
            return nullptr;
        int mid = (l+r)/2;
        TreeNode* q = new TreeNode(0);
        q->left = buildTree(l,mid-1);
        q->val = p->val;
        p = p->next;
        q->right = buildTree(mid+1,r);
        return q;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head) {
        p = head;
        deep=0;
        while (p!=nullptr){
            ++deep;
            p=p->next;
        }
        p = head;
        return buildTree(0,deep-1);
    }
};
