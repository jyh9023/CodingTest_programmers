#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	else {
		return p1.first > p2.first;
	}
}



vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, vector<pair<int, int>>> m;
	map<string, int> m2;
	map<int, string, greater<int>> m3;
	map<int, string, greater<int>>::iterator it3;
	map<string, int>::iterator it2;
	map<string, vector<pair<int, int>>>::iterator it;
	for (int i = 0; i < genres.size(); i++) {
		m[genres[i]].push_back(make_pair(plays[i], i));
		if (m2.find(genres[i]) != m2.end()) {
			m2[genres[i]] += plays[i];
		}
		else {
			m2[genres[i]] = plays[i];
		}
	}

	for (it2 = m2.begin(); it2 != m2.end(); it2++) {
		m3[it2->second] = it2->first;
	}

	for (it3 = m3.begin(); it3 != m3.end(); it3++) {
		it = m.find(it3->second);
		vector<pair<int, int>> temp = it->second;
		sort(temp.begin(), temp.end(), cmp);
		if (temp.size() == 1) {
			answer.push_back(temp[0].second);
		}
		else {
			for (int j = 0; j < 2; j++) {
				answer.push_back(temp[j].second);
			}
		}
	}

	return answer;
}

int main() {
	vector<string> v1 = { "classic", "pop", "classic", "classic", "pop" };
	vector<int> v2 = { 500,600,150,800,2500 };

	solution(v1, v2);
}