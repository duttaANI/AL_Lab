class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0)return false;
        map<int,int> freq_map;
        int tot_ele = nums.size();
        for(auto & n : nums){
            freq_map[n]++;
        }
        
        vector<int> check;
        while(tot_ele>0){
            std::map<int,int>::iterator it = freq_map.begin();
            for(int i=0; i<k; ++i , ++it ){
                if(it->second>0){
                    
                    check.push_back(it->first);
                    it->second--;
                    --tot_ele;
                }else if (it->second==0){
                    freq_map.erase(it->first);
                    --i;
                }else{
                    return false;
                }
            }
        }
        
        //print check
        // for(int i=0; i<check.size(); ++i){
        //     cout << check[i] << " ";
        // }
        // cout << "\n";
        int j;
        for(int i=0; i<check.size(); i=j){
            for(j =i+1; j<i+k; ++j){
                if(check[j]-check[j-1]!=1){
                    // cout << j << " " << i << "\n";
                    return false;
                }
            }
        }
        
        return true;
    }
};