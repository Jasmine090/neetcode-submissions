class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> mp;
        for(int i=0;i<hand.size();i++){
            mp[hand[i]]++; 
        }
        while(mp.size()){
            int smallest_k = mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mp.count(smallest_k+i) && mp[smallest_k+i]>0) mp[smallest_k+i]--;
                else{
                    return false;
                }
                if(mp[smallest_k+i]==0) mp.erase(smallest_k+i);
            }
        }
        return true;
    }
};
