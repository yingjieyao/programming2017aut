#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Point
{
	int x, y;
};

int n, m;
char map[101][101];
struct Point possible_moves_first[4] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
struct Point possible_moves_second[8] = { {-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1} };

int bfs(struct Point possible_moves[], int possible_moves_count, char character);

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		for(int i = 0; i < n; i++) cin >> map[i];
		cout << bfs(possible_moves_first, 4, '@') << ' ' << bfs(possible_moves_second, 8, '@') << endl;
	}
	return 0;
}

int bfs(struct Point possible_moves[], int possible_moves_count, char character)
{
	bool is_visited[100][100];
	queue<Point> queue;
	int count = 0;
	
	memset(is_visited, false, sizeof(is_visited));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(map[i][j] == character && !is_visited[i][j])
			{
				struct Point point;
				point.x = i;
				point.y = j;
				queue.push(point);
				is_visited[i][j] = true;
				count++;
				while(!queue.empty())
				{
					struct Point curr = queue.front();
					queue.pop();
					int curr_x = curr.x, curr_y = curr.y;
					for(int k = 0; k < possible_moves_count; k++)
					{
						int next_x = curr_x + possible_moves[k].x, next_y = curr_y + possible_moves[k].y;
						if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && !is_visited[next_x][next_y] && map[next_x][next_y] == character)
						{
							is_visited[next_x][next_y] = true;
							struct Point next;
							next.x = next_x, next.y = next_y;
							queue.push(next);
						}
					}
				}
			}
		}
	}
	
	return count;
}
