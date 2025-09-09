// postfix evaluation using stack.
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int evaluatePostfix(const string& expr) {
    stack<int> s;
    istringstream iss(expr);
    string token;
    while (iss >> token) {
        if (isdigit(token[0]) || 
            (token.length() > 1 && token[0] == '-' && isdigit(token[1]))) {
            s.push(stoi(token));
        } else {
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            if (token == "+") s.push(val1 + val2);
            else if (token == "-") s.push(val1 - val2);
            else if (token == "*") s.push(val1 * val2);
            else if (token == "/") s.push(val1 / val2);
        }
    }
    return s.top();
}

int main() {
    cout << "Enter postfix expression (tokens separated by spaces): ";
    string expr;
    getline(cin, expr);
    int result = evaluatePostfix(expr);
    cout << "Result: " << result << endl;
    return 0;
}