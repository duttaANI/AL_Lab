vector<int> findSpiral(Node *root)
{
    //Your code here
    // bfs
    vector<int> ans;
    
    if(root==NULL) return {};
    
    queue<Node* > q;
    q.push(root);
    int flg = 0;
    
    while(q.size()){
        int k = q.size();
        vector<int> temp;
        temp.clear();
        for(int i=0;i<k;++i){
            
            Node * f = q.front(); q.pop();
            if( f->left ) q.push(f->left);
            if( f->right ) q.push(f->right);
            temp.push_back(f->data);
        }
        if(flg){
            for(int i=0;i<temp.size();++i){
                ans.push_back(temp[i]);
            }
        }
        else{
            int n = temp.size();
            for(int i= n-1;i>=0;--i){
                ans.push_back(temp[i]);
            }
        }
        flg=!flg;
    }
    return ans;
}