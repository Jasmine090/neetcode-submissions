class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // gas-cost = [-1,0,-1,3]
        int n = gas.size();
        int total = 0;
        int tank = 0;
        int start = 0;
        for(int i=0;i<n;i++){
            if(tank<0){
                start = i;
                tank = 0;
            }
            total += gas[i]-cost[i];
            tank += gas[i]-cost[i];
        }
        return (total>=0)? start:-1;
    }
};
