/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
void dfs(Node* node, unordered_map<Node*, Node*> &mp){
    if(node==nullptr || mp.count(node)) return;
    Node* copy = new Node(node->val, {});
    mp[node] = copy;
    for(auto a: node->neighbors){
        dfs(a, mp);
        copy->neighbors.push_back(mp[a]);
    }
    return;
}
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mp;
        dfs(node, mp);
        return mp[node];
    }
};
