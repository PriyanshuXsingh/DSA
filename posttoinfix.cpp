#include<bits/stdc++.h>
using namespace std;
    string postToInfix(string exp) {
       
        stack<string>st;
        for(int i=0;i<exp.size();i++)
        {
            if(isalpha(exp[i])||isdigit(exp[i]))
            {
                st.push(string(1,exp[i]));
            }
            else
            {
                string t1 = st.top(); st.pop();
                string t2 = st.top(); st.pop();
                st.push('(' + t2 + exp[i] + t1 + ')');
                
            }
        }
        return st.top();
    }
int main()
    {
        string s;
        cout<<"provide input expression: ";
        cin>>s;
        cout<<"postToInfix: "<<postToInfix(s);
        return 0;
    }