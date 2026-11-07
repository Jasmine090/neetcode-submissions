class Solution {
public:
    bool check(string &s, int l, int r){
        while(l < r){
            if(s[l]!=s[r]){
                return false;
            }
            else{
                l++;
                r--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n-1;
        bool chance = true;
        while(left < right){
            bool l, r;
            if(s[left]!=s[right]){
                l = check(s, left+1, right);
                r = check(s, left, right-1);
                return (l||r);
            }
            else{
                left++;
                right--;
            }
        }
        return true;
    }
};