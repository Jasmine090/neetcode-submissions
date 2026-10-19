class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> re;
        bool insert = false;
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][1] < newInterval[0]){
                re.push_back(intervals[i]);
            }
            else if(intervals[i][0] > newInterval[1]){
                if(!insert){
                    re.push_back(newInterval);
                    insert = true;
                }
                re.push_back(intervals[i]);
            }
            else{
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);                
            }
            
        }
        if(!insert) re.push_back(newInterval);
        return re;
    }
};
