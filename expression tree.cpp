#include <bits/stdc++.h>

using namespace std;
struct node
{
    char key;
    struct node *left,*right;
};
struct node* root;
struct node* newnode(char a)
{
    struct node* x=(struct node*)malloc(sizeof(struct node));
    x->key=a;
    x->left=NULL;
    x->right=NULL;
    return x;
};
int isoperator(char a)
{
    if(a=='+' || a=='-' || a=='*' || a=='/' || a=='^')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
struct node* extree(char s[])
{
    struct node *t;
    stack<struct node *>st;
    for(int i=0;i<strlen(s);i++)
    {
        if(isoperator(s[i]))
        {
            t=newnode(s[i]);
            st.push(t);
        }
        else
        {
            struct node *t1,*t2;
            t=newnode(s[i]);
            t1=st.top();
            st.pop();
            t2=st.top();
            st.pop();
            t->left=t2;
            t->right=t1;
            st.push(t);
        }
    }
    return t;
};
void inorder(struct node *t)
{
    if(t)
    {
        inorder(t->left);
        printf("%c ", t->key);
        inorder(t->right);
    }
}
int main()
{
    char s[]="ab+ef*g*-";
    root=extree(s);
    printf("infix expression is \n");
    inorder(root);
    return 0;
}
