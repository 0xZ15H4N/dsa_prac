 #include<iostream>
 #include<bits/stdc++.h>
 using namespace std;
 /*
 
 we will be provided with {1,2,3} and we need to give all the subsets or it {{},{1},{2},{3},{1,2},{2,3},{1,3},{1,2,3}}
 we will use the recursion concept to compute the 2D array

 we will either include or exclude the elemnet in the array , while excluding will now add the element into 
 the 2D array or if we include element then then we add the element into the array

 base case 
    idx >= size:
        return
                        first call       working {1,2,3},                       {}    idx = 0
                                exclude 1/                                         \  include
                        second call    {1,2,3} {}                                  {1,2,3}      ,    {1}  idx = 1
                                    exld    /     \ incl                        exl  /                 \ incl
                       third call {1,2,3} {}       {1,2,3} {2}                     {1,2,3} {1}            {1,2,3}        {1,2}  idx = 2
                                ex /      \in      ex  /    \in                     ex /     \in          ex  /           \in
                fourth call {1,2,3} "{}" {1,2,3} "{3}"|{1,2,3} "{2}" {1,2,3} "{2,3}" | {1,2,3} "{1}"   {1,2,3} "{1,3}" | {1,2,3} "{1,2}" {1,2,3} "{1,2,3}"
                            return       return        return     return       return           return         return        return           
 "" are the answer and we need to push back it in the 2D array
*/

void subsets(vector<int>arr,vector<int>output,int index ,vector<vector<int>>& ans){
    if(index >= arr.size()){
        ans.push_back(output);
        return;
    }
    // exclude
    subsets(arr,output,index+1,ans);
    
    //include 
    int ele = arr[index];
    output.push_back(ele);
    subsets(arr,output,index+1,ans);

}
 int main(){
    
    vector<int> arr = {1,2,3};
    vector<int> output;
    vector<vector<int>> ans;
    int index = 0;
    subsets(arr,output,index,ans);
    cout<< "{";
    for(auto i: ans){
        cout<<"{";
        for(auto j: i){
            cout<<j<<" ,";
        }
        cout<<"}";
    }
    cout<<"}";
    return 0;
 }