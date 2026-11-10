class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int replace = 0;
        int n = nums.size();
        int k = 0;
        for(int i=0;replace<n;i++){
            nums[i] = nums[replace];
            k++;
            replace++;
            while(replace<n && nums[i]==nums[replace]){
                replace++;
            }
        }
        return k;
    }
};