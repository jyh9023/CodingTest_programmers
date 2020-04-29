#include <vector>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int result;

void dfs(vector<int> nums, int start, int depth, int *arr, int num) {

	if (depth == 3) {
		if (arr[num] == 0) {
			result++;
		}
		return;
	}

	for (int i = start; i < nums.size(); i++) {
		num += nums[i];
		dfs(nums, i + 1, depth + 1, arr, num);
		num -= nums[i];
	}
}

int solution(vector<int> nums) {
	int answer = -1;
	int arr[50001];
	memset(arr, 0, sizeof(arr));
	arr[1] = 1;
	for (int i = 2; i <= sqrt(50000); i++) {
		if (arr[i] == 0) {
			for (int j = i * i; j <= 50000; j += i) {
				arr[j] = 1;
			}
		}
	}

	dfs(nums, 0, 0, arr, 0);

	answer = result;

	result = 0;
	return answer;
}

int main() {
	vector<int> v = { 1,2,7,6,4 };

	solution(v);
}