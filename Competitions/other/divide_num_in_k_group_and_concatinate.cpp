string reduce_number_in_k_groups(string number,int k ){
	while(number.size()>k){
		string newNum = "";
		int currSum = 0;
		for(int i=0;i<number.size();i++){
			currSum += number[i] - '0';
			if((i+1)%k==0){
				newNum += to_string(currSum);
				currSum = 0;
			}
		}
		if(currSum) newNum += to_string(currSum);
		number = newNum;
	}
	return number
}