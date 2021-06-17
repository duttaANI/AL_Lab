

struct Trie
{
    int val;
    Trie *child[2];
    Trie()
    {
        val=0;
        child[0]=NULL;
        child[1]=NULL;
    }
};
void insert(Trie *root,int n)
{
    Trie *p=root;
    for(int i=31;i>=0;i--)
    {
        int bit=1&(n>>i);
        if(!p->child[bit])
          p->child[bit]=new Trie();
        p=p->child[bit];  
    }
    p->val=n;
}
int query(Trie *root,int n)
{
    Trie *p=root;
    for(int i=31;i>=0;i--)
    {
        int bit=1&(n>>i);
        if(bit==0)
        {
            if(p->child[1])
              p=p->child[1];
            else
              p=p->child[0];
        }
        else
        {
            if(p->child[0])
              p=p->child[0];
            else
              p=p->child[1];
        }
    }
    return n^p->val;
}
int Solution::solve(vector<int> &A, vector<int> &B) 
{
    Trie *root=new Trie();
    for(auto x:A)
      insert(root,x);
    int res=0;  
    for(auto x:B)
    {
        res=max(res,query(root,x));
    }  
    return res;
}

