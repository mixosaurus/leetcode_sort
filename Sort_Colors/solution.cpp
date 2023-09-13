#include "solution.h"
#include<iostream>
#include<algorithm>

void Solution::sortColors(vector<int>& nums) {
	quickSortApart(nums,0,nums.size()-1);
}

// 快速排序，率辉《数据结构》版本
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
			// 将比枢轴大元素置于枢轴左侧的空位，此时nums[j]可被视作空位
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

int Solution::partition(vector<int>& nums, int srart, int end) {
	// 暂存枢轴的值，而非其索引
	int pivot_value = nums[start];
	int i = start;
	int j = end;
	while (i < j) {
		// j向左移动，直到其指向一个小于枢轴的值（仅在i<j时移动）
		while (i < j && nums[j] >= pivot_value) {
			j--;
		}
		if (i < j) {
			// 将比枢轴大元素置于枢轴左侧的空位，此时nums[j]可被视作空位
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
	return i;
}

// 快速排序，划分与递归分离版本
void Solution::quickSortApart(vector<int>& nums, int start, int end) {
	if (start < end) {
		int pivot_index = partitionWithTwoPointers(nums, start, end);
		quickSortApart(nums, start, pivot_index - 1);
		quickSortApart(nums, pivot_index + 1, end);
	}
}

// 快慢指针
int Solution::partitionWithTwoPointers(vector<int>& nums, int srart, int end) {
	int pivot = nums[end];
	// follow跟随i从左向右移动
	int follow = srart - 1;
	for (int i = srart; i < end; i++) {
		// 一旦follow停止跟随i，即说明follow的下一个元素大于等于pivot
		if (nums[i] < pivot) {
			// 让follow前进一步，使其指向上述大于等于pivot的元素
			follow++;
			// 此时follow指向大于等于pivot的元素，可与nums[i]交换
			std::swap(nums[follow], nums[i]);
		}
	}
	// nums[end]为povit，使其与大于等于pivot的元素交换
	std::swap(nums[follow + 1], nums[end]);
	return follow + 1;
}