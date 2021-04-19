class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    
	    if(n==1) return {0,0};
	    // code here
	    vector<int> arr2(n,0);
	    for(int i=0;i<n;++i){
	        arr2[i] = arr[i];
	    }
	    
	    sort(arr2.begin(),arr2.end());
	    
	    int l=0, r = n-1;
	    while( arr[l] == arr2[l] ){
	       // cout << arr2[l] << " ";
	        ++l;
	    }
	   // cout << endl;
	    while( arr[r]==arr2[r] ){
	       // cout << arr[r] << " ";
	        --r;
	    }
	   // cout << endl;
	    
	    vector<int> ans;
	    
	    ans.push_back(l);
	    ans.push_back(r);
	    
	    return ans;
	}
};