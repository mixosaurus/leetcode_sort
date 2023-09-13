#pragma once
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums);
	void quickSort(vector<int>& nums, int i, int j);
	int partitionTraditional(vector<int>& nums, int srart, int end);
	int partitionLomuto(std::vector<int>& nums, int srart, int end);
	void quickSortHoare(vector<int>& nums, int l, int r);
	int partitionAdvanced(vector<int>& nums, int left, int right);
};

