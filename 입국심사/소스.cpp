#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int check(long long mid, vector<int> times, int n) {
	long long cnt = 0;
	for (int i = 0; i < times.size(); i++) {
		cnt += mid / times[i];
	}
	if (n <= cnt) {
		return 1;
	}
	else {
		return 0;
	}
}

long long solution(int n, vector<int> times) {
	long long answer = 1000000000000000001;
	sort(times.begin(), times.end(), greater<int>());

	long long left = 0;
	long long right = (long long)times[0] * n;

	while (left <= right) {
		long long mid = (left + right) / 2;
		if (check(mid, times, n)) {
			if (mid < answer) {
				answer = mid;
			}
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return answer;
}

int main() {
	vector<int> v = { 7,10 };

	solution(6, v);
}