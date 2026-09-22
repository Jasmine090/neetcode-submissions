class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1;
        bool f = false;
        digits[i] += 1;
        while(i>=0){
            if(f){
                digits[i] += 1;
                f = false;
            }
            if(digits[i]>9){
                f = true;
                digits[i] = 0;
                if(!i){
                    digits.insert(digits.begin(), 1);
                    break;
                }
            }
            i--;
        }
        return digits;
    }
};
