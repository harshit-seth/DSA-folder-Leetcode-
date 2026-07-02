class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {

            // Agar opening bracket hai to stack me daal do
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {

                // Closing bracket mila lekin stack khali hai
                // Matlab koi matching opening bracket nahi hai
                if (st.empty())
                    return false;

                // Har closing bracket ke liye top check karo
                if (ch == ')') {
                    if (st.top() == '(')
                        st.pop();   // Match mil gaya
                    else
                        return false;
                }
                else if (ch == '}') {
                    if (st.top() == '{')
                        st.pop();   // Match mil gaya
                    else
                        return false;
                }
                else if (ch == ']') {
                    if (st.top() == '[')
                         st.pop();   // Match mil gaya
                    else
                        return false;
                }
            }
        }

        // Agar stack empty hai to saare brackets sahi match hue
        return st.empty();
    }
};