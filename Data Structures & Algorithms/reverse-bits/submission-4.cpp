class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t re = 0;
        int c = 32;
        while(c--){
            re<<=1;
            re += (n&1);
            n>>=1;
        }

        // bitset<32> b(re);
        // cout << b <<endl; bit 形式可以這樣印出
        return re;
    }
};
