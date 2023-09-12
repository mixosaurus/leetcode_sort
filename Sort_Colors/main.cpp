#include"Solution.h"
#include<iostream>
#include<vector>
using namespace std;

//75. —’…´∑÷¿‡
int main() {
	Solution solution;
	vector<int> nums = {
		4,10, 2, 3, 7, 8, 9, 1, 5
	};
	solution.sortColors(nums);
	for (int num : nums) {
		cout << num << " ";
	}
	system("pause");
	return 0;
}
