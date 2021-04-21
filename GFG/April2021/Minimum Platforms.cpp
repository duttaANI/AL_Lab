class Solution{
    
    public:
   
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr,arr+n);
    	sort(dep,dep+n);
        int pf=1;
        int j=0;
        for(int i=1;i<n;++i){
            if(arr[i]<=dep[j]){
                pf++;
            }else{
                j++;
            }
        }
     
        return pf;
    	
    }
};


////

int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr,arr+n);
        sort(dep,dep+n);
        int pf=1;
        int res = 1;
        int j=0,i=1;
        while( i<n && j<n ){
            if(arr[i]<=dep[j]){
                pf++;
                ++i;
                res = max({res,pf});
            }else{
                j++;
                --pf;
            }
        }
     
        return res;
        
    }