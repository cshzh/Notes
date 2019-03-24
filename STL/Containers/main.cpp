#include <bits/stdc++.h>

void test1();

void test2();

using namespace std;

struct Edge {
    int dis, to;

    bool friend operator<(Edge x1, Edge x2) {
        return x1.dis > x2.dis;
    }
} temp, now;

vector<Edge> vec[10005];
bool life[10005];
int dis[10005], n;
priority_queue<Edge> q;

void init() {



    for (int i = 1; i <= n; i++)
        dis[i] = 100000000;
    memset(life, 0, sizeof(life));
    while (!q.empty())
        q.pop();
}

int dij(int s, int t) {
    init();
    temp.to = s;
    temp.dis = 0;
    q.push(temp);
    dis[s] = 0;
    while (!q.empty()) {
        now = q.top();
        q.pop();
        if (!life[now.to]) {
            life[now.to] = 1;
            for (int i = 0; i < vec[now.to].size(); i++) {
                if (!life[vec[now.to][i].to] && dis[now.to] + vec[now.to][i].dis < dis[vec[now.to][i].to]) {
                    dis[vec[now.to][i].to] = dis[now.to] + vec[now.to][i].dis;
                    temp.to = vec[now.to][i].to;
                    temp.dis = dis[vec[now.to][i].to];
                    q.push(temp);
                }
            }
        }
    }
    return dis[t];
}

int main() {
    int m, s, t, u, v, d;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    while (m--) {
        scanf("%d%d%d", &u, &v, &d);
        temp.dis = d;
        temp.to = v;
        vec[u].push_back(temp);
    }
    printf("%d\n", dij(s, t) + dij(t, s));
    return 0;

}

void test2() {
    int T, N, A, B, C, sum, rd1, rd2, rd3;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> A >> B >> C;

        sum = 0;
        rd3 = 0;
        rd2 = 0;
        rd1 = 0;

        sum += C / 2;

        rd3 = C % 2;

        if (0 != rd3) {
            if (0 != A && 0 != B) {
                sum++;
                A--;
                B--;
            } else if (A >= 3) {
                sum++;
                A -= 3;
            }
        }

        sum += B / 3;
        rd2 = B % 3;
        if (2 == rd2) {
            // left 2
            if (A >= 2) {
                sum++;
                A -= 2;
            }
        } else if (1 == rd2) {
            // left 1
            if (A >= 4) {
                sum++;
                A -= 4;
            }
        }

        sum += A / 6;

        if (sum >= N) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

void test1() {
    long long x, f, d, p;

    cin >> x >> f >> d >> p;

    if (f > d / x) {
        cout << d / x << endl;
    } else {
        cout << (d - f * x) / (p + x) + f << endl;
    }
}