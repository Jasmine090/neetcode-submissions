class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])) continue;
            mp.insert(nums[i]);
        } 
        int re = 0;
        for(int i=0;i<nums.size();i++){
            if(!mp.count(nums[i])) continue;
            if(!mp.count(nums[i]-1)){
                int tmp = nums[i]+1;
                int count = 1;
                while(mp.count(tmp)){
                    mp.erase(tmp);
                    count++;
                    tmp++;
                }
                re = max(re, count);
            }
        }
        return re;
    }
};
