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

// �������򣬻�����ݹ����汾
void Solution::quickSortApart(vector<int>& nums, int start, int end) {
	if (start < end) {
		int pivot_index = partition(nums, start, end);
		quickSortApart(nums, start, pivot_index - 1);
		quickSortApart(nums, pivot_index + 1, end);
	}
}

// ����ָ��
int Solution::partition(vector<int>& nums, int srart, int end) {
	int pivot = nums[end];
	// follow���������i���������ƶ�
	int follow = srart - 1;
	for (int index = srart; index < end; index++) {
		if (nums[index] < pivot) {
			follow++;
			cout << "i: " << follow << " index: " << index << endl;
			std::swap(nums[follow], nums[index]);
		} else {
			cout << "i: " << follow << " index: " << index << endl;
		}
	}
	// nums[end]Ϊpovit
	std::swap(nums[follow + 1], nums[end]);
	return follow + 1;
}