#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        queue<vector<string>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end())
            return {};

        vector<vector<string>> ans;

        q.push({beginWord});

        unordered_set<string> usedOnLevel;
        usedOnLevel.insert(beginWord);

        int level = 1;

        while (!q.empty()) {

            vector<string> vec = q.front();
            q.pop();

            if (vec.size() > level) {
                level = vec.size();

                for (auto &word : usedOnLevel)
                    st.erase(word);

                usedOnLevel.clear();

                // No need to explore deeper levels
                if (!ans.empty() && level > ans[0].size())
                    break;
            }

            string word = vec.back();

            if (word == endWord) {
                if (ans.empty())
                    ans.push_back(vec);
                else if (ans[0].size() == vec.size())
                    ans.push_back(vec);

                continue;
            }

            for (int i = 0; i < word.size(); i++) {

                char original = word[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    if (ch == original)
                        continue;

                    word[i] = ch;

                    if (st.find(word) != st.end()) {
                        vec.push_back(word);
                        q.push(vec);
                        vec.pop_back();

                        usedOnLevel.insert(word);
                    }
                }

                word[i] = original;
            }
        }

        return ans;
    }
};