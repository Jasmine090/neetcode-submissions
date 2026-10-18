class Solution {
public:
    bool checkValidString(string s) {
        // (((()
        // (()))
        int high = 0; // # of '(' in most '(' situation, all * are '('
        int low = 0; // # of '(' in least '(' situation, all * are ')'
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                low++;
                high++;
            }
            else if(s[i]==')'){
                low--;
                high--;
            }
            else{
                low--;
                high++;
            }
            if(high<0) return false;
            if(low<0) low = 0;
        }
        if(low>0) return false;
        return true;
    }
};
