stack<pair<int,int>> S;
int minEle;
MinStack::MinStack() {
while(S.size()) S.pop();
minEle = INT_MAX;
}

void MinStack::push(int x) {
S.push({x,minEle});
minEle = min(x,minEle);
}

void MinStack::pop() {
if(S.empty()) return;
minEle = S.top().second;
S.pop();
}

int MinStack::top() {
if(S.empty()) return -1;
return S.top().first;
}

int MinStack::getMin() {
if(S.empty()) return -1;
return minEle;
}
