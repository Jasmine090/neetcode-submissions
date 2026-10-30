class Solution {
public:
    int reverse(int x) {
        int re = 0;
        while(x){
            int tmp = x%10;
            x /= 10;
            // 正數：re*10 + tmp > INT_MAX，INT_MAX = M*10 + 7，M = 214748364
            // re >  M：re*10 >= M*10 + 10 = INT_MAX + 3       => 溢位
            // re <  M：re*10 + tmp <= M*10 - 1 = INT_MAX - 8  => 安全
            // re == M：M*10 + tmp > M*10 + 7 => tmp > 7       => 溢位
            // => re > M || (re == M && tmp > 7)

            // 負數：re*10 + tmp < INT_MIN，INT_MIN = M'*10 - 8，M' = -214748364
            // re <  M'：re*10 <= M'*10 - 10 = INT_MIN - 2       => 溢位
            // re >  M'：re*10 + tmp >= M'*10 + 1 = INT_MIN + 9  => 安全
            // re == M'：M'*10 + tmp < M'*10 - 8 => tmp < -8     => 溢位
            // => re < M' || (re == M' && tmp < -8)
            int M = INT_MAX/10;
            int n_M = INT_MIN/10;
            if((re>M || re==M && tmp>7) || (re<n_M || (re==n_M && tmp<-8))){
                return 0;
            }
            re = re*10 + tmp;
        }
        return re;
    }
};
