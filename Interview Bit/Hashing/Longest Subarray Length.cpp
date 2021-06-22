// int Solution::solve(vector<int> &A) {
//     int cnt = 0;
//     int n = A.size();
//     int ans=0 ;
//     unordered_map<int,set<int>> mp;
//     for(int i=0;i<n;++i){
//         if(A[i]==1) ++cnt;
//         else --cnt;
        
//         mp[cnt].insert(i);
//         if(mp.find(cnt-1)!=mp.end()){
//             ans = max({ans,i-*mp[cnt-1].begin()});
//         }
//     }
//     return ans;
// }

// solution of editorial
// int Solution::solve(vector<int> &A) {
//     int mx=0;
//     map<int,int> wow;
//     int temp=0;
//     int n=(int)A.size();
//     wow[0]=-1;
//     for(int i =0;i<n;i++)
//     {
//         if(A[i]==1)
//             temp++;
//         else
//             temp--;
//         if(wow.count(temp-1))
//             mx=max(mx, i-wow[temp-1]);
//         if(wow.count(temp)==0)
//             wow[temp]=i;
//     }
//     return mx;
// }


