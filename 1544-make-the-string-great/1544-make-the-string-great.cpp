class Solution {
public:
    string makeGood(string s) {
         stack<char>st;
        for(int i = 0;i<s.size();i++)
        {
            if(!st.empty() &&  st.top() != s[i] && tolower(st.top()) == tolower(s[i]))
            st.pop();
            else{
                st.push(s[i]);
            }
            
        }
        string ans="";
            while(!st.empty()){
                ans = st.top()+ans;
                st.pop();

            }


        return ans;
    }
};