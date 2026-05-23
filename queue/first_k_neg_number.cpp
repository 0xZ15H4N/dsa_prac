#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> firstNegative(vector<int>& arr, int k) {
    deque<int> dq; // stores indices of negative numbers
    vector<int> ans;

    // process first window
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            dq.push_back(i);
        }
    }

    // store result for first window
    if (!dq.empty())
        ans.push_back(arr[dq.front()]);
    else
        ans.push_back(0);

    // process remaining windows
    for (int i = k; i < arr.size(); i++) {
        // remove out-of-window indices
        if (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // add current element if negative
        if (arr[i] < 0) {
            dq.push_back(i);
        }

        // store answer
        if (!dq.empty())
            ans.push_back(arr[dq.front()]);
        else
            ans.push_back(0);
    }

    return ans;
}

int main() {
    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> res = firstNegative(arr, k);

    for (int x : res) {
        cout << x << " ";
    }

    return 0;
}