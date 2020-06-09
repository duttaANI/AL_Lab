class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set <int> top3;
        for (auto num : nums) {
            top3.insert(num);
            if (top3.size()>3) 
                top3.erase(top3.begin());
            
        }
        return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
        // rbegin means last
    }
};
