#include "solution.h"
#include<iostream>
#include<algorithm>

void Solution::sortColors(vector<int>& nums) {
	quickSort(nums,0,nums.size()-1);
}

//��������
void Solution::quickSort(vector<int>&nums,int start,int end) {
	if (start >= end) {
		return;
	}
	// �ݴ������ֵ
	int pivot_temp = nums[start];
	int i = start;
	int j = end;
	//i��j�������м��ƶ�
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
	// �������ֵ�Ż����У���ʱi��j����
	nums[i] = pivot_temp;
	quickSort(nums,start,i-1);
	quickSort(nums,i+1,end);
}
