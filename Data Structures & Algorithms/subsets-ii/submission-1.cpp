class Solution {
public:
    void DecisionTree(vector<int>& nums, int start, vector<vector<int>> &re, vector<int> &cur, bool init){
        re.push_back(cur);
        for(int i=start;i<nums.size();i++){
            if(init && i>start && nums[i]==nums[i-1]) continue;
            cur.push_back(nums[i]);
            DecisionTree(nums, i+1, re, cur, true);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> re;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        DecisionTree(nums, 0, re, cur, true);
        return re;
    }
};
//1,2,2:
//1,2,
//1,2,2
//1,2
