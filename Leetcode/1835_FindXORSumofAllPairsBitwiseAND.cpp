// Distributive property is similar for AND and XOR here.
// (a1^a2) & (b1^b2) = (a1&b1) ^ (a1&b2) ^ (a2&b1) ^ (a2&b2)
class Solution {
public:
    int getXORSum(vector<int>& A, vector<int>& B) {
        int xora = 0, xorb = 0;
        for (int& a: A)
            xora ^= a;
        for (int& b: B)
            xorb ^= b;
        return xora & xorb;
        
    }
};
