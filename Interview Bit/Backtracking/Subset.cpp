void subset(vector<int> &A,vector<vector<int>> &ans,vector<int> temp,int index)
{
    //insert 
    ans.push_back(temp);
    
    for(int i=index;i<A.size();i++)
    {
        temp.push_back(A[i]); // include

        subset(A,ans,temp,i+1); // i+1 , include / exclude for next element
        temp.pop_back(); // exclude
    }
    // cout << endl;
    return;
}

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector<vector<int>> ans;
    sort(A.begin(),A.end());
    int index=0;
    vector<int> temp;
    subset(A,ans,temp,index);
  return ans;
    
}

// vector<vector<int> > Solution::subsets(vector<int> &A) {
//     vector<vector<int> > ans;
//     int n = A.size();
//     int end = pow(2,n);
//     for(int i=0;i<end; ++i){
//         vector<int> temp;
//         int cpy = i,j=0;
//         while(cpy){
//             if(cpy&1)
//                 temp.push_back( A[j] );
//             cpy=cpy>>1;
//             ++j;
//         }
//         sort(temp.begin(),temp.end());
//         ans.push_back(temp);
//         temp.clear();
//     }
//     sort(ans.begin(),ans.end());
//     return ans;
// }
