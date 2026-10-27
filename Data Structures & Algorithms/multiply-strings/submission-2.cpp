class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        vector<int> product(m+n, 0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int tmp = (num1[m-1-i]-'0')*(num2[n-1-j]-'0');
                product[i+j] += tmp%10;
                product[i+j+1] += tmp/10;
            }
        }
        for(int i=0;i<m+n;i++){
            if(product[i]>9){
                product[i+1] += product[i]/10;
                product[i] %= 10;
            }
        }
        string re = "";
        int start = -1;
        for(int i=m+n-1;i>=0;i--){
            //cout << product[i] <<' ';
            if(product[i]){
                start = i;
                break;
            }
        }
        for(int i=start;i>=0;i--){
            re += (product[i]+'0');
        }
        return (start==-1)?"0":re;
    }
};
