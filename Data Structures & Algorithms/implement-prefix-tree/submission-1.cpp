class PrefixTree {
public:
    struct TreeNode{
        bool isEnd = false;
        TreeNode* next[26] = {};

    };
    TreeNode* root;
    PrefixTree() {
        root = new TreeNode();
    }
    
    void insert(string word) {
        TreeNode* cur = root;
        for(int i=0;i<word.size();i++){
            if(cur->next[word[i]-'a']==nullptr)cur->next[word[i]-'a'] = new TreeNode();
            cur = cur->next[word[i]-'a'];
            if(i==word.size()-1){
                cur->isEnd = true;
            }
        }
        return;
    }
    
    bool search(string word) {
        TreeNode* cur = root;
        for(int i=0;i<word.size();i++){
            if(cur->next[word[i]-'a']!=NULL){
                
                cur = cur->next[word[i]-'a'];
                if(i==word.size()-1 && cur->isEnd){
                    //if(word=="app") cout << word[i] << endl;
                    return true;
                }
            }
            else{
                return false;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TreeNode* cur = root;
        for(int i=0;i<prefix.size();i++){
            if(cur->next[prefix[i]-'a']!=NULL){
                cur = cur->next[prefix[i]-'a'];
            }
            else{
                return false;
            }
        }
        return true;
    }
};
