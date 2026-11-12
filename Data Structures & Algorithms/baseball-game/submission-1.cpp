class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> q;
        for(int i=0;i<operations.size();i++){
            if(operations[i][0]=='+'){
                int tmp = q.top();
                q.pop();
                int next = tmp+q.top();
                q.push(tmp);
                q.push(next);
            }
            else if(operations[i][0]=='D'){
                int tmp = q.top();
                q.push(2*tmp);
            }
            else if(q.size() && operations[i][0]=='C'){
                q.pop();
            }
            else{
                q.push(stoi(operations[i]));
            }
        }
        int re = 0;
        while(q.size()){
            re += q.top();
            q.pop();
        }
        return re;
    }
};