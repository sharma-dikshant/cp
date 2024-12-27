/*
    Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the
    result of the evaluation.

    ?Example 1:
    Input: s = "1 + 1"
    Output: 2

    ?Example 2:
    Input: s = " 2-1 + 2 "
    Output: 3

    ?Example 3:
    Input: s = "(1+(4+5+2)-3)+(6+8)"
    Output: 23

 */

/*
    for s[i] there are given possiblilities and what to do at that situation

    1. digit
        keep making number

    2. '+'
        add the number formed till + to result
        num = 0
        sign = +1

    3. '-'
        add the number formed till - to result
        num = 0
        sign = -1

    4. '('
        push result to stack
        then push sign to stack
        result = 0
        sign = +1

    5. ')'
        firstly add the solution of current bracket to result

        now, add this result to the previous result which is stored in the stack
        and reset the variables
        number = 0
        sign = 1
*/

#include <bits/stdc++.h>
using namespace std;

int calculate(string &s)
{
    stack<int> st;
    int n = s.length();
    int number = 0;
    int result = 0;
    int sign = 1;

    for (int i = 0; i < n; i++)
    {
        if (isdigit(s[i]))
        {
            number = number * 10 + (s[i] - '0');
        }
        else if (s[i] == '+')
        {
            result += (number * sign);
            sign = 1;
            number = 0;
        }
        else if (s[i] == '-')
        {
            result += (number * sign);
            sign = -1;
            number = 0;
        }
        else if (s[i] == '(')
        {
            // new story of bracket has to begin so store the current result and sign and result everything for new story
            st.push(result);
            st.push(sign);
            number = 0;
            result = 0;
            sign = 1;
        }
        else if (s[i] == ')')
        {
            // now story of the last opening bracket has completed so firstly add the result of the current bracket to result

            result += (number * sign);
            number = 0;
            sign = 1;

            int st_sign = st.top();
            st.pop();
            int st_result = st.top();
            st.pop();

            result *= st_sign;
            result += st_result;
        }
    }

    // if the string is 1+2 then at the last iteration, we've just formed the last number and yet to add to result if there is any

    result += (number * sign);

    return result;
}

int main()
{
    string s = "1 + (1 + 2) - 1";
    cout << calculate(s);
    return 0;
}