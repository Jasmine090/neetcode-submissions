class Solution {
public:
    double POW(double x, long long n){
        // x>0, n>0
        if(n==0) return 1;
        double tmp = POW(x, n/2);
        if(n%2) return tmp*tmp*x;
        else return tmp*tmp;
    }
    double myPow(double x, int n) {
        long long ln = n;
        if(x<0 && ln<0){
            if(ln%2) return -1*POW(-1/x, -ln);
            else return POW(-1/x, -ln);
        }
        else if(x<0 && ln>0){
            if(ln%2) return -1*POW(-x, ln);
            else return POW(-x, ln);
        } 
        else if(x>0 && ln<0){
            return POW(1/x, ln);
        }
        else{
            cout << "!" << endl;
            return POW(x, ln);
        }

    }
};
