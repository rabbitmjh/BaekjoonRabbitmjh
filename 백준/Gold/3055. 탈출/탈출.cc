#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;

int dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
class Graph {
public:
	int map[51][51];
	int R, C;
	int Dx, Dy;
	struct ptr {
		int x;
		int y;
	};
	queue<struct ptr> water;
	queue<struct ptr> move;
	Graph() {}
	Graph(int r, int c) {
		int i, j;
		for (i = 0; i < r; i++)
			for (j = 0; j < c; j++)
				map[i][j] = 1;
		R = r;
		C = c;
	}

	void makeStart(int i, int j) {
		struct ptr tmp;
		map[i][j] = 1;
		tmp.x = i;
		tmp.y = j;
		move.push(tmp);
	}

	void makeWater(int i, int j) {
		struct ptr tmp;
		map[i][j] = -1;
		tmp.x = i;
		tmp.y = j;
		water.push(tmp);
	}

	int BFS() {
		int level = 0;
		int i, j;
		int wsize, msize;
		struct ptr tmp, temp;

		while (water.empty() != true || move.empty() != true) {
			wsize = water.size();
			msize = move.size();

			for (i = 0; i < wsize; i++) {
				tmp = water.front();
				water.pop();
				for (j = 0; j < 4; j++) {
					if (tmp.x + dx[j] < 0 || tmp.x + dx[j] >= R || tmp.y + dy[j] < 0 || tmp.y + dy[j] >= C)
						continue;
					if (tmp.x + dx[j] == Dx && tmp.y + dy[j] == Dy)
						continue;
					if (map[tmp.x + dx[j]][tmp.y + dy[j]] != -1) {
						temp.x = tmp.x + dx[j];
						temp.y = tmp.y + dy[j];
						map[temp.x][temp.y] = -1;
						water.push(temp);
					}
				}
			}

			for (i = 0; i < msize; i++) {
				tmp = move.front();
				move.pop();
				if (tmp.x == Dx && tmp.y == Dy)
					return level;

				for (j = 0; j < 4; j++) {
					if (tmp.x + dx[j] < 0 || tmp.x + dx[j] >= R || tmp.y + dy[j] < 0 || tmp.y + dy[j] >= C)
						continue;

					if (map[tmp.x + dx[j]][tmp.y + dy[j]] == 1) {
						temp.x = tmp.x + dx[j];
						temp.y = tmp.y + dy[j];
						map[temp.x][temp.y] = 0;
						move.push(temp);
					}
				}
			}
			level++;
		}
		return -1;
	}
};

int main() {
	int r, c, i, j;
	char input;
	int result;
	scanf("%d %d", &r, &c);
	Graph G(r, c);
	scanf("%c", &input);
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			scanf("%c", &input);
			if (input == 'D') {
				G.Dx = i;
				G.Dy = j;
			}
			else if (input == 'X')
				G.map[i][j] = -1;
			else if (input == '*')
				G.makeWater(i, j);
			else if (input == 'S')
				G.makeStart(i, j);
		}
		scanf("%c", &input);
	}
	result = G.BFS();

	if (result == -1)
		printf("KAKTUS\n");
	else
		printf("%d", result);

	return 0;
}