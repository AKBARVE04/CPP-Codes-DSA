// You are given a stack/deque of integers 'MY-STACK' and an
// integer 'X'. Your task is to insert X to the bottom of 'MY-STACK'
// and return the updated stack/deque.

#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &s, int x)
{
    // base case
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    // recursive call

    solve(s, x);

    s.push(num);
}

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);
    return myStack;
}