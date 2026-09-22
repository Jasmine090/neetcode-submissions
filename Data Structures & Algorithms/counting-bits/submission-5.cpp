class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> re;
        re.push_back(0);
        for(int i=1;i<=n;i++){
            re.push_back(re[i>>1]+(i&1));
        }
        return re;
    }
};
