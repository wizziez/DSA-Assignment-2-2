#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll
#define endl '\n'

const ll mod = 1000000007;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1, vector<pair<int, int>>());

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (u == v && w < 0)
        {
            cout << "YES" << endl
                 << u << " " << v;
            exit(0);
        }
        graph[u].push_back({v, w});
    }

    vector<int> dist(n + 1, INT_MAX);
    vector<int> prevNode(n + 1, -1);
    dist[1] = 0;

    for (int _ = 0; _ < n - 1; _++)
    {
        for (int u = 1; u < n + 1; u++)
        {
            for (pair<int, int> x : graph[u])
            {
                if (dist[x.first] > dist[u] + x.second)
                {

                    prevNode[x.first] = u;
                    dist[x.first] = dist[u] + x.second;
                }
            }
        }
    }

    for (int u = 1; u < n + 1; u++)
    {
        if (dist[u] != INT_MAX)
        {
            for (pair<int, int> x : graph[u])
            {
                if (dist[x.first] > dist[u] + x.second)
                {
                    cout << "YES" << endl;
                    int slow = prevNode[u];
                    int fast = prevNode[slow];
                    while (slow != fast)
                    {
                        fast = prevNode[prevNode[fast]];
                        slow = prevNode[slow];
                    }
                    int start = slow;
                    vector<int> path;
                    path.push_back(start);
                    int end = prevNode[start];
                    while (end != start)
                    {
                        path.push_back(end);
                        end = prevNode[end];
                    }
                    path.push_back(end);
                    reverse(path.begin(), path.end());
                    for (int i = 0; i < (int)path.size(); i++)
                    {
                        cout << path[i] << " ";
                    }
                    cout << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;

    return 0;
}

