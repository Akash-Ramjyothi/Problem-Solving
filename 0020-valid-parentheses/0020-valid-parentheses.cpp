class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(st.empty() && (s[i]=='}' || s[i]==')' || s[i]==']'))
                return false;
            if(s[i]==')' && st.top()=='(' && st.empty()!=true)
                st.pop();
            else if(s[i]==']' && st.top()=='[' && st.empty()!=true)
                st.pop();
            else if(s[i]=='}' && st.top()=='{' && st.empty()!=true)
                st.pop();
            else
                st.push(s[i]);
        }
        return st.empty();
    }
};