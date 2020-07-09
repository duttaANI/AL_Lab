// link: https://www.youtube.com/watch?v=0Oef3MHYEC0&feature=youtu.be
class Solution {
public:
    
    // Recursive function to return gcd of a and b 
    int gcd(int a, int b) 
    { 
        if (b == 0) 
            return a; 
        return gcd(b, a % b);  

    } 
    
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z) return false;
        //case x or y is zero
        if( x == z || y == z || x + y == z ) return true;

        //get GCD, then we can use the property of Bézout's identity
        return z%gcd(x, y) == 0;
    }
};