#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_=INT_MAX;
        int max_ = 0;
        for (auto price  : prices){
            if(price<min_){
                min_ = price;
            }else{
                max_ = max(max_,price - min_);
            }
        }
        return max_;
    }
};