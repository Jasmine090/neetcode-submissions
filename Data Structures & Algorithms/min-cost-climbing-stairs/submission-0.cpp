class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        int mp[size+1];
        mp[0] = 0;
        mp[1] = 0;
        for(int i=2;i<size+1;i++){
            mp[i] = min(mp[i-1]+cost[i-1], mp[i-2]+cost[i-2]);
        }
        for(int i=0;i<size+1;i++) cout << mp[i] << endl;
        return mp[size];
    }
};
