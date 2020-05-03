#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int start=0, end=0, maxend=0, steps=0, n=nums.size();
        
        while(end < n-1)
        {
            steps++;
            for (int i=start; i<=end; i+)
            {
                maxend = max(nums[i] + i,maxend);
            }
            
            start = end;
            end = maxend;
            
            //cout << start << " " << end << "\n";
            
        }
        
        return steps;
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
        
        int ret = Solution().jump(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
