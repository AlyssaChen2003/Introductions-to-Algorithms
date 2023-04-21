#include<iostream>
using namespace std;
class people {
public:
	int name;
	bool isdated;
	int* like;
	int date;
	int cishu;//男人当前邀约人的排名
	people() {
		isdated = 0;
		date = 0;
		cishu = 1;
	}
};
int main() {
	int n;
	cin >> n;
	people* m, * w;
	m = new people[n];
	w = new people[n];
	for (int i = 1; i <= n; i++) {
		m[i - 1].name = i;
		m[i - 1].like = new int[n];
		for (int j = 1; j <= n; j++) {
			int tmp;
			cin >> tmp;
			m[i - 1].like[j - 1] = tmp;
		}
	}
	for (int i = 1; i <= n; i++) {
		w[i - 1].name = i;
		w[i - 1].like = new int[n];
		for (int j = 1; j <= n; j++) {
			int tmp;
			cin >> tmp;
			w[i - 1].like[j - 1] = tmp;
		}
	}
	int judge = 0;//用于判断是否所有男人都已经约会
	int count = 0;
	while (judge != n) {
		if (count == n)count = 0;
		if (!m[count].isdated) {
			int t = m[count].like[m[count].cishu -1];
			if (!w[t-1].isdated) {
				m[count].date = w[t-1].name;
				m[count].isdated = 1;
				w[t-1].date = m[count].name;
				w[t-1].isdated = 1;
			}
			else {
				int m1, m2;
				int m3 = w[t-1].date -1;
				for (int i = 0; i < n; i++) {
 					if (w[t-1].like[i] == m[count].name)
						m1 = i;
					if (w[t-1].like[i] == m[m3].name)
						m2 = i;
				}
				if (m1 < m2) {
					m[count].date = w[t-1].name;
					m[count].isdated = 1;
					w[t-1].date = m[count].name;
					m[m3].isdated = 0;
					m[m3].date = 0;
				}
			}
			judge = 0;
			m[count].cishu++;
		}
		else { 
			judge++; 
			int t = m[count].like[m[count].cishu - 1];
		}
		count++;
	}
	for (int i = 0; i < n; i++) {
		cout << m[i].date << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}