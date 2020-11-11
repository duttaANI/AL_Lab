# define ar array
# define ll long long
// set[i] stores the maximum profit taking elements from the suffix starting at i.
class Solution {
public:
    vector<ar<int,3>> a;
    map<int,int> s;
    map<int,int> mp;
    
    static bool cmp(ar<int,3> a,ar<int,3> b){
        if(a[0]!=b[0])
            return a[0]<b[0];
        else /*if(a[1]!=b[1])*/
            return a[2]<b[2];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        for(int i=0;i<n;++i){
            a.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(a.begin(),a.end(),cmp);
        
        // for(auto i : a){
        //     cout << i[0] << " " << i[1] << " " << i[2] << "\n";
        // }
    
        int ans = -1;
        for(int i=n-1; i>=0; --i){
            // try to find an element in set with stime >= endtime
            auto it = s.lower_bound( a[i][1] );
            if (it != s.end() ){
                mp[a[i][0]] = max({ ans, (*it).second + a[i][2] });
            }else{
                mp[a[i][0]] = max({a[i][2],ans,mp[a[i][0]] });
            }
            // cout << mp[a[i][0]] << "\n";
            
            s[a[i][0]]=max(s[a[i][0]],mp[a[i][0]]);
            ans = max(ans,mp[a[i][0]]);
        }
        
        // for( auto i : s ){
        //     cout << i.first << " " << i.second << "\n";
        // }
        
        return ans;
    }
};

















































# define ar array
# define ll long long
// set[i] stores the maximum profit taking elements from the suffix starting at i.
class Solution {
public:
    vector<ar<int,3>> a;
    set<ar<int,2>> s;
    map<int,int> mp;
    
    static bool cmp(ar<int,3> a,ar<int,3> b){
        if(a[0]!=b[0])
            return a[0]<b[0];
        else /*if(a[1]!=b[1])*/
            return a[1]>b[1];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        
        for(int i=0;i<n;++i){
            a.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(a.begin(),a.end(),cmp);
    
        int ans = -1;
        for(int i=n-1; i>=0; --i){
            // try to find an element in set with stime >= endtime
            auto it = s.lower_bound( {a[i][1]} );
            if (it != s.end() ){
                mp[a[i][0]] = (*it)[1] + a[i][2];
            }else{
                mp[a[i][0]] = max(a[i][2],ans );
            }
            cout << mp[a[i][0]] << "\n";
            
            s.insert({a[i][0],mp[a[i][0]]});
            ans = max(ans,mp[a[i][0]]);
        }
        
        for( auto i : s ){
            cout << i[0] << " " << i[1] << "\n";
        }
        
        return ans;
    }
};