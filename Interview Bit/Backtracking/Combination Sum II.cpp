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
