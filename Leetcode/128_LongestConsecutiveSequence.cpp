class Solution {
public:
    int longestConsecutive(vector<int>& num) {
        set<int> s;
        for(int i : num){
            s.insert(i);
        }
        int longestStreak = 0;
        for(int n : s){
            if(s.find(n-1)==s.end()){
                int curNum = n;
                int curStreak =1;
                
                while(s.find(curNum+1)!=s.end()){
                    curNum += 1;
                    curStreak +=1;
                }
                
                longestStreak = max({longestStreak,curStreak});
            }
        }
        return longestStreak;
    }
};