class Solution{
    public:
    // This function wants you to modify the given input
    // array and no need to return anything
    // arr: input array
    // n: size of array
    //Function to rearrange  the array elements alternately.
    
    void rearrange(long long *arr, int n) 
    { 
    	
    	// Your code here
    	//TLE code
    // 	int flg = 1;
    // 	for( int i=0;i<n;++i ){
    // 	    if( flg ){
    // 	        swap( arr[i], *max_element( arr+i, arr+n ) );
    // 	    }
    // 	    else{
    // 	        swap( arr[i], *min_element( arr+i, arr+n ) );
    // 	    }
    // 	    flg = !flg;
    // 	}
        vector<long long> a(n,0),b(n,0);
        for(int i=0;i<n;++i){
            a[i] = arr[i];
            b[i] = arr[i];
        }
   
    	int j=0;
    	for( int i=0; i<n/2+1;  ){
    	    if(j<n){
    	        arr[j] = a[n-i-1];
        	    ++j;
    	    }
        	if(j<n){
        	    arr[j] = a[i];
        	    ++j;
        	}  
        	    
    	    ++i;
    	}
    }
};
