class Solution {
public:
    vector<int> intersection(vector<vector<int>>& A ) {
        vector<int> ans;
        map<int,int> mp; //  element , sum of indices of number of arrays in which it is present 
        int H = A.size();
        
        for(int i=0;i<H;++i){
            int W = A[i].size();
            for(int j=0;j<W;++j){
                
                mp[A[i][j]] += (i+1);
                // cout << A[i][j] << " <-ele  mp-> " << mp[A[i][j]] << " i+1-> " << (i+1) << endl;
                
            }
        }
        // cout << " (H)*(H+1)/2 = " <<  (H)*(H+1)/2 << endl;
        for( auto e : mp ){
            // cout << e.first << " " << e.second << endl;
            if( e.second == (H)*(H+1)/2 ){
                
                ans.push_back(e.first);
            }
        }
        
        return ans;
    }
};