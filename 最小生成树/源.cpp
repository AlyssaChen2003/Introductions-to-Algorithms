//#include<iostream>
//#include <algorithm>
//using namespace std;
//int n, m;
//struct bian {
//	int begin, end, weight;
//};
//int find(int* p, int b) {
//	int r = b;
//	while (p[r] > -1) {
//		r = p[r];
//	}
//	return r;
//}
//int mycomp(bian a, bian b) {
//	return a.weight < b.weight;
//}
//int Kruskal(bian* a, int* root) {
//	sort(a, a + m, mycomp);
//	int count = 0, weights = 0;
//	int p1, p2;
//	for (int i = 0; i < m; i++) {
//		p1 = find(root, a[i].begin);
//		p2 = find(root, a[i].end);
//		if (p1 != p2) {
//			root[p2] = p1;
//			count++;
//			weights += a[i].weight;
//			if (count == n)
//				return weights;
//		}
//	}
//	return weights;
//}
//int main() {
//	cin >> n >> m;
//	bian* a;
//	int* root;
//	a = new bian[m];
//	root = new int[m];
//	int b, e, w;
//	for (int i = 0; i < m; i++) {
//		cin >> b;
//		cin >> e;
//		cin >> w;
//		a[i].begin = b;
//		a[i].end = e;
//		a[i].weight = w;
//		root[i] = -1;
//	}
//	cout << Kruskal(a, root);
//	return 0;
//}