class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        int mp[26] = {0};
        for(int i=0;i<s1.size();i++) mp[s2[i]-'a']++;
        for(int i=0;i<s1.size();i++) mp[s1[i]-'a']--;
        int left = 0;
        int right = s1.size()-1;

        while(1){
            for(int i=0;i<26;i++){
                if(mp[i]) break;
                if(i==25) return true;
            }
            mp[s2[left]-'a']--;
            left++;
            right++;
            if(right >= s2.size()) break;
            mp[s2[right]-'a']++;
        }
        return false;
    }

};
