class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        /*
        2 5 6
        1 4 4
        5 7 5
        */
        bool fir = false;
        bool sec = false;
        bool thir = false;
        for(int i=0;i<triplets.size();i++){
            if(triplets[i][0]==target[0] && triplets[i][1]<= target[1] && triplets[i][2]<= target[2]){
                fir = true;
            }
            if(triplets[i][1]==target[1] && triplets[i][0]<= target[0] && triplets[i][2]<= target[2]){
                sec = true;
            }
            if(triplets[i][2]==target[2] && triplets[i][0]<= target[0] && triplets[i][1]<= target[1]){
                thir = true;
            }
        }
        return fir && sec && thir;
    }
};
