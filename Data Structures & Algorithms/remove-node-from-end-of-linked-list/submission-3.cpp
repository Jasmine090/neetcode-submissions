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
        ListNode* fast = head;
        ListNode* slow = head;
        int ct = n-1;
        while(fast && ct){
            ct--;
            fast = fast->next;
        }
        ListNode* prev = new ListNode(-1);
        while(fast->next){
            fast = fast->next;
            prev = slow;
            slow = slow->next;
        }
        cout << prev->val << endl;
        cout << slow->val << endl;
        prev->next = slow->next;
        slow->next = NULL;
        if(slow==head) return prev->next;
        return head;
    }
};
