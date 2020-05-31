class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int stone1,stone2;
        priority_queue<int> max_heap(stones.begin(), stones.end());
        while (max_heap.size()>1) {
            stone1 = max_heap.top(); max_heap.pop();
            stone2 = max_heap.top(); max_heap.pop();
            
            if(abs(stone2-stone1) !=0) 
                max_heap.push(abs(stone2-stone1));
        }
        return max_heap.size()==1? max_heap.top():0;
    }
};