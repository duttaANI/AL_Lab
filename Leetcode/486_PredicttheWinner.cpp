// Player 1 will try to maximise term " _{Player\_1} - score_{Player\_2} " and player2 will try to minimise it
// turn =1 => player1 will choose , turn =-1 => Player2 will choose
class Solution {
public:
    
    int winner(vector<int>& nums, int s, int e, int turn) {
        if(s == e) return turn*nums[s];
        
        int a = turn * nums[s] + winner(nums, s + 1, e, -turn);  //changing sign of turn
        int b = turn * nums[e] + winner(nums, s, e - 1, -turn);
        
        return turn == 1 ? max(a, b) : min(a, b);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        return winner(nums, 0, nums.size()-1, 1)>=0;
    }
};