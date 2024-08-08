#include<bits/stdc++.h>

/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.


Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]
 

Constraints:

n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.


 */


void sortColors(vector<int>& nums) {
       //brute force -- general sorting method
        //better solution 
        int count0=0,count1=0,count2=0;
        for(int i=0;i<n;i++){
            if(a[i]==0) count0++;
            else if(a[i]==1) count1++;
            else count2++;
        }
        for(int i=0;i<count0;i++){
          a[i] = 0;
        }
        for(int i=count0;i<(count1+count0);i++){
            a[i] =1;
        }
        for(int i=(count1+count0);i<(count2+count1+count0);i++){
            a[i]=2;
        }
    
    
    //dutch national flag algorithm -- optimal solution
    int low = 0,high=n-1,mid = 0;
    while(mid<=high){
        if(a[mid]==0){
          swap(a[mid],a[low]);
          mid++;
          low++;  //because 0 starts from 0 to low -1 pointer here we are swaping mid and low .. now low becames 0 and so we are moving low and mid is now 1
        }
        else if(a[mid]==1){
            mid++; //if 1 is present just move one place to the right ... 1 starts from low and goes till mid-1
        }
        else{
            swap(a[mid],a[high]);
          high--;
        } //if 2 is present swap with high pointer 
        //time complexity is O(N) and O(1)
    }
    
}

/*
Intution of the dutch national flag algorithm is to use 3 pointers low,mid and high. low will point to the starting of the array, mid will point to the current element and high will point to the end of the array.
if the mid element is 0 then we swap the mid element with the low element and increment the mid and low pointer.
if the mid element is 1 then we just increment the mid pointer.
if the mid element is 2 then we swap the mid element with the high element and decrement the high pointer.
by this method we can sort the array in place.

 */