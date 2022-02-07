class Solution {
public:
    #define ll long long
    long long smallestNumber(long long num) {
        int neg = 0,z=0;
        ll ans =0;
        if(num==0) return 0;
        if(num<0){
            neg = 1;
            num *= -1;
        }
        vector<int> dig;
        while(num){
            int d = num%10;
            num/=10;
            if(d==0){
                ++z;
                continue;
            }
            dig.push_back(d);
        }
        
        sort(dig.begin(),dig.end());
        
        if(neg){
            // cout << "neg\n";
            reverse(dig.begin(),dig.end());
            
            for(int i=0;i<dig.size();++i){
                ans = ans*10 + dig[i];
            }
            ans = ans*pow(10,z);
            return (-1*ans);
        }
        else{
            ans = dig[0];
            ans = ans*pow(10,z);
            for(int i=1;i<dig.size();++i){
                ans = ans*10 + dig[i];
            }
            return ans;
        }
        
           
    }
};