#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
	vector<int> answer;
	set<string>st;
	st.insert(words[0]);
	int chk = 0;
	int idx = -1;

	for (int i = 1; i < words.size(); i++) {
		if (words[i - 1][words[i - 1].size() - 1] != words[i][0] || st.find(words[i]) != st.end()) {
			chk++;
			idx = i;
			break;
		}
		else {
			st.insert(words[i]);
		}
	}
	if (chk == 0) {
		answer.push_back(0);
		answer.push_back(0);
	}
	else {
		answer.push_back(idx % n);
		answer.push_back((idx / n) + 1);
	}
	return answer;
}

int main() {
	vector<string> v = { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" };

	solution(3, v);
}