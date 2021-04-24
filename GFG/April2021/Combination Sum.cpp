class Solution {
  public:
    // set<vector<int>>ans;
    vector<vector<int>>ans;
    int sum=0;
    vector<int> temp;
    
    void bckTrk(vector<int> &A, int B, int start){
        if( sum==B ){
            // ans.insert(temp);
            ans.push_back(temp);
            return ;
        }
        
        if(sum<B){
            for(int i=start; i<A.size(); ++i){
                temp.push_back(A[i]);
                sum += A[i];
                bckTrk(A,B,i);
                temp.pop_back();
                sum-=A[i];
            }
        }
        
        return ;    
    }
  
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        // Your code here
        sort(A.begin(),A.end());
        A.erase(unique(A.begin(), A.end()), A.end());
        bckTrk(A,B,0);
        
        vector< vector<int> > res;
        
        // for( vector<int> v : ans  ){
        //     res.push_back(v);
        // }
        
        // return res;
        return ans;
    }
};