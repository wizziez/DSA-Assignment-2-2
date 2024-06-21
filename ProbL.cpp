#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>ii;

bool cmp(int i,int j)
{
    return i>j;
}

int main() {

    int t,i,n,m,num;

    cin>>t;

    while (t--)
    {
        cin>>n>>m;

        vector<int>v;
        queue<ii>q;

        for (i=0;i<n;i++)
        {
            cin>>num;
            q.push(ii(num,i));
            v.push_back(num);
        }

        sort(v.begin(),v.end(),cmp);

        i=0;
        int global = 0;

        while (!q.empty())
        {
            int u = q.front().first;
            int w = q.front().second;
            q.pop();

            if (u == v[i])
            {
                global++;
                if (w == m) break;
                i++;
            }
            else
            {
                q.push(ii(u,w));
            }
        }
        cout<<global<<endl;
    }

    return 0;
}

