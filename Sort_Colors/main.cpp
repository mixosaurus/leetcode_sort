#include"Solution.h"
#include<iostream>
#include<vector>
using namespace std;

//75. —’…´∑÷¿‡
int main() {
	Solution solution;
	vector<int> nums = {
		8, 6, 11, 10, 2, 13, 7, 1, 16
	};
	solution.sortColors(nums);
	for (int num : nums) {
		cout << num << " ";
	}
	system("pause");
	return 0;
}
