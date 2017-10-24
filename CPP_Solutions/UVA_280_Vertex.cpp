/*
	Tyler Coleman: Uva Problem #280 Vertex: Usernam: Hackerman

	Data Structures used: Vector, Queue

	Tricks of the trade: This was just a breadth first search on a directed
						 graph to find unreachable nodes from any given start
						 vertex.
*/
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//max number of verts
#define SIZE 100
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int size, test;
	int val, start, vertex;


	while (cin >> size && size != 0)
	{
		//graph to hold our graph in an adjacency list
		vector<vector<int>> graph(SIZE + 1);
		

		int count = 0;
		cin >> vertex;
		//build graph in adjacency list
		while (count <= size && vertex != 0)
		{
			while (cin >> val && val != 0)
			{
				graph[vertex].push_back(val);
			}
			count++;
			cin >> vertex;
		}

		//num test cases
		cin >> test;
		
		for (int i = 0; i < test; i++)
		{

			//breadth first search algorithm.
			queue<int> Q;

			int counter = size;

			//boolean vector, hold true if the vert 
			//was never found and false otherwise.
			vector<bool> found(size + 1, true);

			//used in the BFS as a way to "check off" 
			//nodes that had already been found and 
			//marked.
			vector<bool> verts(SIZE + 1, false);

			//start vertex
			cin >> start;
			Q.push(start);
			while (!Q.empty())
			{
				int u = Q.front();
				Q.pop();
				for (int j = 0; j < graph[u].size(); j++)
				{
					if (verts[graph[u][j]] == false)
					{
						verts[graph[u][j]] = true;
						Q.push(graph[u][j]);
						found[graph[u][j]] = false;
						counter--;
					}
				}
			}


			cout << counter;
			//any vert in the found vector with the value
			//true was never reached with the BFS algorithm.
			for (int i = 1; i < found.size(); i++)
			{
				if (found[i] == true)
				{
					cout << " " <<  i;
				}
			}
			cout << endl;
		}




	}

	return 0;
}