#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(int n, int s) {
	vector<int> answer(n);
	int idx = n;
	int num = s;

	if (s >= n) {
		for (int i = 0; i < n; i++) {
			int temp = num / idx;
			answer[i] = temp;
			num -= temp;
			idx--;
		}
		// sort(answer.begin(), answer.end());
	}
	else {
		answer.clear();
		answer.push_back(-1);
	}

	return answer;

}
int main() {

	solution(10000, 10000);
}