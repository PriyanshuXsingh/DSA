

#include<bits/stdc++.h>
using namespace std;
  
 string preToInfix(string pre_exp) {
       
        stack<string>st;
       for(int i=pre_exp.length()-1;i>=0;i--)
        {
            if(isalpha(pre_exp[i]))
            {
              st.push(string(1, pre_exp[i]));
            }
            else
            {
                
                string t1=st.top(); st.pop();
                string t2= st.top(); st.pop();
                string con = '(' + t1 + pre_exp[i] + t2 + ')';
                st.push(con);
            } 
            
        }
        
        return st.top();
    }
int main()
    {
        string s;
        cout<<"provide input expression: ";
        cin>>s;
        cout<<"preToInfix: "<<preToInfix(s);
        return 0;
    }