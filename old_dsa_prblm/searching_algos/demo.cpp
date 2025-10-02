#include<vector>
#include<iostream>

int pivot(std::vector<int>&nums){
        int start = 0;
        int end = nums.size()-1;
        int mid = start + (end - start)/2;
        int ans ;
        while(start < end){
            if(nums[mid] > nums[end]){  
                start = mid+1;
            }
            else{
                end = mid;
            }
            mid = start + (end - start)/2;
        }
        return mid;
}
bool search(std::vector<int>& nums, int target) {
        int piv = pivot(nums);
        int start = 0;
        int end = nums.size()-1;
        if(target > nums[piv] && target < nums[end]){
            start = piv;
            
        }
        else{
            end = piv -1 ;
        }
        int mid = start + (end - start)/2;
        while(start <= end){
            if(nums[mid] == target){
                return true;
            }
            else if(nums[mid] > target){
                end = mid-1;
            }
            else{
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }
        return false;
                
    }

int main(){
    
    std::vector<int> p = {5,6,7,9,10,1,2,3,4};
    std::cout<<"the pivot index is "<<pivot(p)<<std::endl;
    std::cout<<"the value found is "<<search(p,1);
    return 0;


}