vector <int> zigZagTraversal(Node* root)
{
	// Code here
	vector<int> ans;
	
	queue<Node*> q;
	q.push( root );
	int flg = 1; // 1 -> right , 0-> left
	
	while( !q.empty() ){
	    int k = q.size();
	    vector<int> temp(k,0);
	    for( int i=0; i<k; ++i  ){
	        temp[i] = q.front()->data; 
	        if( q.front()->left )
	        q.push(q.front()->left);
	        if( q.front()->right )
	        q.push(q.front()->right);
	        q.pop();
	    }
	    if( !flg ){
	        reverse( temp.begin(), temp.end() );
	        
	    }
	    flg = !flg;
	    for( int i=0; i<k; ++i ){
	        ans.push_back(temp[i]);
	    }
	}
	
	return ans;
}