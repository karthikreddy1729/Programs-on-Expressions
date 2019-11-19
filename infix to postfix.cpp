#include<bits/stdc++.h>
#include<stack>
using namespace std;
int prec(char i)
{
    if(i=='+' || i=='-')
    {
        return 1;
    }
    if(i=='*' || i=='/')
    {
        return 2;
    }
    return 0;
}
int main()
{
    cout<<"enter the expression\n";
    char s[100],t[100];
    int j=0;
    cin>>s;
    int n=strlen(s);
    s[n+2]='\0';
    s[n+1]=')';
    int i=0;
    for(i=n;i>0;i--)
    {
        s[i]=s[i-1];
    }
    s[0]='(';
    cout<<s<<endl;
    stack<char> a;
    while(s[i]!='\0')
    {
        if(s[i]=='(')
        {
            a.push(s[i]);
        }
        else if(s[i]>='a' && s[i]<='z')
        {
            t[j]=s[i];
            j++;
        }
        else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
        {
            while(a.top()=='+' || a.top()=='-' || a.top()=='*' || a.top()=='/')
            {
                if(prec(a.top())>=prec(s[i]))
                {
                    t[j]=a.top();
                    a.pop();
                    j++;
                }
                else
                {
                    break;
                }
            }
            a.push(s[i]);
        }
        else if(s[i]==')')
        {
            while(a.top()!='(')
            {
                t[j]=a.top();
                a.pop();
                j++;
            }
            a.pop();
        }
        i++;
    }
    t[j]='\0';
    cout<<t<<endl;
}
