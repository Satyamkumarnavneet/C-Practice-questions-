#include<iostream>
#include<string>
#define MAX 20
using namespace std;

char stk[20];
int top=-1;
void push(char oper)
{
    if(top==MAX-1){
        cout<<"stackfull!!!!";
    }
   
    else{
        top++;
        stk[top]=oper;
    }
}
char pop() {
    char ch;
    if(top==-1) {
        cout<<"stackempty!!!!";
    }
    else {
        ch=stk[top];
        stk[top]='\0';
        top--;
        return(ch);
    }
    return 0;
}
int priority ( char alpha ) {
    if(alpha == '+' || alpha =='-'){
        return(1);
    }
 
    if(alpha == '*' || alpha =='/'){
        return(2);
    }
 
    if(alpha == '$'){
        return(3);
    } 
    return 0;
}
string convert(string infix){
    int i=0;
    string postfix = "";   
    while(infix[i]!='\0')
    {       
        if(infix[i]>='a' && infix[i]<='z'|| infix[i]>='A'&& infix[i]<='Z')          
        {
            postfix.insert(postfix.end(),infix[i]);
            i++;
        }       
        else if(infix[i]=='(' || infix[i]=='{'  || infix[i]=='[')
        {
            push(infix[i]);
            i++;
        }        
        else if(infix[i]==')' || infix[i]=='}'  || infix[i]==']')
        {
            if(infix[i]==')')
            {
                while(stk[top]!='(') {
			        postfix.insert(postfix.end(),pop());
                }
                pop();
                i++;
            }
            if(infix[i]==']'){
                while(stk[top]!='['){
                    postfix.insert(postfix.end(),pop());
                }
                pop();
                i++;
            }
 
            if(infix[i]=='}'){
                while(stk[top]!='{'){
                    postfix.insert(postfix.end(),pop());
                }
                pop();
                i++;
            }
        }
        else {
            if(top==-1) {
                push(infix[i]);
                i++;
            } 
            else if( priority(infix[i]) <= priority(stk[top])) {
                postfix.insert(postfix.end(),pop());
               
                while(priority(stk[top]) == priority(infix[i])){
                    postfix.insert(postfix.end(),pop());
                    if(top < 0) {
                        break;
                    }
                }
                push(infix[i]);
                i++;
            }
            else if(priority(infix[i]) > priority(stk[top])) {
                push(infix[i]);
                i++;
            }
        }
    }
    while(top!=-1){
        postfix.insert(postfix.end(),pop());
    }
    cout<<"The converted postfix string is : "<<postfix; //It will print postfix conversion  
    return postfix;
}

int main()
{
    int cont;
    string infix, postfix;
    cout<<"\nEnter the infix expression : "; //Enter the expression here
    cin>>infix;
    postfix = convert(infix);
    return 0;
}
