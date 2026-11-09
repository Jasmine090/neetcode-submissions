class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string re = "";
        int i = 0;
        int j = 0;
        int m = word1.size();
        int n = word2.size();
        while(i<m || j<n){
            if(i<m){
                re += word1[i];
                i++;
            }
            if(j<n){
                re += word2[j];
                j++;
            }
        }
        return re;
    }
};