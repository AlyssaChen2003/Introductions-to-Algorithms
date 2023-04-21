#include<iostream>
#include<algorithm>
#include<iomanip>
#include<math.h>
using namespace std;
struct point {
    double x;
    double y;

};
bool mycompx(point e1, point e2) {
    return (e1.x < e2.x);

}
bool mycompy(point e1, point e2) {
    return (e1.y < e2.y);
}
double d(point e1, point e2) {
    return sqrt((e1.x - e2.x) * (e1.x - e2.x) + (e1.y - e2.y) * (e1.y - e2.y));
}
double ClosestPairRec(point *p, int l, int r) {
    if (r - l + 1 <= 3) {
        double min = 20000, distance;
        for (int i = l; i < r + 1; i++) {
            for (int j = i + 1; j < r + 1; j++) {
                distance = d(p[i], p[j]);
                if (distance < min)
                    min = distance;
            }

        }
        return min;
    }
    else {
        int m = (l + r) / 2;
        double d_left = ClosestPairRec(p, l, m);
        double d_right = ClosestPairRec(p, m, r);
        double mx = p[m].x;
        double min;
        if (d_left < d_right)
            min = d_left;
        else
            min = d_right;
        point pt[30000];
        int k = 0;
        for (int i = l; i < r; i++) {
            if (p[i].x - mx<min && p[i].x - mx>(-1 * min)) {
                pt[k] = p[i];
                k++;
            }
        }
        sort(pt, pt + k, mycompy);
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if (pt[j].y - pt[i].y >= min)
                    break;
                else {
                    double distance = d(pt[i], pt[j]);
                    if (distance < min)
                        min = distance;
                }
            }
        }
        return min;

    }
}
int main() {
    int n;
    cin >> n;
    point* p = new point[n];
    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;
        p[i].x = x;
        p[i].y = y;
    }
    sort(p, p + n, mycompx);
    cout << fixed << setprecision(2);
    cout << ClosestPairRec(p,0, n - 1) * ClosestPairRec(p, 0, n - 1);
}