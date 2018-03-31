#include<iostream>
#include<queue>
using namespace std;

char Lib[102][102];
bool visited[102][102][10];
int K, R = 0, C = 0, T;
int Sx, Sy, Ex, Ey;
class P
{
public:
	/* 描述状态信息：坐标、时间点 */
	int x;
	int y;
	int t;
	P(int _x, int _y, int _t):x(_x), y(_y), t(_t) {}
};
queue<P> Points;

int main()
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	while (N--)
	{
		for (int i = 1; i <= 101; i++)
		{
			for (int j = 1; j <= 101; j++)
			{
				Lib[i][j] = '\0';
				for (int k = 0; k <= 9; k++)
					visited[i][j][k] = false;
			}
		}
		cin >> R >> C >> K;
		for (int i = 1; i <= R; i++)
		{
			for (int j = 1; j <= C; j++)
			{
				cin >> Lib[i][j];
				if (Lib[i][j] == 'S')
				{
					Sx = i;
					Sy = j;
				}
				if (Lib[i][j] == 'E')
				{
					Ex = i;
					Ey = j;
				}
			}
		}
		/* 初始化广搜队列并加入起点 */
		while (!Points.empty())
			Points.pop();
		P St(Sx, Sy, 0);
		Points.push(St);
		visited[Sx][Sy][0] = true;
		bool B = false;
		while (true)
		/* 进入广搜 */
		{
			if (Points.empty())
			{
				cout << "Oop!" << endl;
				break;
			}
			int X = Points.front().x;
			int Y = Points.front().y;
			int TT = Points.front().t;
			if (X == Ex && Y == Ey)
			{
				/* 到达终点 */
				B = true;
				T = TT;
				break;
			}
			if ((TT + 1) % K == 0)
			{
				/* 向四个方向尝试（注意模运算在判断中的作用） */
				if (Lib[X + 1][Y] != '\0' && visited[X + 1][Y][(TT + 1) % K] == false)
				{
					visited[X + 1][Y][(TT + 1) % K] = true;
					P tmp(X + 1, Y, TT + 1);
					Points.push(tmp);
				}
				if (Lib[X - 1][Y] != '\0' && visited[X - 1][Y][(TT + 1) % K] == false)
				{
					visited[X - 1][Y][(TT + 1) % K] = true;
					P tmp(X - 1, Y, TT + 1);
					Points.push(tmp);
				}
				if (Lib[X][Y - 1] != '\0' && visited[X][Y - 1][(TT + 1) % K] == false)
				{
					visited[X][Y - 1][(TT + 1) % K] = true;
					P tmp(X, Y - 1, TT + 1);
					Points.push(tmp);
				}
				if (Lib[X][Y + 1] != '\0' && visited[X][Y + 1][(TT + 1) % K] == false)
				{
					visited[X][Y + 1][(TT + 1) % K] = true;
					P tmp(X, Y + 1, TT + 1);
					Points.push(tmp);
				}
			}
			else
			{
				if (Lib[X + 1][Y] != '#' && Lib[X + 1][Y] != '\0' && visited[X + 1][Y][(TT + 1) % K] == false)
				{
					visited[X + 1][Y][(TT + 1) % K] = true;
					P tmp(X + 1, Y, TT + 1);
					Points.push(tmp);
				}
				if (Lib[X - 1][Y] != '#' && Lib[X - 1][Y] != '\0' && visited[X - 1][Y][(TT + 1) % K] == false)
				{
					visited[X - 1][Y][(TT + 1) % K] = true;
					P tmp(X - 1, Y, TT + 1);
					Points.push(tmp);
				}
				if (Lib[X][Y - 1] != '#' && Lib[X][Y - 1] != '\0' && visited[X][Y - 1][(TT + 1) % K] == false)
				{
					visited[X][Y - 1][(TT + 1) % K] = true;
					P tmp(X, Y - 1, TT + 1);
					Points.push(tmp);
				}
				if (Lib[X][Y + 1] != '#' && Lib[X][Y + 1] != '\0' && visited[X][Y + 1][(TT + 1) % K] == false)
				{
					visited[X][Y + 1][(TT + 1) % K] = true;
					P tmp(X, Y + 1, TT + 1);
					Points.push(tmp);
				}
			}
			Points.pop();
		}
		if (B)
			cout << T << endl;
	}
	return 0;
}
