class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        quickselect(nums, 0, nums.size()-1, k-1);
        //for(int i=0;i<nums.size();i++) cout << nums[i] << endl;
        return nums[k-1];
    }
    int partition(vector<int> &nums, int left, int right){
        int i= left-1;
        for(int j=left;j<right;j++){
            if(nums[right]<nums[j]){
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i+1], nums[right]);
        return i+1;
    }
    void quickselect(vector<int> &nums, int left, int right, int k){
        if(left > right) return;
        int pivotIdx = partition(nums, left, right);
        if(pivotIdx==k) return;
        else if(pivotIdx < k){
            quickselect(nums, pivotIdx+1, right, k);
        }
        else{
            quickselect(nums, left, pivotIdx-1, k);
        }
        return;
    }
};
