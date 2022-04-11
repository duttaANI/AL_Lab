// My 
int n;
unordered_map<string,int> mp;

void solve(int s, int cur_sum, int B, vector<int> temp, vector< vector<int> >& ans, const vector<int>& A){
    
    // cout << cur_sum << " cur_sum \n";
    if( cur_sum == B ){
        string str = "";
        for(int i=0;i<temp.size();++i){
            str += to_string(temp[i]);
        }
        // cout << str << " str \n";
        if(mp.find(str)==mp.end()){
            ans.push_back(temp);
            mp[str] = 1;
        }
    }
    if(s==n){
        return ;
    }
    for(int i = s ; i<n; ++i){
        temp.push_back(A[i]);
        if(cur_sum+A[i]<=B)
            solve(i+1,cur_sum+A[i],B,temp,ans,A);
        temp.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {
    sort(A.begin(),A.end());
    vector< vector<int> > ans;
    n = A.size();
    
    solve(0,0,B,{},ans,A);

    return ans;
}


void incExcl(vector<vector<int>>& ans, vector<int>& temp, int start, int target, vector<int>& candidates )  {
        
        if( target<0 ){
            return ;
        }

        if( 0==target ) {
          
            ans.push_back(temp);
           
            return ;
        } 

        for (int i=start; i<candidates.size(); ++i) {  

         
            
            if(i>start&&candidates[i]==candidates[i-1])      //add this condition only
            {
                continue;
            }

            temp.push_back(candidates[i]);

            incExcl(ans, temp, i+1, target-candidates[i], candidates);

            temp.pop_back();
        }
    }

vector<vector<int> > Solution::combinationSum(vector<int> &candidates, int target) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    sort(candidates.begin(),candidates.end());

    vector<vector<int>> ans; vector<int> temp;

    incExcl(ans, temp, 0, target, candidates);

    return ans;
}
