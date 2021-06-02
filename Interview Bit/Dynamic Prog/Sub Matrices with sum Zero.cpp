int zeroes(int arr[], int n)
{
   unordered_map<int, int> mp;
   int count = 0;
   int sum = 0;
   for(int i = 0; i < n; i++)
   {
      sum += arr[i];
      if(sum==0)
      {
          count++;
      }
      if(mp.find(sum) != mp.end())
      {
          count += mp[sum];
      }
      mp[sum]++;
  }
  return count;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    if(n==0 || m==0)
    {
        return 0;
    }
    int ans = 0;
    for(int i = 0; i < m; i++)
    {
        int arr[n] = {0};
        for(int j = i; j < m; j++)
        {
            for(int k = 0; k < n; k++)
            {
                arr[k] = arr[k] + A[k][j];
            }
            ans = ans + zeroes(arr,n);
        }
    }
    return ans;
}

// #include <bits/stdc++.h>
// using namespace std;

// int Solution::solve(vector<vector<int> > &A) {
    
//     int H = A.size();
//     int W = A[0].size();
//     int ans = 0;
    
//     unordered_map<string,int> mp;
//     int sum = 0;
//     for(int i=0;i<H;++i){
//         for(int j=0;j<W;++j){
//             sum += A[i][j];
            
//             for(int k=0;k<i;++k){
//                 for(int l=0;l<j;++l){
//                     string sB = ""; string sY = ""; string sG = ""; 
//                     sB += to_string(k) + " " + to_string(l);
//                     sY += to_string(k) + " " + to_string(j);
//                     sG += to_string(i) + " " + to_string(l);
//                     if( mp[sG] + mp[sY] - mp[sB] == sum  ){
//                         ++ans;
//                     }
//                 }
//             }
            
//             string s = "";
//             s += to_string(i) + " " + to_string(j);
//             mp[s] = sum;
//         }
//     }
//     return ans;
// }
