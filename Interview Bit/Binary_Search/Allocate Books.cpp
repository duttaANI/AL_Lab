#define ll long long
#include <bits/stdc++.h>
/*
 simple simulation approach
   intially Sum := 0
   cnt_of_student = 0
   iterate over all books:
        If Sum + number_of_pages_in_current_book > V :
                  increment cnt_of_student
                  update Sum
        Else:
                  update Sum
   EndLoop;

*/
int std_reqd(vector<int> &A,int V){
    int sum =0, std_cnt =0;
    for(int i=0; i<A.size(); ){
        if(sum + A[i]>V){
            sum =0;
            std_cnt++;
        }else{
            sum += A[i];
            ++i;
        }
    }
    if(sum>0) ++std_cnt;
    return std_cnt;
}



int Solution::books(vector<int> &v, int k) {
    if(v.size()<k)
        return -1;
        
    int maxi=0,sum=0;
    for(auto i:v){
        maxi=max(maxi,i);
        sum+=i;
    }
    
    int l=maxi,r=sum,ans=maxi;
    while(l<=r){
        int mid=l+(r-l)/2;
        int s=std_reqd(v,mid);
        if(s>k){
            l=mid+1;
        }
        else if(s<k){
            r=mid-1;
        }
        else{
            ans=mid;
            r=mid-1;
        }
    }
    return ans;
    
}


