/*
	Tyler Coleman: Uva Problem #10986 Sending Email: Username: Hackerman

	Data Structures used: Vector, Priority Queue, pair.

	Tricks of the trade: This is a straightforward shortest path problem
						 I used the dijkstras shortest path algorithm from
						 the competative programming book.
*/
#include<iostream>
#include<vector>
#include<queue>


using namespace std;

//define infinity for dijkstras. no weight will ever meet this value
#define INF 1000000
#define endl '\n'


typedef pair<int, int> ii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie();
	ii node;
	
	int cases;
	int start, finish;
	int numVerts, numEdges;
	int tmpVert1, tmpVert2, latency;

	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		
		cin >> numVerts >> numEdges >> start >> finish;
		vector <vector<pair<int, int>>> adjList(numVerts + 1);

		//build adjacency list, graph is undirected per problem
		//description, so if adjList[i][j] exists so does
		//adjList[j][i]
		for (int j = 0; j < numEdges; j++)
		{
			cin >> tmpVert1 >> tmpVert2 >> latency;
			node.first = tmpVert2; node.second = latency;
			adjList[tmpVert1].push_back(node);
			node.first = tmpVert1;
			adjList[tmpVert2].push_back(node);
		}


		//Dijkstras Algorithm from green book, Pg. 148
		vi dist(numVerts,INF);
		dist[start] = 0;
		priority_queue<ii, vector<ii>> pq;
		pq.push(ii(start, 0));
		while (!pq.empty())
		{
			ii front = pq.top(); pq.pop();
			int d = front.second, u = front.first;
			if (d > dist[u]) continue;

			for (int k = 0; k < adjList[u].size(); k++)
			{
				node = adjList[u][k];
				//relax edges
				if (dist[u] + node.second < dist[node.first])
				{
					dist[node.first] = dist[u] + node.second;
					pq.push(ii(node.first, dist[node.first]));
				}
			}

		}

		//if the shortest path is still INF, it was an unreachable node
		if (dist[finish] == INF)
		{
			cout << "Case #" << i + 1 << ": " << "unreachable" << endl;
		}
		else
		{
			cout << "Case #" << i + 1 << ": " << dist[finish] << endl;
		}
			
	}


	return 0;
}