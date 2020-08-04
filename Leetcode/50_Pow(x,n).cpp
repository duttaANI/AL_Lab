// link : https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-1/tutorial/

class Solution {
public:
    
    double binaryExponentiation( double x, long long int n ){
        if( n==0 ) return 1;
        if( n%2==0 ){
            return binaryExponentiation( x*x , n/2  );
        }else{
            return x*binaryExponentiation( x*x, (n-1)/2 );
        }
    }
    
    double myPow(double x, long long int n) {
        
        if( n<0 ){
            x = 1/x;
            n = -1*n;
        }
        
        return binaryExponentiation( x,n );
    }
};