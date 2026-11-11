class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> win;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            
            if(cnt==k+1){
                win.erase(nums[i-k-1]);
                cnt--;
            }
            
            if(win.count(nums[i])){
                return true;
            }
            win.insert(nums[i]);
            cnt++;
        }
        return false;
    }
};