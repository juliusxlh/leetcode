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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lh=nullptr,*rt=nullptr;
        ListNode* lt=nullptr,*rh=nullptr;
        ListNode* p = head;
        while (p!=nullptr){

            if (p->val<x){
                if (lh==nullptr){

                    lh = p;
                    lt = p;
                    p=p->next;
                } else{

                    lt->next = p;
                    lt = lt->next;
                    p=p->next;
                }
            } else{
                if (rh==nullptr){

                    rh = p;
                    rt = p;
                    p=p->next;
                } else{

                    rt->next = p;
                    rt = rt->next;
                    p=p->next;
                }
            }
        }
        if (rt!=nullptr)rt->next = nullptr;
        if (lt==nullptr)
            return rh;
        else 
            lt->next=rh;
        return lh;
    }
};
