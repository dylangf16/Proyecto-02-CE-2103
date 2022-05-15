#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

class Stack {
    int top;

public:
    vector<vector<std::string>> a[MAX]; // Maximum size of Stack
    Stack() { top = -1;
    }
    bool push(vector<vector<std::string>> x);
    vector<vector<std::string>> pop();
    bool isEmpty();
};

bool Stack::push(vector<vector<std::string>> x)
{
    if (top >= (MAX - 1)) {
        a->erase(a->begin());
        top--;
        this->push(x);
    }
    else {
        a[++top] = x;
    }
    return true;
}

vector<vector<std::string>> Stack::pop()
{
    if (top < 0) {
        cout << "Stack Underflow";
        vector<vector<std::string>> x;
        return x;
    }
    else {
        vector<vector<std::string>> x = a[top--];
        return x;
    }
}

bool Stack::isEmpty()
{
    return (top < 0);
}
