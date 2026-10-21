class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> tmp;
        tmp.push_back(intervals[0]);
        for(int i=1;i<intervals.size();i++){
            if(tmp.back()[1] > intervals[i][1]){
                tmp.pop_back();
                tmp.push_back(intervals[i]);
            }
            else if(tmp.back()[1] <= intervals[i][0]) 
                tmp.push_back(intervals[i]);
            
        }
        // for(int i=0;i<tmp.size();i++){
        //     cout << tmp[i][0] << ' ' << tmp[i][1] << endl; 
        // }
        return intervals.size()-tmp.size();
    }
};
