class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        
        vector<long long > b,ans(n,0);
        // int n = arr.size();
        
        for(int i=0;i<n;++i){
            b.push_back(arr[i]);
        }
        
        reverse( b.begin(), b.end() );
        
        stack<long long> s;
        
        
        
        for(int i=0;i<n;++i){
            while(!s.empty() && s.top()<b[i]  ){
                s.pop();
            }
            if(!s.empty()){
                ans[i] = s.top();
            }else{
                ans[i] = -1;
            }
            s.push(b[i]);
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
