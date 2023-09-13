#include "solution.h"
#include<iostream>
#include<algorithm>

void Solution::sortColors(vector<int>& nums) {
	quickSortHoare(nums,0,nums.size()-1);
}

// 此部分代码在所有的快速排序皆相同，可搭配不同的划分算法
void Solution::quickSort(vector<int>&nums,int start,int end) {
	if (start >= end) {
		return;
	}
	int pivot_index = partitionTraditional(nums, start, end);
	quickSort(nums, start, pivot_index - 1);
	quickSort(nums, pivot_index + 1, end);
}

// 快速排序的划分操作，率辉《数据结构》版本
int Solution::partitionTraditional(vector<int>& nums, int start, int end) {
	// 暂存枢轴的值，而非其索引
	int pivot_value = nums[start];
	int i = start;
	int j = end;
	// i和j轮流向枢轴所在最终位置移动，二者相遇的位置即枢轴的最终位置
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

// 快速排序的划分操作，使用快慢指针，单向遍历
// Lomuto提出
int Solution::partitionLomuto(vector<int>& nums, int srart, int end) {
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

// 使用Hoare划分，不保证在每轮划分结束后枢轴元素在其应该在的位置
// 每轮划分结束后，数组会成为两个子序列，左侧子序列中的元素小于枢轴元素，右侧子序列中的元素大于等于枢轴元素，枢轴元素在右侧子序列的某个位置中
void Solution::quickSortHoare(vector<int>& nums, int start, int end) {
	if (start >= end)
		return;
	int pivot = nums[start];
	int i = start - 1;
	int j = end + 1;
	while (true) {
		do {
			i++;
		} while (nums[i] < pivot);
		do {
			j--;
		} while (nums[j] > pivot);
		if (i >= j) {
			break;
		}
		swap(nums[i], nums[j]);
	}
	quickSortHoare(nums, start, j);
	quickSortHoare(nums, j + 1, end);
}
