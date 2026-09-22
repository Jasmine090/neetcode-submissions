/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* p1 = list1;
        ListNode* p2 = list2;
        ListNode* head = NULL;
        ListNode* prev = NULL;
        while(p1 && p2){
            ListNode* tmp = NULL;
            if(p1->val <= p2->val){
                tmp = p1;
                p1 = p1->next;
            }else{
                tmp = p2;
                p2 = p2->next;
            } 
            if(!head){
                head = tmp;
                prev = tmp;
                tmp->next = NULL;
            }else{
                prev->next = tmp;
                tmp->next = NULL;
                prev = tmp;
            }
        }
        if(p1) 
            if(!prev) head = p1;
            else prev->next = p1;
        if(p2)
            if(!prev) head = p2;
            else prev->next = p2;
        return head;
    }
};
