class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left=0;
        int right = heights.size()-1;
        int re = 0;
        while(left < right){
            re = max(min(heights[left], heights[right])*(right-left), re);
            if(heights[left] < heights[right]){
                left++;
            }
            else right--;
        }
        return re;
    }
};
