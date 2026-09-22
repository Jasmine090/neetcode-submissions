class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> st;
        
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                int a = st.back();
                st.pop_back();
                a += st.back();
                st.pop_back();
                st.push_back(a);
            }
            else if(tokens[i]=="-"){
                int a = st.back();
                st.pop_back();
                a = st.back()-a;
                st.pop_back();
                st.push_back(a);
            }
            else if(tokens[i]=="*"){
                int a = st.back();
                st.pop_back();
                a *= st.back();
                st.pop_back();
                st.push_back(a);
            }
            else if(tokens[i]=="/"){
                int a = st.back();
                st.pop_back();
                a = st.back()/a;
                st.pop_back();
                st.push_back(a);
            }
            else{
                st.push_back(stoi(tokens[i]));
            }
        }
        return st.back();
    }
};
