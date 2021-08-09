class WordDictionary {
public:
    
    class Trie{
        public:
            Trie *arr[26];
            bool isEnd = false;
    };
    
    Trie* root;
    
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        Trie *cur = root;
        for(int i=0; i<word.size(); ++i){
            int x = word[i]-'a';
            if(cur->arr[x] == NULL) cur->arr[x] = new Trie();
            cur=cur->arr[x];
        }
        cur->isEnd = true;
        return;
    }
    
    bool search(string word, Trie *tempRoot = NULL) {
        Trie *cur = NULL;
        if(!tempRoot) cur = root;
        else cur = tempRoot;
        
        for(int i=0; i<word.size(); ++i){
            char ch = word[i];
            if(ch=='.'){
                for(int j=0; j<26; ++j){
                    if(cur->arr[j] && search(word.substr(i+1, word.size()-i), cur->arr[j])) return true;
                }
                return false;
            }else{
                int idx = ch-'a';
                if(cur->arr[idx]==NULL) return false;
                cur=cur->arr[idx];
            }
        }
        return cur->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
