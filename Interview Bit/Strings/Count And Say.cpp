string Solution::countAndSay(int n) {
    if(n==1)    return "1";
    string s = "11";
    if(n==2)    return s;
    int i=3,j,count;   
    
    while(i<=n){
        int x=s.size();
        char y=s[0];
        count=1;
        string ans;
        for(j=1;j<x;j++){
            if(s[j]==y){
                count++;
            }
            else{
                ans+=48+count;
                ans+=y;
                y=s[j];
                count=1;
            }
        }
        ans+=48+count;
        ans+=y;
        s=ans;
        i++;   
    }    
    return s;
}