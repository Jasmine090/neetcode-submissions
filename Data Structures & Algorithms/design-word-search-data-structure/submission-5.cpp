class WordDictionary {
public:
    struct TreeNode{
        bool isEnd = false;
        TreeNode* next[26] = {};
    };
    TreeNode* root;
    WordDictionary() {
        root = new TreeNode();
    }
    
    void addWord(string word) {
        TreeNode* cur = root;
        for(int i=0;i<word.size();i++){
            if(!cur->next[word[i]-'a']) cur->next[word[i]-'a'] = new TreeNode();
            cur = cur->next[word[i]-'a'];
        }
        cur->isEnd = true;
        return;
    }
    bool dfs(TreeNode* cur, string &word, int start){
        if(word.size()==0) return false;
        for(int i=start;i<word.size();i++){
            if(word[i]=='.')
            {   
                vector<TreeNode*> tmp;
                bool flag = false;
                for(int j=0;j<26;j++){
                    if(cur->next[j]){
                        tmp.push_back(cur->next[j]);
                        //if(cur->next[j]->isEnd) flag = true;
                    }
                }
                if(!tmp.size()) return false;
                //else if(i==word.size()-1) return flag;
                for(int j=0;j<tmp.size();j++){
                    if(dfs(tmp[j], word, i+1)) return true;
                }
                return false;
            }
            if(cur->next[word[i]-'a']==nullptr) return false;
            cur = cur->next[word[i]-'a'];
        }
        return cur->isEnd;
    }
    bool search(string word) {
        return dfs(root, word, 0);
    }
};
