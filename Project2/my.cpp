#include<vector>
#include<unordered_set>
#include<iostream>
#include<algorithm>
using namespace std;

int search(vector<int>& nums, int target) {
	int Left = 0;
	int Right = nums.size() - 1;
	int mid = (Left + Right) / 2;
	while (Left >= Right)
	{
		if (target == nums[mid])
			return mid;
		if (target < nums[mid])
			Right = mid - 1;
		else if (target > nums[mid])
			Left = mid + 1;
		mid = (Left + Right) / 2;
	}
	return -1;
	
}