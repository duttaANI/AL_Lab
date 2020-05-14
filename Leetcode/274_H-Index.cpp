class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int max=0;
        for(int i=0;i<citations.size();++i)
        {
            if(max<citations[i])
                max=citations[i];
        }
        
        vector<int> freq_map(max+1,0); 
        
        for(int i=0;i<citations.size();++i)
        {
            
            freq_map[citations[i]]++; // i.e if there are 4 papers having n citations then freq_map[n] = 4
        }
        
        vector<int> accumulative (max+2,0);
        accumulative[max+1] = 0;
        
        for(int i=max;i>=0;--i)
        {
            accumulative[i] = accumulative[i+1] + freq_map[i];  // keeps count of all papers having citation >= i
        }
        
        int max_i=0;
        for(int i=0;i<max+1;++i)
        {
            if(accumulative[i]>=i && i>max_i)
                max_i = i;
        }
        
        return max_i;
    }
};