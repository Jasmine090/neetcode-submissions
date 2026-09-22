class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size();i++){
            
            vector<int> tmp;
            if(mp.count(target-nums[i])){
                int j = mp[target-nums[i]];
                if(j>i){
                    tmp.push_back(i);
                    tmp.push_back(j);
                }else{
                    tmp.push_back(j);
                    tmp.push_back(i);
                }
                return tmp;
            }
            mp[nums[i]]=i;
        }

    }
};
