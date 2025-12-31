#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isOperator(string s) {
        return (s == "+" || s == "-" || s == "*" || s == "/");
    }

    int eval(int a, int b, string op) {
        if (op == "+") return b + a;
        if (op == "-") return b - a;
        if (op == "*") return b * a;
        return b / a; 
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (int i = 0; i < tokens.size(); i++) {
            if (isOperator(tokens[i])) {
                int a = s.top(); s.pop();
                int b = s.top(); s.pop();
                s.push(eval(a, b, tokens[i]));
            } else {
                s.push(stoi(tokens[i]));
            }
        }

        return s.top();
    }
};
