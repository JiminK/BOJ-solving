// pair �����ϱ� ���� ����!
#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	return a.second > b.second; // ��������
}

int main() {
	pair<int, int> p[10];
	for (int i = 0; i < 9; i++) {
		int a;
		cin >> a;
		p[i] = { i, a };
	}
	sort(p, p + 10, cmp);
	cout << p[0].second << endl;
	cout << p[0].first + 1 << endl;
	
	return 0;
}