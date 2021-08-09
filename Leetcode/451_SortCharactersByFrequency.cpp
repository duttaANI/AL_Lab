class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        unordered_map < char,int > mp;
        vector< pair<int,char> > freq;
        for(int i=0;i<n;++i){
            mp[s[i]] ++;
        }
        
        for( auto i : mp   ){
            freq.push_back({ i.second, i.first  });
        }
        
        sort( freq.begin(),freq.end() );
        
        string ans = "";
        for( auto i : freq ){
            int temp = i.first;
            while(temp--){
                ans += i.second;
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
