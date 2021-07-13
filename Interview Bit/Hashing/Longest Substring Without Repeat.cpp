int Solution::lengthOfLongestSubstring(string A) {
   
    unordered_map< char,int > mp;
    int ans=0;
    int l=-1,r=0;
    int n = A.size();
    while( r<n ){
        if(mp.find(A[r])!=mp.end()){
            if(l<mp[A[r]])
                l = mp[A[r]];
        }
        
        ans  = max({ans,r-l});
        mp[A[r]] = r;
        ++r;
        
    }
    
    return ans;
}