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
	// 暂存枢轴的值
	int pivot_temp = nums[start];
	int i = start;
	int j = end;
	//i和j轮流向中间移动
	while (i < j) {
		while (i < j && nums [j] >= pivot_temp){
			j--;
		}
		if (i < j) {
			nums[i] = nums[j];
			i++;
		}
		while (i < j && nums[i] < pivot_temp) {
			i++;
		}
		if (i < j) {
			nums[j] = nums[i];
			j--;
		}
	}
	// 将枢轴的值放回序列，此时i和j相遇
	nums[i] = pivot_temp;
	quickSort(nums,start,i-1);
	quickSort(nums,i+1,end);
}
