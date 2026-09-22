class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t re = 0;
        int c = 32;
        bitset<32> a(n);
        cout << a <<endl;
        while(c--){
            re<<=1;
            re += (n&1);
            n>>=1;
            
        }

        bitset<32> b(re);
        cout << b <<endl;
        return re;
    }
};
