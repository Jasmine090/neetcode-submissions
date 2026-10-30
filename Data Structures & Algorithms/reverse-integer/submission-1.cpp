class Solution {
public:
    int reverse(int x) {
        int re = 0;
        while(x){
            int tmp = x%10;
            x /= 10;
            // re*10 + tmp > INT_MAX?
            // re*10 + tmp < INT_MIN?
            if((re > (INT_MAX-tmp)/10) || (re < (INT_MIN-tmp)/10)){
                return 0;
            }
            re = re*10 + tmp;
        }
        return re;
    }
};
