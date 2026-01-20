#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*

we need to find if the valid string contains a valid parantheses or not for example "{[()]}" is valid but "{]()" is not valid
*/


int main(){

    string paren = "{{[(]}}";

    stack<char>stk;

    for(int i = 0;i<paren.size();i++){
        if( (paren[i] == '{') || (paren[i] == '[') ||( paren[i] =='(') ){
            stk.push(paren[i]);
        }
        if((paren[i]=='}') || (paren[i] == ']') || (paren[i] == ')')){
            if(!stk.empty()){
                char top = stk.top();
                if((paren[i] == '}' && top == '{') || (paren[i] == ']' && top == '[') || (paren[i] == ')' && top == '(')){
                    stk.pop();
                }
                else{
                cout<<"not a valid parentheses string";
                return 0;
                }
            }else{
                cout<<"not a valid parentheses string";
                return 0;
            }
        }
    }
    if(!stk.empty()){
        cout<<"not a valid parenthesis string";
    }
    else{
        cout<<"valid one";
    }
    return 0; 
}