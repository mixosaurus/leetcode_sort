#include"Solution.h"
#include<iostream>
#include<vector>
using namespace std;

//75. ��ɫ����
int main() {
	Solution solution;
	vector<int> nums = {
		6, 6, 11, 10, 2, 13, 7, 1, 6
	};
	solution.sortColors(nums);
	for (int num : nums) {
		cout << num << " ";
	}
	system("pause");
	return 0;
}
