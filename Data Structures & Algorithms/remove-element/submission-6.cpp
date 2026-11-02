class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        int sw_idx = n-1;
        int i;
        for(i=0;i<=sw_idx;i++){
            if(nums[i]==val){
                swap(nums[i], nums[sw_idx]);
                sw_idx--;
                i--;
            }
            
        }
        return i;
    }
};