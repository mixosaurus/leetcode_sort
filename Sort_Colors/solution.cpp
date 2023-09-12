#include "solution.h"
#include<iostream>
#include<algorithm>

void Solution::sortColors(vector<int>& nums) {
	quickSortApart(nums,0,nums.size()-1);
}

// 快速排序，率辉版数据结构
void Solution::quickSortTraditional(vector<int>&nums,int start,int end) {
	if (start >= end) {
		return;
	}
	// 暂存枢轴的值，而非其索引
	int pivot_value = nums[start];
	int i = start;
	int j = end;
	while (i < j) {
		// j向左移动，直到其指向一个小于枢轴的值（仅在i<j时移动）
		while (i < j && nums [j] >= pivot_value){
			j--;
		}
		if (i < j) {
			// 将比枢轴大元素值与枢轴左侧的空位，此时nums[j]可被视作空位
			nums[i] = nums[j];
			// i向右移动
			i++;
		}
		while (i < j && nums[i] < pivot_value) {
			i++;
		}
		if (i < j) {
			nums[j] = nums[i];
			j--;
		}
	}
	// 将枢轴的值放回序列，此时i和j相遇
	nums[i] = pivot_value;
	quickSortTraditional(nums,start,i-1);
	quickSortTraditional(nums,i+1,end);
}

// 快速排序，划分与递归分离版本
void Solution::quickSortApart(std::vector<int>& nums, int start, int end) {
	if (start < end) {
		int pivot = partition(nums, start, end);
		quickSortApart(nums, start, pivot - 1);
		quickSortApart(nums, pivot + 1, end);
	}
}

int Solution::partition(std::vector<int>& nums, int srart, int end) {
	int pivot = nums[end];
	int i = srart - 1;

	for (int j = srart; j < end; j++) {
		if (nums[j] < pivot) {
			i++;
			std::swap(nums[i], nums[j]);
		}
	}
	std::swap(nums[i + 1], nums[end]);
	return i + 1;
}