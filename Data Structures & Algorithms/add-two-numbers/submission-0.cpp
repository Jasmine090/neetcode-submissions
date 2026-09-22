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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* idx = new ListNode(0);
        ListNode* re = idx;
        while(l1 || l2 || carry){
            int a = 0;
            int b = 0;
            if(l1){
                a = l1->val;
                l1 = l1->next;
            }
            else a = 0;
            if(l2){
                b = l2->val;
                l2 = l2->next;
            } 
            else b = 0;
            int tmp = a + b + carry;
            carry = tmp/10;
            idx->val = tmp%10;
            if(l1 || l2 || carry)idx->next = new ListNode(0);
            idx = idx->next;
           
        }
        return re;
    }
};
