#include "solution.h"
#include<iostream>
#include<algorithm>

void Solution::sortColors(vector<int>& nums) {
	quickSort(nums,0,nums.size()-1);
}

// �˲��ִ��������еĿ����������ͬ���ɴ��䲻ͬ�Ļ����㷨
void Solution::quickSort(vector<int>&nums,int start,int end) {
	if (start >= end) {
		return;
	}
	int pivot_index = partitionAdvanced(nums, start, end);
	quickSort(nums, start, pivot_index - 1);
	quickSort(nums, pivot_index + 1, end);
}

// ��������Ļ��ֲ������ʻԡ����ݽṹ���汾
int Solution::partitionTraditional(vector<int>& nums, int start, int end) {
	// �ݴ������ֵ������������
	int pivot = nums[start];
	int i = start;
	int j = end;
	// i��j������������������λ���ƶ�������������λ�ü����������λ��
	while (i < j) {
		// j�����ƶ���ֱ����ָ��һ��С�������ֵ������i<jʱ�ƶ���
		while (i < j && nums[j] >= pivot) {
			j--;
		}
		if (i < j) {
			// ���������Ԫ�������������Ŀ�λ����ʱnums[j]�ɱ�������λ
			nums[i] = nums[j];
			// i�����ƶ�
			i++;
		}
		// i�����ƶ���ֱ����ָ��һ�����ڻ���������ֵ������i < jʱ�ƶ���
		while (i < j && nums[i] < pivot) {
			i++;
		}
		if (i < j) {
			nums[j] = nums[i];
			j--;
		}
	}
	// �������ֵ�Ż����У���ʱi��j����
	nums[i] = pivot;
	return i;
}


// �ʻԡ����ݽṹ���㷨�Ľ��汾
int Solution::partitionAdvanced(vector<int>& nums, int start, int end) {
	// ʹ�����Ԫ����Ϊ�������������ӻ��ֵ�ƽ���ԣ�Ҳ�ɲ�ʹ��
	int random_index = rand() % (end - start + 1) + start;
	int pivot = nums[random_index];
	// ʹ�����Ϊ��Ԫ��
	// ��Ϊ�����ֵ�ᱻ�������棬����Ԫ��û�С�i�ĳ�ʼֵΪ0����nums[i] = nums[j]ʱ����Ԫ�ر�����
	swap(nums[random_index], nums[start]);
	int i = start, j = end;
	while (i < j) {
		while (i < j && nums[j] >= pivot) {
			j--;
		}
		// �˴�ɾ�����ʻԡ����ݽṹ���㷨�е�i<j������i��j���ʱ��nums[i]Ҳ��nums[j]��ȣ�����Ȼ�����һ��������ĸ��Ʋ��������ò�����������
		// �˴�ɾ�����ʻԡ����ݽṹ���㷨��i++����i���������whileѭ�����ƶ�
		nums[i] = nums[j];
		while (i < j && nums[i] <= pivot) {
			i++;
		}
		nums[j] = nums[i];
	}
	nums[i] = pivot;
	return i;
}

// ��������Ļ��ֲ�����ʹ�ÿ���ָ�룬�������
// Lomuto���
int Solution::partitionLomuto(vector<int>& nums, int srart, int end) {
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

// ʹ��Hoare���֣�����֤��ÿ�ֻ��ֽ���������Ԫ������Ӧ���ڵ�λ��
// ÿ�ֻ��ֽ�����������Ϊ���������У�����������е�Ԫ��С������Ԫ�أ��Ҳ��������е�Ԫ�ش��ڵ�������Ԫ�أ�����Ԫ�����Ҳ������е�ĳ��λ����
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
