class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> re;
        for(int i=0;i<=n;i++){
            re.push_back(count(i));
        }
        return re;
    }
    int count(int n){
        int tmp = 0;
        while(n){
            n = n&(n-1);
            tmp++;
        }
        return tmp;
    }
};
