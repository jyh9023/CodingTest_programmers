#include <string>
#include <vector>
#include <cstring>
using namespace std;

long long solution(int n) {
	long long answer = 0;
	long long dp[2001];
	memset(dp, 0, sizeof(dp));
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	answer = dp[n] % 1234567;
	return answer;
}

int main() {

	solution(4);
}