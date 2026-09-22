class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> s;
        for (const auto &n: nums){
            if(s.count(n)) return true;
            s.insert(n);
        }
        return false;
    }
};