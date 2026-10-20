class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> re;
        re.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] <= re.back()[1]){
                re.back()[0] = min(re.back()[0], intervals[i][0]);
                re.back()[1] = max(re.back()[1], intervals[i][1]);
            }
            else re.push_back(intervals[i]);
        }
        return re;
    }
};
