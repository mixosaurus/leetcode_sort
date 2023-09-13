#include "solution.h"
#include<iostream>
#include<algorithm>

void Solution::sortColors(vector<int>& nums) {
	quickSortApart(nums,0,nums.size()-1);
}

// ���������ʻԡ����ݽṹ���汾
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
			// ���������Ԫ�������������Ŀ�λ����ʱnums[j]�ɱ�������λ
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

int Solution::partition(vector<int>& nums, int srart, int end) {
	// �ݴ������ֵ������������
	int pivot_value = nums[start];
	int i = start;
	int j = end;
	while (i < j) {
		// j�����ƶ���ֱ����ָ��һ��С�������ֵ������i<jʱ�ƶ���
		while (i < j && nums[j] >= pivot_value) {
			j--;
		}
		if (i < j) {
			// ���������Ԫ�������������Ŀ�λ����ʱnums[j]�ɱ�������λ
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
	return i;
}

// �������򣬻�����ݹ����汾
void Solution::quickSortApart(vector<int>& nums, int start, int end) {
	if (start < end) {
		int pivot_index = partitionWithTwoPointers(nums, start, end);
		quickSortApart(nums, start, pivot_index - 1);
		quickSortApart(nums, pivot_index + 1, end);
	}
}

// ����ָ��
int Solution::partitionWithTwoPointers(vector<int>& nums, int srart, int end) {
	int pivot = nums[end];
	// follow����i���������ƶ�
	int follow = srart - 1;
	for (int i = srart; i < end; i++) {
		// һ��followֹͣ����i����˵��follow����һ��Ԫ�ش��ڵ���pivot
		if (nums[i] < pivot) {
			// ��followǰ��һ����ʹ��ָ���������ڵ���pivot��Ԫ��
			follow++;
			// ��ʱfollowָ����ڵ���pivot��Ԫ�أ�����nums[i]����
			std::swap(nums[follow], nums[i]);
		}
	}
	// nums[end]Ϊpovit��ʹ������ڵ���pivot��Ԫ�ؽ���
	std::swap(nums[follow + 1], nums[end]);
	return follow + 1;
}