class Solution {
public:

	vector<int> ComputeWithDP( string input , unordered_map< string , vector<int> >& mp ){
		int n = input.length();
		vector<int> output,result1,result2;
		for( int i=0; i<n ; ++i ){
			if( ispunct(input[i]) ){
				if( mp.find(input.substr(0,i))!= mp.end() ){
					result1 = mp[input.substr(0,i)];
				}else{
					result1 = ComputeWithDP( input.substr(0,i),mp );
				}
				if( mp.find(input.substr(i+1))!= mp.end()  ){
					result2 = mp[input.substr(i+1)];
				}else{
					result2 = ComputeWithDP( input.substr(i+1),mp );
				}

				for(int a : result1){
					for(int b : result2){
						if( input[i]=='+' ){
							output.push_back(a+b);
						}else if ( input[i]=='-' ){
							output.push_back(a-b);
						}else if( input[i]=='*' ){
							output.push_back(a*b);
						}
					}
				}
			}
		}
        if( output.size() ){
            mp[input]=output;
        }else{
            mp[input] = vector<int> {stoi(input)};
        }
		
		return output.size()? output : vector<int>{stoi(input)};
	}

    vector<int> diffWaysToCompute(string input) {
    	unordered_map< string , vector<int> > mp;
        return ComputeWithDP( input , mp );
    }
};