#include <iostream>
#include <regex>
#include <vector>
#include <cctype>
#include <string>
#include "stack.h"

using namespace std;

void split(const string& input, vector<string>& vec)
{
    regex exp(R"((\d+)|(\s)|(.))");
    smatch match;
    string s = input;

    while(regex_search(s, match, exp)) {
        if (match[2] == "") {
            vec.push_back(match[0]);
        }
        s = match.suffix();
    }
}

bool has_higher_or_equal_precedence(
        const string& stack_top, const string& other) {
    return !((stack_top == "+" || stack_top == "-")
            && (other == "*" || other == "/"));
}


// Time complixity: O(N)
string infix_to_postfix(const string& expr)
{
    Stack<string> st;
    vector<string> res;
    vector<string> vec_expr;

    split(expr, vec_expr);

    for (string item: vec_expr) {
        if (isdigit(item[0])) {
            res.push_back(item);
        } else if (item == "(") {
            st.push(item);
        } else if (item == "+"
                || item == "-"
                || item == "*"
                || item == "/") {
            while (!st.is_empty()
                    && st.peek() != "(") {
                if (has_higher_or_equal_precedence(
                        st.peek(), item)) {
                    string x = st.pop();
                    res.push_back(x);
                } else {
                    break;
                }
            }
            st.push(item);
        } else if (item == ")") {
            while (!st.is_empty()
                    && st.peek() != "(") {
                string x = st.pop();
                res.push_back(x);
            }
            if (!st.is_empty()) {
                st.pop();
            }
        }
    } // for

    while (!st.is_empty()) {
        string x = st.pop();
        res.push_back(x);
    }

    string result = "";
    bool first = true;
    for (string x: res) {
        if (first) {
            first = false;
        } else {
            result += " ";
        }
        result += x;
    }
    return result;
}

int main()
{
    cout << ("42" ==
             infix_to_postfix("42")) << endl;
    cout << ("1 2 +" ==
             infix_to_postfix("1 + 2")) << endl;
    cout << ("1 2 * 3 +" ==
             infix_to_postfix("1 * 2 + 3")) << endl;
    cout << ("1 2 + 3 + 4 +" ==
             infix_to_postfix("1 + 2 + 3 + 4")) << endl;
    cout << ("1 2 +" ==
             infix_to_postfix("(1 + 2)")) << endl;
    cout << ("1 2 3 4 + + +" ==
             infix_to_postfix("(1 + (2 + (3 + 4)))")) << endl;
    cout << ("1 2 3 * +" ==
             infix_to_postfix("1 + 2 * 3")) << endl;
    cout << ("1 2 + 3 *" ==
             infix_to_postfix("(1 + 2) * 3")) << endl;
    cout << ("1 2 3 * + 4 +" ==
             infix_to_postfix("1 + 2 * 3 + 4")) << endl;
    cout << ("1 2 + 3 4 + *" ==
             infix_to_postfix("(1 + 2) * (3 + 4)")) << endl;
    cout << ("1 2 + 3 4 * 5 / -" ==
             infix_to_postfix("1 + 2 - 3 * 4 / 5")) << endl;
    cout << ("1 2 / 3 * 4 - 5 +" ==
             infix_to_postfix("1 / 2 * 3 - 4 + 5")) << endl;
    cout << ("1 2 / 3 4 * - 5 +" ==
             infix_to_postfix("1 / 2 - 3 * 4 + 5")) << endl;
    cout << ("1 2 3 - + 4 5 / *" ==
             infix_to_postfix("(1 + (2 - 3)) * (4 / 5)")) << endl;
    cout << ("1 2 3 - / 4 5 + *" ==
             infix_to_postfix("1 / (2 - 3) * (4 + 5)")) << endl;
    cout << ("1 2 3 - 4 5 + * /" ==
             infix_to_postfix("1 / ((2 - 3) * (4 + 5))")) << endl;
    cout << ("1 2 3 4 * - 5 + /" ==
             infix_to_postfix("1 / (2 - 3 * 4 + 5)")) << endl;
    cout << ("42" ==
             infix_to_postfix("(42)")) << endl;
    cout << ("42" ==
             infix_to_postfix("(((42)))")) << endl;
    cout << ("1 2 +" ==
             infix_to_postfix("(1 + 2)")) << endl;
    cout << ("1 2 *" ==
             infix_to_postfix("(((1) * (2)))")) << endl;

}