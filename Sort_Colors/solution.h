#pragma once
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums);
	void quickSortTraditional(vector<int>& nums, int i, int j);
	int partitionTraditional(vector<int>& nums, int srart, int end);
	int partitionWithTwoPointers(std::vector<int>& nums, int srart, int end);
};

