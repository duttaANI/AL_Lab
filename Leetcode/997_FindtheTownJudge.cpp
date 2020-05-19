class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
          
        vector<int> count(N+1,0);
        for(auto i : trust) {
            count[i[0]]--;
            count[i[1]]++;
        }
        for(int i=1; i<= N;++i) {
            if(count[i]==N-1) return i;
        }
        return -1;
    }
};