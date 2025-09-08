class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int result = 0;

        for(char &ch : s) {
            if(ch == '(') {
                st.push(ch);
                result = max(result, (int)st.size());
            } else if(ch == ')') { 
                st.pop();
            }
        }
        return result;
    }
};
