class Solution {
public:
    vector<vector<int>> DecisionTree(vector<int> &nums, int start_idx, vector<int> cur){
        vector<vector<int>> re;
        re.push_back(cur);
        for(int i=start_idx ; i<nums.size() ; i++){
            cur.push_back(nums[i]);
            vector<vector<int>> tmp = DecisionTree(nums, i+1, cur);
            re.insert(re.end(), tmp.begin(), tmp.end());
            cur.pop_back();
        }
        return re;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> cur;
        return DecisionTree(nums, 0, {});
    }
};
