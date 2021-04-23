class Solution{   
public:
    vector<int> repeatingEven(int arr[], int n) {
        // code here
        vector<int> ans(0,0);
        
        unsigned long long int Xor=0;
        for(int i=0;i<n;++i){
            Xor ^= (1ULL<<arr[i]);
        }
        
        for(int i=0;i<n;++i){
            if( !(Xor & (1ULL<<arr[i]))  ){
                ans.push_back(arr[i]);
                Xor |= (1ULL << arr[i]); // to avoid duplicates
            }
        }
        // cout << "1 hello\n";
        
        if(ans.size()==0){
            // cout << "1 hello\n";
            ans.push_back(-1);
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};