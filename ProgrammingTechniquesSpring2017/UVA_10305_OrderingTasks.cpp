/*
	Tyler Coleman: Uva Problem: 10305 Ordering Tasks:  Username: Hackerman

	Data Structures Used: Vector

	Tricks of the trade: This problem required a topological sort.
						 This sort is done using a depth first search 
						 and after each vertex is full explored, it is 
						 pushed on to a vector. this vector holds the 
						 list topologically sorted in reverse order.
*/
#include<iostream>
#include<vector>
using namespace std;

enum DFS { VISITED, UNVISITED };
//holds the vertices after a DFS algorithm
vector<int> topSort;
//holds the enumerated type DFS used in the DFS algorithm
vector<int> dfsNum;

void DFS_Topsort(int, vector<vector<int>>);

int main()
{

	int tasks, precedences;
	int t1, t2;

	while (cin >> tasks >> precedences && tasks + precedences != 0)
	{
		//clear globals after each itteration.
		topSort.clear();
		dfsNum.clear();
		
		for (int i = 0; i <= tasks; i++)
		{
			dfsNum.push_back(UNVISITED);
		}

		vector<vector<int>> adjList(tasks + 1);
		
		//create adjacency list
		//graph is directed.
		for (int i = 0; i < precedences; i++)
		{
			cin >> t1 >> t2;
			adjList[t1].push_back(t2);
		}

		//Depth first search
		for (int u = 0; u < adjList.size(); u++)
		{
			if (dfsNum[u] == UNVISITED)
			{
				DFS_Topsort(u, adjList);
			}
		}

		//output the top sort in reverse order
		//this creates the topological sorted vector.
		for (int j = topSort.size() - 1; j > 0; j--)
		{
			if (j == topSort.size() - 1) cout << topSort[j];
			else cout << " " << topSort[j];
		}
		cout << endl;
	}
	return 0;
}
/*
	Function: DFS_Topsort
	Params:	integer and adjacency List
	return type: void
	Description: A general Depth first search 
	with the added element of pushing vertices 
	onto a vector when they have been fully explored. 
	This vector is a topologically sortedlist of these vertices.
*/
void DFS_Topsort(int u, vector<vector<int>> adjList)
{
	dfsNum[u] = VISITED;
	for (int i = 0; i < adjList[u].size(); i++)
	{
		int v = adjList[u][i];
		if (dfsNum[v] == UNVISITED)
		{
			DFS_Topsort(v, adjList);
		}
	}
	topSort.push_back(u);
}