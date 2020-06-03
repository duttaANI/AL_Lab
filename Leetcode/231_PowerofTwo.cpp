class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)
            return true;
        if(n<=0)
            return false;
        double a=log2(n);
        int b=a;
        if(b==a)
        {
            return true;
        }
        return false;
    }
};
// ALT 1
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
          return false;
        int ans=n&n-1;
        if(ans==0)
            return true;
        return false;
    }
};

// My code
class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if (n==0 || n<0) return false;
        
        while (n>1) {
            
            if (n%2==0 ) {
                n=n/2;
                continue;
            }
            return false;
        }
        return true;
    }
};