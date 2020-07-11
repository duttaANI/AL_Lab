// link : https://leetcode.com/problems/push-dominoes/solution/
class Solution {
public:
    string pushDominoes(string dominoes) {
        string ans="";
        int N = dominoes.length();
        vector<int> forces(N,0);
        int force = 0;
        for (int i=0; i<N; ++i){
            if (dominoes[i] == 'R') force = N;
            else if (dominoes[i] == 'L') force = 0;
            else force = max(force - 1, 0);
            forces[i] += force;
        }
        for (int i = N-1; i >= 0; --i){
            if (dominoes[i] == 'L') force = N;
            else if (dominoes[i] == 'R') force = 0;
            else force = max(force - 1, 0);
            forces[i] -= force;
        }
        for (int f: forces)
            ans.push_back(f > 0 ? 'R' : f < 0 ? 'L' : '.');
        return ans;
    }
};

// This approach doesnt work
class Solution {
public:
    string pushDominoes(string dominoes) {
        string ans="";
        queue <pair<char,int>> Q;
        for (int i=0; i<dominoes.length(); ++i){
            if(dominoes[i]=='L'){
                Q.push({'L',i});
            }else if(dominoes[i]=='R'){
                Q.push({'R',i});
            }
        }
        pair<char,int> fir,sec;
        int slow=0,fast=0;
        while(Q.size()>=2){
            fir = Q.front(); Q.pop(); sec = Q.front(); //Q.pop();
            
            if(fir.first=='L' && sec.first=='L' ){
                fast = sec.second;
                for(int i=fir.second; i<=fast; ++i){
                    ans = ans + 'L';
                }
                slow=fast;
            }else if (fir.first=='L' && sec.first=='R' ){
                fast = fir.second;
                for(int i=slow+1; i<=fast; ++i){
                    ans = ans + 'L';
                }
                for(int i=fast+1; i<sec.second; ++i){
                    ans = ans + '.';
                }                
                slow=fast;
            }else if (fir.first=='R' && sec.first=='R' ){
                fast = sec.second;
                for(int i=fir.second; i<=fast; ++i){
                    ans = ans + 'R';
                }
                slow=fast;
            }else if (fir.first=='R' && sec.first=='L' ){
                for(int i=0; i<=(sec.second-fir.second-1)/2; ++i){
                    ans = ans + 'R';
                }
                if((sec.second-fir.second-1)%2!=0 ){
                    ans += '.';
                } 
                for(int i=0; i<=(sec.second-fir.second-1)/2; ++i){
                    ans = ans + 'L';
                }
                fast=sec.second;
                slow=fast;
            }
        }
        for(int i=fast+1; i<dominoes.length();++i){
            ans += dominoes[i];
        }
        
        return ans;
    }
};