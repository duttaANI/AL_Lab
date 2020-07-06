// link : https://www.youtube.com/watch?v=jfmJusJ0qKM
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        int score = 0;
        for (int i=0 ; i<S.length();++i){
            if(S[i]=='(') {
                s.push(score);
                score = 0;
            }else {
                score = s.top() + max(score*2,1);
                s.pop();
            }
        }
        return score;
    }
};