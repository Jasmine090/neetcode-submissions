class Solution {
public:
    int hammingWeight(uint32_t n) {
        int tmp = 0;
        while(n){
            n = n&(n-1);
            tmp++;
        }
        return tmp;
    }
};
