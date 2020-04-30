#include <iostream>
#include <bits/stdc++.h> 
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> freq_map; //  (val_number : freq_of_number)
        for(auto &val : nums)
        {
            freq_map[val]++;
        }
        
        // create a min heap of size k  ( freq_of_number : val_number)
        priority_queue <pair <int, int>, vector<pair <int, int>>, greater<pair <int, int>>  > min_heap;
        
        for(auto &i : freq_map)
        {
            if(min_heap.size() < k)
            {
                min_heap.push( {i.second,i.first} );
            }
            else
            {
                if(i.second > min_heap.top().first)
                {
                    min_heap.pop();
                    min_heap.push( {i.second,i.first} );
                }
            }
        }
        
        vector<int> ans;
        
        while(min_heap.empty()==false)
        {
            ans.push_back(min_heap.top().second);
            min_heap.pop();
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

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        vector<int> ret = Solution().topKFrequent(nums, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}

/*
sample i/o:
[1,1,1,2,2,3]
2
[2, 1]

*/
