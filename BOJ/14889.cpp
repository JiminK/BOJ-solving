#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n = 0;
int s[21][21];
bool check[21];
int minR = INT_MAX;

/* recursive call ��� */
void calc(int idx, int cnt) {
    /* n / 2 �� check[] true�� ������� �� */
	if (cnt == n / 2) {
		/* 
		   start��, link�� ������
		   check[] == true�� idx => start team
		   check[] == false�� idx => link team
		*/
		vector<int> start, link; // ��� �ʱ�ȭ ����� ��.
		for (int i = 0; i < n; i++) {
			if (check[i] == true)
				start.push_back(i);
			else
				link.push_back(i);
		}

		/* �ɷ�ġ ���� ��� */
		int start_stat = 0, link_stat = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = i + 1; j < n / 2; j++) {
				start_stat += s[start[i]][start[j]] + s[start[j]][start[i]];
				link_stat += s[link[i]][link[j]] + s[link[j]][link[i]];
			}
		}
		int diff = abs(start_stat - link_stat);
		minR = min(minR, diff);
		return;
	}
	
	for (int i = idx + 1; i < n; i++) {
		if (check[i] == false) {
			check[i] = true;
			calc(i, cnt + 1);
			check[i] = false;
		}
	}
}

int main() {	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> s[i][j];
	}

    calc(0, 0);
    cout << minR << endl;

	return 0;
}