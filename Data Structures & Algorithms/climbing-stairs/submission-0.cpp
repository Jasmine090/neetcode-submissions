class Solution {
public:
    int climbStairs(int n) {
        static int mp[45];
        static bool built = false;
        mp[0]=1;
        mp[1]=2;
        mp[2]=3;
        if(!built){
            for(int i=3;i<45;i++) mp[i]=mp[i-1]+mp[i-2];
            built = true;
        }
        return mp[n-1];
    }
};
