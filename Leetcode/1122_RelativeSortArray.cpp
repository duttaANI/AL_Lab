// link : https://leetcode.com/problems/relative-sort-array/discuss/364612/C%2B%2B-Map-Solution
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> freq_map;
        for (auto& i: arr1) {
            freq_map[i]++;
        }
        int pos = 0;
        for (int i=0; i<arr2.size(); ++i){
            while(freq_map[arr2[i]]-- > 0) arr1[pos++] = arr2[i];
        }
        for (auto it : freq_map){
            while(it.second-- >0) arr1[pos++]=it.first;
        }
        
        return arr1;
    }
};