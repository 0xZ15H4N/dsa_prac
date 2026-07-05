#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
T.C O(NlogN)
S.C O(N+M)
*/

class Node{
    public:
        int data;
        int row;
        int col;

        Node(int data , int row, int col){
            this->data = data;
            this->row = row;
            this->col = col;
        }
};

class compare{
    public:
        bool operator()(Node* a, Node*b){
            return a->data > b->data;
        }
};

vector<int> merge_k_sorted_arrays(vector<vector<int>>KArrays,int size){
    priority_queue<Node* , vector<Node*>, compare> pq; 
    vector<int> ans;
    for(int i = 0; i<size; i++){
        int data = KArrays[i][0];
        int row = i;
        int col = 0;
        Node* tmp = new Node(data,row,col);
        pq.push(tmp);
    }

    while(!pq.empty()){
        Node* tmp = pq.top();
        pq.pop();
        ans.push_back(tmp->data);
        if(tmp->col +1 < KArrays[tmp->row].size()){
            int row = tmp->row;
            int col = tmp->col+1;
            int data = KArrays[row][col];
            Node* ntmp = new Node(data,row,col);
            pq.push(ntmp);
        }
    }
    return ans;
}

int main(){
// Your Driver Code
    return 0;
}