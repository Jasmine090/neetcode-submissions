class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int re = 0;
        while(left <= right){
            int k = (left+right)/2;
            long long int hrs = 0;
            for(int i=0;i<piles.size();i++){
                hrs += (piles[i]+k-1)/k;
            }
            if(hrs <= h){
                re = k;
                right = k-1;
            }else{
                left = k+1;
            }
        }
        return re;
    }
};
