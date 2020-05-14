class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> char_map(26,0);
        for(int i=0;i<tasks.size();++i){
            char_map[tasks[i]-'A']++;
        }
        sort(char_map.begin(),char_map.end());
        
        int max_val = char_map[25]-1 , idle_slots = max_val*n;
        
        for(int i=24;i>=0;i--){
            idle_slots -= min(char_map[i],max_val);
        }
        return idle_slots>0? idle_slots + tasks.size() : tasks.size();
    }
};