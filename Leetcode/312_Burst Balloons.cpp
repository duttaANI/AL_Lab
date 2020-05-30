// link : https://www.youtube.com/watch?v=IFNibRVgFBo
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        
        if(nums.size()==0) return 0;
        
        vector<vector<int> > dp( nums.size() , vector<int> (nums.size(), 0));
        
        for(int len=1; len<=nums.size(); ++len) {
            
            for(int i=0; i<=nums.size()-len; ++i) { // iterate over all subarrays of size = len
                
                int j=i+len-1;
                
                for(int k=i; k<=j ;++k) { // k indicates which balloon is bursted last. 
                    
                    int leftValue = 1; int rightValue = 1;
                    if( i!=0 ) leftValue = nums[i-1];
                    if( j!=nums.size()-1 ) rightValue = nums[j+1];
                    int before = 0, after = 0;
                    if(i!=k) before = dp[i][k-1];  //since i<k-1
                    if(j!=k) after =  dp[k+1][j];  //since j>k+1
                    
                    dp[i][j] = max(before + leftValue*nums[k]*rightValue + after,dp[i][j]); // recursive relation
                }
            }
        }
        return dp[0][nums.size()-1];
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().maxCoins(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}