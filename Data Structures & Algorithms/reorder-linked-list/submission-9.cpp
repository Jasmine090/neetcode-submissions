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
    void reorderList(ListNode* head) {
        // find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        //if(slow==fast) return;
        // cout << slow->val << endl;
        // cout << fast->val <<endl;
        // reverse latter list part
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        slow->next = NULL;
        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        if(prev) cout << prev->val << endl;
        else cout << "empty" << endl;
        ListNode* tmp = prev;
        while(tmp){
            cout << tmp->val <<endl;
            tmp = tmp->next;
        }
        cout << endl;
        tmp = head;
        while(tmp){
            cout << tmp->val << endl;
            tmp = tmp->next;
        }
        //merge
        ListNode* dummy = new ListNode(-1);
        curr = dummy;
        ListNode* list1 = head;
        ListNode* list2 = prev;
        while(list1 && list2){
            curr->next = list1;
            list1 = list1->next;
            curr = curr->next;

            curr->next = list2;
            list2 = list2->next;
            curr = curr->next;
        }
        if(list1) curr->next = list1;
        if(list2) curr->next = list2;
    }
};
