#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int, int>
#define MOD 1e9 + 7
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

int n;

class comp
{
    public:
      vector<pii> nodes;
      int size = 0;
};

bool cmp(comp a, comp b)
{
  return a.size < b.size;
}

int main()
{
    fastio
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");

    fin >> n;

    int grid[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            char x; fin >> x;
            if(x == '#') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }

    vector<pii> edges[n][n];

    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < n; j++)
      {
        if(i - 1 >= 0) edges[i][j].push_back(make_pair(i - 1, j));
        if(i + 1 < n) edges[i][j].push_back(make_pair(i + 1, j));
        if(j - 1 >= 0) edges[i][j].push_back(make_pair(i, j - 1));
        if(j + 1 < n) edges[i][j].push_back(make_pair(i, j + 1));
      }
    }

    vector<comp> comps;
    int total = 0;

    bool visited[n][n];
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) visited[i][j] = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(visited[i][j] || grid[i][j] == 0) continue;
            visited[i][j] = true;
            queue<pii> q;
            comp currcomp;
            total++;
            q.push(make_pair(i, j));
            while(!q.empty())
            {
                pii curr = q.front(); q.pop();
                currcomp.size++;
                currcomp.nodes.push_back(curr);
                for(pii adjnode : edges[curr.first][curr.second])
                {
                  if(visited[adjnode.first][adjnode.second] || grid[adjnode.first][adjnode.second] == 0) continue;
                  visited[adjnode.first][adjnode.second] = true;
                  q.push(adjnode);
                }
            }
            comps.push_back(currcomp);
        }
    }
    sort(comps.begin(), comps.end(), cmp);
    int largest = comps[total - 1].size;

    int minperi = INT_MAX;
    for(int i = total - 1; i >= 0; i--)
    {
      if(comps[i].size != largest) break;
      int currperi = 0;
      for(pii node : comps[i].nodes)
      {
        for(pii adjnode : edges[node.first][node.second])
        {
          if(grid[adjnode.first][adjnode.second] == 0) currperi++;
        }
        currperi += 4 - edges[node.first][node.second].size();
      }
      minperi = min(currperi, minperi);
    }

    fout << largest << " " << minperi << "\n";
    
}