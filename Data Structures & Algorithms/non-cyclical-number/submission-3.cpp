class Solution {
public:
    bool isHappy(int n) {
        set<int> mp;
        while(n!=1){
            mp.insert(n);
            n = sum(n);
            if(mp.count(n)) return false;
        }
        return true;
    }
    int sum(int n){
        int re = 0;
        while(n){
            re += (n%10)*(n%10);
            n /= 10;
        }
        return re;
    }
};
