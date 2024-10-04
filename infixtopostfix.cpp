#include<bits/stdc++.h>
using namespace std;
int prec(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;}
    string infixToPostfix(string s) {
        // Your code here
        stack<char>st;
        string ans;
        int i=0;
        while(i<s.size())
        {
            if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')||(s[i]>='0'&&s[i]<='9'))
            {
                ans=ans+s[i];
            }
            else if(s[i]=='(')
            {
               st.push('('); 
            }
            else if(s[i]==')')
            {
                while(st.top()!='(')
                {
                    ans = ans + st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                while(!st.empty()&&prec(s[i])<=prec(st.top()))
                {
                    ans = ans + st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
            i++;
        }
        while(!st.empty())
        {
            ans = ans + st.top();
            st.pop();
        }
        return ans;
    }
    int main()
    {
        string s;
        cout<<"provide input expression: ";
        cin>>s;
        cout<<"infix to postfix: "<<infixToPostfix(s);
        return 0;
    }