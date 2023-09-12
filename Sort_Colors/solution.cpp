#include "solution.h"
#include<iostream>
#include<algorithm>

void Solution::sortColors(vector<int>& nums) {
	quickSortApart(nums,0,nums.size()-1);
}

// ���������ʻ԰����ݽṹ
void Solution::quickSortTraditional(vector<int>&nums,int start,int end) {
	if (start >= end) {
		return;
	}
	// �ݴ������ֵ������������
	int pivot_value = nums[start];
	int i = start;
	int j = end;
	while (i < j) {
		// j�����ƶ���ֱ����ָ��һ��С�������ֵ������i<jʱ�ƶ���
		while (i < j && nums [j] >= pivot_value){
			j--;
		}
		if (i < j) {
			// ���������Ԫ��ֵ���������Ŀ�λ����ʱnums[j]�ɱ�������λ
			nums[i] = nums[j];
			// i�����ƶ�
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
	// �������ֵ�Ż����У���ʱi��j����
	nums[i] = pivot_value;
	quickSortTraditional(nums,start,i-1);
	quickSortTraditional(nums,i+1,end);
}

// �������򣬻�����ݹ����汾
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