class Solution {
public:
    int search(vector<int>& nums, int target) {
        int le=0, ri=nums.size()-1;
        while(le <= ri && ri>=0 && le<nums.size()){
            int mid = (le+ri)/2;
            cout << mid << endl;
            if(nums[mid]==target) return mid;
            if(nums[mid]>target) ri = mid-1;
            else le = mid+1;
        }
        return -1;
    }
};
