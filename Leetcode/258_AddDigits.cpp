class Solution {
public:
    int addDigits(int num) {
        int n = num,temp,sum,digit;
        while (  n>9){
            temp = n; sum=0;
            while(temp!=0) {
                digit = temp%10;
                sum += digit;
                temp /= 10;
            }
            n = sum;
        }
        return n;
    }
};