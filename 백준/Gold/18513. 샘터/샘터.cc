#include <iostream>

#include <algorithm>

#include <vector>

#include <cstdio>

#include <cstring>

#include <queue>

#include <cmath>

#include <set>

#define FIO cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);

using namespace std;

 

 

int n, k;

queue<int> q;

set<int> s;

int dx[2] = { -1, 1 };

 

long long bfs()

{

	long long ans = 0;

	long long happy = 1;

 

	while (!q.empty())

	{

		int size = q.size();

 

		while (size--)

		{

			int water = q.front();

			q.pop();

 

			for (int i = 0; i < 2; i++)

			{

				int house = water + dx[i];

 

				if (s.count(house) == 0)

				{

					k--;

					ans += happy;

					s.insert(house);

					q.push(house);

 

					if (k == 0)

						return ans;

				}

			}

		}

		happy++;

	}

	return ans;

}

 

int main()

{

	FIO;

	cin >> n >> k;

 

	for (int i = 0; i < n; i++)

	{

		int a;

		cin >> a;

		q.push(a);

		s.insert(a);

	}

	cout << bfs();

}
