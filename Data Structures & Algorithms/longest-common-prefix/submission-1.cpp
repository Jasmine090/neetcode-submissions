class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string re = "";
        for(int i=0;;i++){
            if(i>=strs[0].size()) break;
            char tmp = strs[0][i];
            bool diff = false;
            for(int j=1;j<strs.size();j++){
                if(strs[j].size()==i) return re;
                if(tmp!=strs[j][i]){
                    diff = true;
                    break;
                }
            }
            if(diff) return re;
            else re += tmp;
        }
        return re;
    }
};