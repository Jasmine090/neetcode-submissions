class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        map<char, int> ss;
        for (int i=0; i<s.size(); i++){
            if (!ss.count(s[i])){
                ss[s[i]] = 1;
            }else{
                ss[s[i]]++;
            }
        } 
        for (int i=0; i<s.size(); i++){
            if (ss.find(t[i])==ss.end() ||
                ss.find(t[i])->second==0) return false;
            ss[t[i]]--;
        }
        return true;
    }
};
