class Solution {
public:
    int search(vector<int>& nums, int target) {
        // search for start
        int left = 0;
        int right = nums.size()-1;
        int start = 0;
        while(left <= right){
            start = (left+right)/2;
            if(start >0 && nums[start-1]>nums[start])break;
            else if(nums[start]>nums[right]) left = start+1;
            else right = start-1;
        }
        // << start << endl;
        // search target
        int size = nums.size();
        left = 0;
        right = size-1;
        int mid = 0;
        while(left <= right){
            mid = (left+right)/2;
            //cout << left << ' ' << right << endl;
            int tmp = (start + mid) % size;
            if(nums[tmp]==target) return tmp;
            else if(nums[tmp] > target) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }
};
