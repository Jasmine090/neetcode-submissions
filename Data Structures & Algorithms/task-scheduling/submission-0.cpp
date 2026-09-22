class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int ct[26] = {0};
        int maxFreq = 0;
        int maxCt = 0;
        for(int i=0;i<tasks.size() ; i++){
            ct[tasks[i]-'A']++;
            maxFreq = max(maxFreq, ct[tasks[i]-'A']);
        }
        
        for(int i=0;i<26 ; i++){
            if(maxFreq==ct[i]) maxCt++;
        }//cout << maxFreq << " " << maxCt << endl;
        return max(int(tasks.size()), (n+1)*(maxFreq-1)+maxCt);

    }
};
