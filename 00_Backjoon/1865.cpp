#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int tc;
int n, m, w;

struct edge 
{
	int s, e, t;
};

int MAX = 30000001;

bool time_travel(int n, vector<edge>& edges) 
{
	vector<int> dist(n + 1, MAX);

	int s, e, t;
	dist[1] = 0;
	for (int i = 1; i < n; i++) 
    {
		for (int j = 0; j < edges.size(); j++) 
        {
			s = edges[j].s;
			e = edges[j].e;
			t = edges[j].t;
			if (dist[e] > dist[s] + t) {
				dist[e] = dist[s] + t;
			}
		}
	}
	for (int j = 0; j < edges.size(); j++) 
    {
		s = edges[j].s;
		e = edges[j].e;
		t = edges[j].t;
		if (dist[e] > dist[s] + t) 
            return true;
		
	}

	return false;
}

void Input()
{
    cin >> tc;
}

void Solution()
{
    int s, e, t;
    while (tc--)
    {
        cin >> n >> m >> w;

		vector<edge> edges;

		for (int i = 0; i < m; i++) 
        {
			cin >> s >> e >> t;
			edges.push_back({ s,e,t });
			edges.push_back({ e,s,t });
		}
		for (int i = 0; i < w; i++) 
        {
			cin >> s >> e >> t;
			edges.push_back({ s,e,-t });
		}

        if (time_travel(n, edges))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}

void Solve()
{
    Input();
    Solution();
}

int main()
{
    ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    Solve();

    return 0;
}