class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size()-1;
        int mid = 0;
        while(left <= right){
            mid = (left+right)/2;
            if(mid>0 && nums[mid-1]>nums[mid]) break;
            else if(nums[mid] > nums[right]){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
            
        }
        return nums[mid];
    }
};
