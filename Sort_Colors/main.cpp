#include"Solution.h"
#include<iostream>
#include<vector>
using namespace std;

//75. —’…´∑÷¿‡
int main() {
	Solution solution;
	vector<int> nums = {
		2,0,4,9,8,1
	};
	solution.sortColors(nums);
	for (int num : nums) {
		cout << num << " ";
	}
	system("pause");
	return 0;
}
