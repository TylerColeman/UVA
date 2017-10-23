#include<iostream>
#include<queue>
#include<stack>
using namespace std;
#define endl '\n'
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, command, value;
	while (cin >> n)
	{
		queue<int> q;
		priority_queue<int> pq;
		stack<int> s;
		bool stac, que, pque, badInput;
		stac = que = pque = true;
		badInput = false;
		int qOut, pqOut, stackOut;
		for (int i = 0; i < n; i++)
		{
			cin >> command >> value;
			if (command == 1)
			{
				q.push(value);
				pq.push(value);
				s.push(value);
			}

			else if (command == 2)
			{
				if (q.empty() || pq.empty() || s.empty()) { que = false; pque = false; stac = false; }
				else
				{
					qOut = q.front();
					pqOut = pq.top();
					stackOut = s.top();
					q.pop(); pq.pop(); s.pop();
					if (value != qOut) { que = false; }
					if (value != pqOut) { pque = false; }
					if (value != stackOut) { stac = false; }
				}

			}


		}

		if ((que && pque && stac) || (que && pque && !stac) || (que && !pque && stac) || (!que && pque && stac)) { cout << "not sure" << endl; }
		else if (que) { cout << "queue" << endl; }
		else if (pque) { cout << "priority queue" << endl; }
		else if (stac) { cout << "stack" << endl; }
		else { cout << "impossible" << endl; }

	}


	return 0;
}
