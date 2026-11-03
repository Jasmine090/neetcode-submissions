class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            if(!cnt){
                candidate = nums[i];
                cnt++;
            }
            else if(candidate==nums[i]){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return candidate;
    }
};