class Solution {
public:
    vector<int> partitionLabels(string S) {
        
        vector<int> ans;
        
        vector<int> last_occur(26,-1); // -1 implies not present
        for (int i=0; i<S.length(); ++i) {
            last_occur[S[i]-'a'] = i ;
        }
        
        int j=0, anchor =0 ;
        for(int i=0; i< S.length(); ++i) {
            j = max(j,last_occur[S[i]-'a']);
            if(i==j) {
                ans.push_back(i - anchor +1);
                anchor = i+1;
            }
        }
        
        return ans;
        
    }
};