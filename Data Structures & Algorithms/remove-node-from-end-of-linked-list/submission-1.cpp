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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* tmp = head;
        while(tmp){
            sz++;
            tmp = tmp->next;
        }
        int target = sz-n+1;
        int ct = 1;
        ListNode* prev = new ListNode(-1);
        tmp = head;
        while(tmp){
            if(target==ct){
                prev->next = tmp->next;
                tmp->next = NULL;
                break;
            }
            ct++;
            prev = tmp;
            tmp = tmp->next;
        }
        if(ct==1) return prev->next;
        return head;
    }
};
