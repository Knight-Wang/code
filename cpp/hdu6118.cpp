#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXV = 505;
const int MAXE = 1005;

typedef pair<int, int> P;
struct edge
{
    int to, cap, cost, rev;   
};
vector<edge> G[MAXV];
int V, E;
int dist[MAXV], prevv[MAXV], preve[MAXE];

void add_edge(int from, int to, int cap, int cost)
{
    edge e;
    e.to = to;
    e.cap = cap;
    e.cost = cost;
    e.rev = G[to].size();
    G[from].push_back(e);
    e.to = from;
    e.cap = 0;
    e.cost = -cost;
    e.rev = G[from].size() - 1;
    G[to].push_back(e);
}
 
int min_cost_flow(int s, int t, int f)
{
    int res = 0;
    while (f > 0)
    {
        fill(dist, dist + V + 2, INF);
        dist[s] = 0;
        bool upd = true;
        while (upd)
        {
            upd = false;
            for (int v = 0; v <= V + 1; v++)
            {
                if (dist[v] == INF) continue;
                for (int i = 0; i < G[v].size(); i++)
                {
                    edge& e = G[v][i];
                    if (e.cap > 0 && dist[e.to] > dist[v] + e.cost)
                    {
                        dist[e.to] = dist[v] + e.cost;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        upd = true;
                    }
                }
            }
        }
        if (dist[t] == INF) break;
        if (dist[t] > 0) break;
        int d = f;
        for (int v = t; v != s; v = prevv[v])
        {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * dist[t];
        for (int v = t; v != s; v = prevv[v])
        {
            edge& e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}
int main()
{
    while (cin >> V >> E)
    {
        int a, b, c, d, u, v, k;
        for (int i = 0; i < MAXV; i++) G[i].clear();
        for (int i = 1; i <= V; i++)
        {
            cin >> a >> b >> c >> d;
            add_edge(0, i, b, a);
            add_edge(i, V + 1, d, -c);
        }
        for (int i = 1; i <= E; i++)
        {
            cin >> u >> v >> k;
            add_edge(u, v, INF, k);
            add_edge(v, u, INF, k);
        }
        cout << -min_cost_flow(0, V + 1, INF) << endl;
    }
    return 0;
}