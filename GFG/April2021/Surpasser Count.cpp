class Solution{
public:
    vector <int> sol;
    void merge( vector< pair<int,int> >& nums, int left , int mid, int right) {
        int p = left ,q = mid+1;
        
        for(int i = left ; i<=right ; ++i) {
            if(p > mid ){
                q++; 
            } 
            else if(q > right){
                sol[nums[p].second] += (q-mid-1);
                // cout << q << " " << mid << " " << (q-mid-1) << " ";
                p++;
            }
            else if( nums[ p ].first <= nums[ q ].first ){
                sol[nums[p].second] += (q-mid-1); // adding tot numbers in 2nd sorted array which are less than nums[p]
                // cout << q << " " << mid << " " << (q-mid-1) << " j ";
                p++;
            }
            else{
                q++;
            }
        }
        // cout << "\n";
        sort(nums.begin()+left,nums.begin()+right+1);
        // for(int i=left; i<right+1;++i){
        //     cout << nums[i].first << " ";
        // }
        // cout << "\n";
        // for(int i=0; i<sol.size(); ++i){
        //     cout << sol[i] << " ";
        // }
        // cout << "next \n";
    }
    
    void mergeSort( vector< pair<int,int> >& nums, int left , int right) {
        int mid;
        if (left < right) 
        { 
            mid = left+(right-left)/2; 
            mergeSort(nums, left, mid);
            mergeSort(nums, mid+1, right); 
            merge(nums, left, mid, right); 
        } 
    }
    
    vector<int> findSurpasser(int arr[], int n) {
        // code here
        vector<int> ans;
        int end = n;
        sol.resize(end,0);
        vector< pair<int,int> >num;
        for(int i=0 ;i <end;++i)
        {
            num.push_back({arr[i],i});
        }
        
        
        mergeSort(num,0,end-1);
        // for(int i=0; i<end; ++i) {
        //     sol[i];
        // }
        
        for(int i=0;i<n;++i){
            ans.push_back( (n-i-1 - sol[i]) );
        }
        return ans;
    }
};