#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    // int min_(int x,int y)
    // {
    //     if(x<y)
    //         return x;
    //     return y;
    // }
    
    int trap(vector<int>& height) {
        vector<int> left_dir(height.size(),0);
        vector<int> right_dir(height.size(),0);
        int max=0;
        for(int i=0;i<height.size();++i)// towards right_dir
        {
            if(max<height[i])
                max=height[i];
            //cout << max << " ";
            right_dir[i]=max;
        }
        
        max=0;
        for(int i=height.size()-1;i>=0;--i)// towards left_dir
        {
            if(max<height[i])
                max=height[i];
            //cout << max << " ";
            left_dir[i]=max;
        }
        
        int ans=0;
        
        for(int i=0;i<height.size();++i)
        {
            ans = ans + min(right_dir[i],left_dir[i]) - height[i];
            //cout << min_(right_dir[i],left_dir[i]) << " ";
        }
        
        return ans;
        
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
        vector<int> height = stringToIntegerVector(line);
        
        int ret = Solution().trap(height);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}