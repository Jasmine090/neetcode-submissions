class Solution {
public:
    int characterReplacement(string s, int k) {
        if(!s.size()) return 0;
        if(s.size()==1) return 1;
        int quota = k;
        int left = 0;
        unordered_map<char, int> mp;
        mp[s[0]] = 1;
        int re = 0;
        char max_rep = s[0];
        for(int i=1;i<s.size();i++){
            cout << max_rep << endl;
            mp[s[i]]++;
            if(mp[max_rep]<mp[s[i]]) max_rep = s[i];
            
            if((i+1-left-mp[max_rep])>k){
                mp[s[left]]--;
                left++;
            }
            re = max(re, i+1-left);
        }
        return re;
    }
};
