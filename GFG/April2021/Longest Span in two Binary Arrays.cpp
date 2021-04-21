int longestCommonSum(bool arr1[], bool arr2[], int n) {
        // code here 
        unordered_map<int,int> mp;
        mp[0] = -1;
        int X=0,Y=0;
        int result =0;
        for(int i=0;i<n;++i){
            X += arr1[i];
            Y += arr2[i];
            
            int diff = X - Y;
            if(mp.find(diff)==mp.end()){
                mp[diff] = i;
            }
            else{
                result = max({ result, i - mp[diff] });
            }
        }
        
        return result;
    }