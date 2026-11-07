class Solution {
public:
    bool validPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        bool chance = true;
        while(left < right){
            if(s[left] !=s[right]){
                chance = false;
                break;
            }
            else{
                left++;
                right--;
            }
        }
        if(!chance){
            left++;
            while(left<right){
                if(s[left] !=s[right]){
                    break;
                }
                else{
                    left++;
                    right--;
                }
            }
            left--;
            right--;
            while(left<right){
                if(s[left]!=s[right]){
                    return false;
                }
                else{
                    left++;
                    right--;
                }
            }
        }
        return true;
    }
};