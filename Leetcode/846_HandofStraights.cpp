// link : https://www.youtube.com/watch?v=K7n_BQihPCM
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if (hand.size()%W !=0) return false;
        map<int,int> card_count;
        for (auto card : hand){
            // cout << card << " ";
            card_count[card]++;
        }
        while(card_count.size()>0){
            int first = card_count.begin()->first;
            for (int card = first; card < first + W; ++card) {
                if(card_count.find(card)==card_count.end()) return false;
                int c = card_count[card];
                if(c==1) card_count.erase(card);
                else
                    card_count[card] = c-1;
            }
        }
        return true;
    }
};