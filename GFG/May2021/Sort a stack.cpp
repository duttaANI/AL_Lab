void SortedStack :: sort()
{
   //Your code here
   
   stack<int> tmpStack;

    while (!s.empty())
    {
        // pop out the first element
        int tmp = s.top();
        s.pop();

        // while temporary stack is not empty and top
        // of stack is greater than temp
        while (!tmpStack.empty() && tmpStack.top() > tmp)
        {
            // pop from temporary stack and push
            // it to the s stack
            s.push(tmpStack.top());
            tmpStack.pop();
        }

        // push temp in tempory of stack
        tmpStack.push(tmp);
    }
    
    s = tmpStack;

    // return tmpStack;
}