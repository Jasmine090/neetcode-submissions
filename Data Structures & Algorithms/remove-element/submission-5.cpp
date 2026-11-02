class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        int sw_idx = n-1;
        for(int i=0;i<n;i++){
            if(i==n-1 && nums[i]!=val) break;
            if(sw_idx<=i) return sw_idx;
            if(nums[i]==val){
                while(nums[sw_idx]==val){
                    sw_idx--;
                    if(sw_idx<0) return 0;
                    if(sw_idx==i) return i;
                }
                swap(nums[i], nums[sw_idx]);              
            }
        }
        return n;
    }
};