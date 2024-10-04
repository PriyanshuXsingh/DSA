#include<bits/stdc++.h>
using namespace std;
int prec(char c)
{
    if(c=='^')return 3;
    else if(c=='*'||c=='/')return 2;
    else if(c=='+'||c=='-')return 1;
    else return -1;
}
string infixtoprefix(string s)
{
    stack<char>st;
    string ans;
    
   reverse(s.begin(), s.end());
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') s[i] = ')';
        else if(s[i] == ')') s[i] = '(';
    }
   int i=0;
    while(i<s.size())
    {
        if(isalpha(s[i])||isdigit(s[i]))
        {
            ans=ans+s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(!st.empty() && st.top()!='(')
            {
                ans=ans+st.top();
                st.pop();
            }
            if(!st.empty())st.pop();
        }
        else
        {
          if(s[i]=='^')
          {
            while(!st.empty() && prec(s[i])<=prec(st.top()))
            {
              ans=ans+st.top();
              st.pop();
            }
          }
          else{
            while(!st.empty() && prec(s[i])<prec(st.top()))
            {
                ans=ans+st.top();
                st.pop();
            }
          }
          st.push(s[i]);
        }
        i++;
    }
    while(!st.empty())
    {
        ans=ans+st.top();
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main()

{
    string s;
     cout<<"provide a input expression: ";
     cin>>s;
   cout<<"infix to prefix is: "<< infixtoprefix(s);
   return 0;
}