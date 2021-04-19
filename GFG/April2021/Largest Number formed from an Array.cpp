class Solution{
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	
	static bool cmp( string a, string b  ){
        string s1 = a+b;
        string s2 = b+a;
        return s1>s2;
    }
	
	string printLargest(vector<string> &str) {
	    // code here
	    int n = str.size();
	    sort( str.begin(), str.end(), cmp );
        
        if( str[0]=="0" ) return "0";
        
        string ans = "";
        for(int i=0;i<n;++i){
            ans += str[i];
        }
        return ans;
	    
	    
	}
};