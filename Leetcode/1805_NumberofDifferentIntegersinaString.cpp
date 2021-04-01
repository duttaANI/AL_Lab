
class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> s;
        string temp = "";
        int n = word.size(),j=0;
        for(int i=0; i<n ;){
            while( i<n && isdigit(word[i] ) ){
                temp += word[i];
                ++i;
            }
            
            j=0;
            while( temp.size()>1 && j<temp.size() ){
                if(temp[j]=='0'){
                    temp.erase(j, 1);
                }
                else{
                    break;
                }
            }
            // cout << temp << endl;
            if(temp.size())
                s.insert(temp);
            temp = "";
            ++i;
        }
        return s.size();
    }
};