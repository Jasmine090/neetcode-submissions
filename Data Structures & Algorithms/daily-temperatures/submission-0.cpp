class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> re(temperatures.size(), 0);
        stack<int> st;
        st.push(0);
        
        for(int i=1;i<temperatures.size();i++){
            //cout << i << ": ";
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                //cout << st.top() <<',' << temperatures[st.top()] << ' ';
                re[st.top()] = i-st.top();
                st.pop();
            }
            //cout << endl;
            st.push(i);
        }
        while(!st.empty()){
            re[st.top()] = 0;
            st.pop();
        }
        return re;
    }
};
