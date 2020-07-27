#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define intl long long
using namespace std;

/*
if (e1.primary != e2.primary) {
    return e1.primary < e2.primary;
  }
  return e1.secondary < e2.secondary;
  */

static bool cmp ( vector<intl> a,  vector<intl> b) {  // sort in order of left point of each interval
    if(a[0]!=b[0])
        return (a[0] < b[0]);   //||(a[0]==b[0] && a[1]<b[1]);
    else
        return (a[1]>b[1]);
}

// Key concept => we dont care who is leaving and when

int main() {
    
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    intl N,a,b;
    cin >> N;
    intl ans=0,cur=0;
    vector<vector<intl>>intervals (0 , vector<intl> (2,0) ); // 1 for arrival , -1 for departure
    
    for(int i=0; i<N; ++i){
        cin >> a >> b;
        intervals.push_back({a,1});
        intervals.push_back({b,-1});
    }
    sort(intervals.begin(),intervals.end(),cmp);
    // for(auto & r : intervals){
    //     cout << r[0] << " " << r[1] << "\n";
    // }
    for(int i=0; i<N; ++i){
        if(intervals[i][1]==1) ++cur;
        else --cur;
        //cout << cur << " ";
        if(cur>ans)
            ans=cur;
    }
    cout << ans;
    
    return 0;
}
