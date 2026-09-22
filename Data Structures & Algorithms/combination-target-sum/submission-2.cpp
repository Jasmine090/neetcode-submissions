class Solution {
public:
    void DecisionTree(vector<int> &nums, int target, vector<int> cur, vector<vector<int>> &re, int start){
        
        for(int i=start;i<nums.size();i++){
            if(nums[i]>target) break;
            if((target-nums[i])==0){
                cur.push_back(nums[i]);
                re.push_back(cur);
                cur.pop_back();
            }
            else if((target-nums[i])>0){
                cur.push_back(nums[i]);
                DecisionTree(nums, target-nums[i], cur, re, i);
                cur.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> re;
        sort(nums.begin(), nums.end());
        DecisionTree(nums, target, {}, re, 0);
        return re;
    }
};
