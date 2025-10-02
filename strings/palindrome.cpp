#include<iostream>
using namespace std;

    char toLower(char s){
        if(s >='a' && s <= 'z'){
            return s;
        }else{
            return s -'A'+'a';  // this is learning
        }
    }

    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        while (start < end) {
            // skip non-alphanumeric
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }

            // compare after converting both to lowercase
            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }