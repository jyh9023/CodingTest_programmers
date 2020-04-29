#include <iostream>
#include <bitset>
using namespace std;

int solution(int n)
{
	int ans = 0;
	bitset<30> bb = n;
	ans = bb.count();

	return ans;
}

int main() {

	solution(5000);
}