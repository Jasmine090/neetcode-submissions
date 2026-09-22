class Solution {
public:

    string encode(vector<string>& strs) {
        string en;
        for(int i=0;i<strs.size();i++){
            en += (to_string(strs[i].size()) + '#' + strs[i]);
        }
        return en;
    }

    vector<string> decode(string s) {
        vector<string> de;
        int pos = 0;
        int size = s.size();
        while(pos < size){
            //if(s.find('#', pos)==string::npos) break;
            int gap = s.find('#', pos);
            gap -= pos;
            int len = stoi(s.substr(pos, gap));
            pos += gap+1;
            de.push_back(s.substr(pos, len));
            pos += len;
        }
        return de;
    }
};
