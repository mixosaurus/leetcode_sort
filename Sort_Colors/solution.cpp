#include "solution.h"
#include<iostream>
#include<algorithm>

void Solution::sortColors(vector<int>& nums) {
	quickSort(nums,0,nums.size()-1);
}

//快速排序
void Solution::quickSort(vector<int>&nums,int start,int end) {
	if (start >= end) {
		return;
	}
	int temp = nums[start];
	int i = start;
	int j = end;
	//i和j轮流向中间移动
	while (i < j) {
		while (i < j && nums [j] >= temp){
			j--;
		}
		if (i < j) {
			nums[i] = nums[j];
			i++;
		}
		while (i < j && nums[i] < temp) {
			i++;
		}
		if (i < j) {
			nums[j] = nums[i];
			j--;
		}
	}
	//此时i和j相遇
	nums[i] = temp;
	quickSort(nums,start,i-1);
	quickSort(nums,i+1,end);
}
