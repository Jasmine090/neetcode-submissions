class Solution {
public:
    void DecisionTree(vector<int>& nums, vector<int>& cur, vector<vector<int>> &re){
        if(cur.size()==nums.size()){
            re.push_back(cur);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==-11) continue;
            int tmp = nums[i];
            nums[i] = -11;
            cur.push_back(tmp);
            DecisionTree(nums, cur, re);
            cur.pop_back();
            nums[i] = tmp;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> re;
        vector<int> cur;
        sort(nums.begin(), nums.end());
        DecisionTree(nums, cur, re);
        return re;
    }
};
