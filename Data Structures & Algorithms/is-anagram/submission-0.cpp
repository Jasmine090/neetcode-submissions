class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> ss, tt;
        for (int i=0; i<s.size(); i++){
            if (!ss.count(s[i])){
                ss[s[i]] = 1;
            }else{
                ss[s[i]]++;
            }
        } 
        for (int i=0; i<t.size(); i++){
            if (!tt.count(t[i])){
                tt[t[i]] = 1;
            }else{
                tt[t[i]]++;
            }
        } 
        if (ss==tt) return true;
        else return false;
    }
};
