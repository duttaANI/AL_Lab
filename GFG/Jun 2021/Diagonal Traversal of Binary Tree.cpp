vector<int> diagonal(Node *root)
{
   // your code here
   vector<int> ans;
   queue<Node *> q;
   q.push(root);
   
   while(q.size()){
       Node * f = q.front(); q.pop();
       while(f){
           ans.push_back(f->data);
           if(f->left){
               q.push(f->left);
           }
           f = f->right;
       }
   }
   
   return ans;
}