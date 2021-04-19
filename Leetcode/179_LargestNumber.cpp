class Solution {
public:
    
    static bool cmp( string a, string b  ){
        string s1 = a+b;
        string s2 = b+a;
        return s1>s2;
    }
    
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> str(n);
        for(int i=0;i<n;++i){
            str[i] = to_string(nums[i]);
        }
        
        sort( str.begin(), str.end(), cmp );
        
        if( str[0]=="0" ) return "0";
        
        string ans = "";
        for(int i=0;i<n;++i){
            ans += str[i];
        }
        return ans;
    }
};