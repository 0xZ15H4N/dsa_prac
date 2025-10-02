#include<iostream>

using namespace std;

char toLower(char s){
        if(s >='a' && s <= 'z'){
            return s;
        }else{
            return s -'A'+'a';  // this is learning
        }
    }
int main(){

    string s;
    cout<<"Enter the string : ";
    cin>>s;
    char ch ;
    int count = 0;
    for(int i = 0;i<s.size();i++){
        char temp = toLower(s[i]);
        char cnt = 0;
        for(int j = 1;j<s.size();j++){
            if(temp == toLower(s[j])){
                cnt++;
            }
        }
        if(cnt >= count){
            ch = temp;
            count = cnt;
        }
    }

    cout<<"maximux occcured character is : "<<ch<<"The No of occurance is "<<count;
    return 0;
}