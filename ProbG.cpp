#include <bits/stdc++.h>
using namespace std;

int main() {
    int ver, ed;
    cin >> ver >> ed;

    vector<int> adj[ver + 1];

    while (ed--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(ver + 1, INT_MAX);

    parent[1] = -1;

    vector<int> dist(ver + 1, INT_MAX);

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : adj[node]) {
            if (dist[it] > 1 + dist[node]) {
                dist[it] = 1 + dist[node];
                parent[it] = node;
                q.push(it);
            }
        }
    }

    vector<int> path;

    if (dist[ver] == INT_MAX) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int x = ver;
    while (x != -1) {
        path.push_back(x);
        x = parent[x];
    }

    cout << path.size() << endl;

    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;

    return 0;
}

