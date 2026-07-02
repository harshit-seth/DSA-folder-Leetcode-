class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            // Push opening brackets
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            // Match closing brackets
            else {
                if (st.empty())
                    return false;

                if (ch == ')') {
                    if (st.top() == '(')
                        st.pop();
                    else
                        return false;
                }
                else if (ch == '}') {
                    if (st.top() == '{')
                        st.pop();
                    else
                        return false;
                }
                else if (ch == ']') {
                    if (st.top() == '[')
                        st.pop();
                    else
                        return false;
                }
            }
        }

        return st.empty();
    }
};