
// 60 ms soln Bidirectional BFS
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return 0;
        int l=beginWord.length();
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        
        int step = 0;
        while(!q1.empty() && !q2.empty()){
            ++step;
            //always expend the smaller queue first
            if(q1.size() > q2.size()){
                std::swap(q1,q2);
            }
            unordered_set<string> q;
            for(string w: q1){
                for(int i=0; i<l; i++){
                    char ch =w[i];
                    for(int j = 'a'; j<='z';++j){
                        w[i] = j;
                        if(q2.count(w)) return step+1;
                        if(!dict.count(w)) continue;
                        
                        dict.erase(w);
                        q.insert(w);
                    }
                    w[i] = ch;
                }
            }
            std:: swap(q,q1);
        }
        return 0;
    }
};


// 1260ms soln normal BFS

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        int ladder = 1;
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                string word = todo.front();
                todo.pop();
                if (word == endWord) {
                    return ladder;
                }
                dict.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end()) {
                            todo.push(word);
                        }
                     }
                    word[j] = c;
                }
            }
            ladder++;
        }
        return 0;
    }
};
