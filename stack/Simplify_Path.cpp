#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;
/*


You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.


*/

string solve(string Path){
    stack<string> stk;

    for(int i = 0; i < Path.size(); i++){
        
        if(Path[i] == '/') continue;

        string temp = "";
        while(i < Path.size() && Path[i] != '/'){
            temp += Path[i];
            i++;
        }

        if(temp == "." || temp == ""){
            continue;
        }
        else if(temp == ".."){
            if(!stk.empty()) stk.pop();
        }
        else{
            stk.push(temp);
        }
    }

    // build result
    vector<string> res;
    while(!stk.empty()){
        res.push_back(stk.top());
        stk.pop();
    }

    reverse(res.begin(), res.end());

    string ans = "/";
    for(int i = 0; i < res.size(); i++){
        ans += res[i];
        if(i != res.size() - 1) ans += "/";
    }

    return ans;
}

int main(){
    string Path = "/.././GVzvE/./xBjU///../..///././//////T/../../.././zu/q/e";
    string valid_path = solve(Path);
    cout<<valid_path;
    return 0;
}