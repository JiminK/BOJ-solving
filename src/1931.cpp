#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(const vector<int>& v1, const vector<int>& v2)
{
    if (v1[1] == v2[1]) // E ���� => S ���� ������ ����
        return v1[0] < v2[0];
    else // E �ٸ��� => E ���� ������ ����
        return v1[1] < v2[1];
}

int main()
{
    int N = 0, answer = 1;
    cin >> N;
    vector<vector<int>> arr(N, vector<int>(2,0));
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    int n = arr.size();

    sort(arr.begin(), arr.end(), cmp);

    int end_time = arr[0][1]; // ȸ�ǰ� ������ �ð� ����
    for (int i = 1; i < n; i++) {
        if (end_time <= arr[i][0]) { // ���� ȸ���� ������ �ð��� ���� ȸ�� ���� �ð����� ������ ���� ���� ȸ�� �����ϹǷ�
            end_time = arr[i][1]; // ���� ȸ���� ������ �ð��� ����
            answer++;
        }
    }
    cout << answer << endl;
    return 0;
}