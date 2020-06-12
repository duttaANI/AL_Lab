class Solution {
public:
    int result = 0;
    int hammingWeight(uint32_t n) {         
        if(n & 1)
        {
            result++;
        }
        if(n == 0) return result;        
       return hammingWeight(n>>1);      
    }    
};