/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head==NULL) return head;
        ListNode* pre = head;
        ListNode* ppre = NULL;
        ListNode* p = head->next;
        bool flag=true;
        while (p!=NULL){
            if (p->val!=pre->val){
                if (flag){
                    ppre = pre;
                    pre->next=p;
                    pre = p;
                    p=p->next;
                    pre->next=NULL;
                } else {
                    pre->val = p->val;
                    p=p->next;
                    pre->next=NULL;
                    flag=true;
                }
            } else{
                flag=false;
                p=p->next;
            }
        }
        if (!flag)
        {
            if (pre==head) return NULL;
            ppre->next = NULL;
            return head;
        }
        return head;
    }
};
