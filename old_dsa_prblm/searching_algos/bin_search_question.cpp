// binary search questions

// question 1 :- first and last positon of an element in a sorted array

#include<iostream>
#include<vector>

int occurance(std::pair<int,int>);
int first_occurance(int [],int ,int);
int last_occurance(int [],int ,int);
int peakValue_mountain(int [],int);
int pivotI(int [],int  );
int pivotII(int [],int  );
int find_rotated(int [],int ,int);
int binary_search(int [],int ,int ,int);
double square_root(int);
double precision(int,int,int);
int minimumSUM(std::vector<int>,int,int);
bool isPossible(std::vector<int>,int,int,int);



int binary_search(int arr[],int start,int end ,int key){

    int start_ = start;
    int end_  = end;
    int mid = start_ + (end_ + start_)/2;

    while(start_ <= end_){
        if(arr[mid] ==  key ){
            return mid;
        }
        else if(arr[mid]>key){
            end_= mid -1;

        }
        else{start_ = mid +1;}
        mid = start_ + (end_ - start_)/2;
    }
    return -1;


}


int first_occurance(int arr[],int size,int key){
    int start = 0;
    int end = size -1 ;

    int ans = -1;
    int mid = start + (end -start)/2;
    while(start<=end){

        if(arr[mid] == key){
            ans = mid ;
            end = mid -1 ;
        }

        if(arr[mid]<key){
            start = mid+1;
        }
        if(arr[mid] > key){
            end = mid-1;
        }
        mid = start + (end -start)/2;
    }
    return ans;
}

int last_occurance(int arr[],int size , int key){
    
    int start = 0;
    int end = size -1 ;

    int ans = -1;
    int mid = start + (end -start)/2;
    while(start<=end){

        if(arr[mid] == key){
            ans = mid ;
            start = mid  + 1 ;
        }

        if(arr[mid]<key){
            start = mid+1;
        }
        if(arr[mid] > key){
            end = mid-1;
        }
        mid = start + (end -start)/2;
    }
    return ans;
}

std::pair<int ,int> occurance_elemnt(int arr[],int size , int key){
    std::pair<int,int> p ;
    p.first = first_occurance(arr,size,key);
    p.second = last_occurance(arr,size,key);
    
    return p;
}

int main(){

    int arr[] = {1,2,3,4,6,6,6,6,6,6,7,8,9};
    int arr1[] = {1,2,3,4,5,6,5,4,3,2,1};
    int arr2[] = {8,10,17,1,3};
    int size2 = sizeof(arr2)/sizeof(int);
    int size = sizeof(arr)/sizeof(int);
    int size1 = sizeof(arr)/sizeof(int);
    int key = 6;
    std::vector<int>books = {10,20,30,40};
    //std::pair<int,int> p = occurance_elemnt(arr,size,key);
    //std::cout<<p.first<<" "<<p.second<<std::endl;
    //std::cout<<"the number of occurances are "<<occurance(p)<<std::endl;
    //std::cout<<"the peak element in the array is "<<peakValue_mountain(arr1,size1)<<std::endl;
    std::cout<<"the pivot value of the array is "<<pivotI(arr2,size2)<<std::endl;
    //std::cout<<"the pivot value of the array is "<<pivotII(arr2,size2)<<std::endl;
    //std::cout<<"the value 17 in the rotated array is at "<<find_rotated(arr2,size2,17)<<std::endl;
    //std::cout<<"the sqr root of 97 is "<<square_root(40);
    std::cout<<"the mimimum sumofpages are"<<minimumSUM(books,2,4);
    return 0;

}

// question 2 to find the number of occurance 

int occurance(std::pair<int ,int> p){
    if(p.first + p.second > 0){return (-p.first + p.second +1);}
    else {return 0;}
}

// question 3 to find the peak value in mountain array

int peakValue_mountain(int arr[],int size){
    
    int start = 0;
    int end = size -1;

    int mid = start +(end - start )/2;

    while(start < end){ // remeber this not to add the equals to sign


        if(arr[mid] < arr[mid +1]){
            start = mid + 1;

        }

        if(arr[mid]>arr[mid+1]){
            end = mid; // remember this not to but -1 with it
        }
        mid = start + (end - start)/2;

    }
    return arr[start];
}

// question 4  find the pivot in an  array
//part I
// where we get a lowest value in the rotated array
int pivotI(int arr[],int size){
    int start = 0;
    int end = size -1;
    int mid = start + (end - start )/2;
    while(start < end ){
        
        if(arr[mid]>=arr[0])
            start = mid +1;
    
        else
            end = mid;
        
        mid = start + (end-start)/2;
    
    }
    return end;
}
 //part II where we get a peak value from the rotated array //same thing we can do with pivotI the index return can be substracted by -1 to find the peak value in the first line
int pivotII(int arr[],int size){
    int start = 0;
    int end = size -1;
    int mid = start + (end - start)/2;
    while(start < end){
         
        if(arr[mid] >arr[0])
            start = mid;
    
        else
            end = mid-1;
        
        mid = start + (end-start)/2;
    
    }
    return end;
    
}

// searching in rotated array we will use the concept of pivoting

int find_rotated(int arr[],int size, int key){

    int pivot = pivotI(arr,size);

    if(arr[size-1] > key && arr[pivot]< key){
        return binary_search(arr,pivot,size-1,key );
    }
    else{
        return binary_search(arr,0,pivot-1,key);
    }
}

//finding the square root of a number using the binary search

double square_root(int key){
    int start = 0;
    int end = key;
    double mid = start + (end-start)/2;
    int ans;
    
    while(start<=end){
        int square = mid * mid;    
        if(square == key){
            return mid;
        }
        if(square > key){
          
            end = mid -1;
        }
        else{
              ans  = mid;
            start = mid + 1;
        }
        mid = start + (end - start)/2;
    }
    return precision(key,7,ans);
}
double precision(int n,int r,int t)
{
    double factor = 1;
    double ans = t;

    for(int i = 0; i<r; i++){
        factor = factor / 10;

        for(double j = ans ; j*j<n; j=j+factor){
            ans = j;
        }

    }
    return ans;

}
//searching in 2D matrix
bool search_2Dmatrix(std::vector<std::vector<int>>&matrix,int target){
            int rows = matrix.size();
            int cols = matrix[0].size();
            int row = 0 , col = cols-1;

            while(row < rows && col > -1){
                int cur = matrix[row][col] ;
                
                if(cur == target){return true;}

                if(cur > target){col--;}
                
                else{row++;}
                
            }
            return false;      
}

//book allocation problem        
int minimumSUM(std::vector<int>arr,int n,int m){
    int start = 0;
    int sum=0;
    for(auto it:arr){
        sum +=it;
    }
    int end = sum;
    int mid = start + (end - start)/2;
    int ans = -1;
    if(n>m){
    while(start<=end){
    if(isPossible(arr,n,m,mid)){
        ans = mid;
        end = mid -1;
    }

    else{
        start = mid + 1;
    }

    mid = start + (end - start)/2;
    }
    
}
return ans;
}                                                                       

bool isPossible(std::vector<int>arr,int n,int m,int mid){
    int PersonCount=1;
    int sumOFpages = 0;
    for(int i = 0;i<n;i++){
        if(sumOFpages + arr[i]<= mid){
            sumOFpages+=arr[i];
        }
        else{
            PersonCount++;
            if(PersonCount>m || arr[i] > mid){
                return false;
            }
            sumOFpages= arr[i];
        }
    }
    return true;
}