/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        // insert new ones
        Node* tmp = head;
        while(tmp){
            Node* next_n = tmp->next;
            tmp->next = new Node(tmp->val);
            tmp->next->next = next_n;
            tmp = next_n;
        }
        // deal with random
        Node* re = head->next;
        tmp = head;
        while(tmp){
            Node* next_n = tmp->next->next;
            if(tmp->random) tmp->next->random = tmp->random->next;
            else tmp->next->random = nullptr;
            if(next_n) tmp->next->next = next_n->next;
            tmp = next_n;
        }
        // remove old (new point to new)

        return re;
    }
};
