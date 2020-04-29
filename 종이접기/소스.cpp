#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> solution(int n) {
	vector<int> answer;
	vector<vector<int>> v;
	vector<int> zero = { 0 };
	v.push_back(zero);
	for (int i = 1; i <= n; i++) {
		vector<int> temp = v[i - 1];
		vector<int> temp2 = v[i - 1];
		temp2.push_back(0);
		reverse(temp.begin(), temp.end());
		for (int j = 0; j < temp.size(); j++) {
			temp2.push_back(!temp[j]);
		}	
		v.push_back(temp2);
	}
	return answer;
}
int main() {
	int a = !1;

	solution(4);
}