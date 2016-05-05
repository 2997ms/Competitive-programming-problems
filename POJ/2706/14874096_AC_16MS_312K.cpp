#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#pragma warning(disable:4996)
using namespace std;

const int si = 23;
const int num = 251;
int n;
int m;
int lastx, lasty;
int map[si][si];
bool link[num][num];

int posx[9] = { 0,-1,-2,-2,-1,1,2,2,1 };
int posy[9] = { 0,2,1,-1,-2,-2,-1,1,2 };

typedef class chess
{
public:
	int color;//黑棋：1 白棋：0
	int r, c;
	int connect[8];
	int pc;

	chess()
	{
		color = -1;
		pc = 0;
	}
}PEG;

void line_peg(PEG * peg, int i)
{
	int color = peg[i].color;
	for (int k = 1; k <= 8; k++)
	{
		int r = peg[i].r + posx[k];
		int c = peg[i].c + posy[k];

		if (r >= 0 && r <= n&&c >= 0 && c <= n)
		{
			if (map[r][c] && peg[map[r][c]].color == color)
			{
				switch (k)
				{
				case 1://30度
				{
					if (link[map[r][c - 2]][map[r + 1][c]])
					{
						break;
					}
					if (c - 3 >= 0 && link[map[r][c - 3]][map[r + 1][c - 1]])
					{
						break;
					}
					if (c + 1 <= n&&link[map[r][c - 1]][map[r + 1][c + 1]])
					{
						break;
					}
					if (r - 1 >= 0)
					{
						if (link[map[r - 1][c - 2]][map[r + 1][c - 1]])
						{
							break;
						}
						if (link[map[r - 1][c - 1]][map[r + 1][c]])
						{
							break;
						}
						if (link[map[r - 1][c]][map[r + 1][c - 1]])
						{
							break;
						}
					}
					if (r + 2 <= n)
					{
						if (link[map[r + 2][c - 2]][map[r][c - 1]])
						{
							break;
						}
						if (link[map[r + 2][c - 1]][map[r][c - 2]])
						{
							break;
						}
						if (link[map[r + 2][c]][map[r][c - 1]])
						{
							break;
						}
					}

					int a = map[peg[i].r][peg[i].c];
					int b = map[r][c];
					peg[a].connect[peg[a].pc++] = b;
					peg[b].connect[peg[b].pc++] = a;

					link[a][b] = link[b][a] = true;
					break;
				}
				case 2://60
				{
					if (link[map[r][c - 1]][map[r + 2][c]])
					{
						break;
					}
					if (r - 1 >= 0 && r + 1 <= n&& c-1>=0 && link[map[r - 1][c - 1]][map[r + 1][c]])
					{
						break;
					}
					if (r + 3 <= n&&link[map[r + 1][c - 1]][map[r + 3][c]])//
					{
						break;
					}
					if (c - 2 >= 0 && r + 1 <= n&&link[map[r + 1][c]][map[r][c - 2]])//
					{
						break;
					}
					if (r + 1 <= n&&c + 2 <= n&&link[map[r + 1][c]][map[r + 2][c - 2]])
					{
						break;
					}
					if (r + 2 <= n&&c - 2 >= 0 && link[map[r + 2][c]][map[r + 1][c - 2]])
					{
						break;
					}
					if (c - 1 >= 0 && c + 1 <= n&&link[map[r + 1][c - 1]][map[r][c + 1]])
					{
						break;
					}
					if (r + 2 <= n&&c - 1 >= 0 && c + 1 <= n&&link[map[r + 1][c - 1]][map[r + 2][c + 1]])
					{
						break;
					}
					if (c - 1 >= 0 && c + 1 <= n&&link[map[r][c - 1]][map[r + 1][c + 1]])
					{
						break;
					}

					int a = map[peg[i].r][peg[i].c];
					int b = map[r][c];
					peg[a].connect[peg[a].pc++] = b;
					peg[b].connect[peg[b].pc++] = a;
					link[a][b] = link[b][a] = true;
					break;
				}
				case 3://120
				{
					if (r + 1 <= n&&r - 1 >= 0 && c + 1 <= n&&link[map[r + 1][c]][map[r - 1][c + 1]])
					{
						break;
					}
					if (r + 2 <= n&&c + 1 <= n&&link[map[r + 2][c]][map[r][c + 1]])
					{
						break;
					}
					if (r + 3 <= n&&c + 1 <= n&&link[map[r + 3][c]][map[r + 1][c + 1]])
					{
						break;
					}
					if (c - 1 >= 0 && c + 1 <= n&&r + 1 <= n&&link[map[r][c - 1]][map[r + 1][c + 1]])
					{
						break;
					}
					if (r + 1 <= n&&c - 1 >= 0 && c + 1 <= n&&link[map[r + 1][c - 1]][map[r][c + 1]])
					{
						break;
					}
					if (r + 2 <= n&&c - 1 >= 0 && c + 1 <= n&&link[map[r + 2][c - 1]][map[r + 1][c + 1]])
					{
						break;
					}
					if (r + 1 <= n&&c + 2 <= n&&link[map[r + 1][c]][map[r][c + 2]])
					{
						break;
					}
					if (r + 2 <= n&&c + 2 <= n&&link[map[r + 1][c]][map[r + 2][c + 2]])
					{
						break;
					}
					if (r + 2 <= n&&c + 2 <= n&&link[map[r + 2][c]][map[r + 1][c + 2]])
					{
						break;
					}
					int a = map[peg[i].r][peg[i].c];
					int b = map[r][c];
					peg[a].connect[peg[a].pc++] = b;
					peg[b].connect[peg[b].pc++] = a;
					link[a][b] = link[b][a] = true;
					break;
				}
				case 4:
				{
					if (r + 1 <= n&& c + 1 <= n&&c - 1 >= 0 && link[map[r + 1][c - 1]][map[r][c + 1]])
					{
						break;
					}
					if (r + 1 <= n&&c + 2 <= n&&link[map[r + 1][c]][map[r][c + 2]])
					{
						break;
					}
					if (r + 1 <= n&&c + 3 <= n&&link[map[r + 1][c + 1]][map[r][c + 3]])
					{
						break;
					}
					if (c + 1 <= n&&r + 2 <= n&&link[map[r + 2][c]][map[r][c + 1]])
					{
						break;
					}
					if (r + 2 <= n&&c + 2 <= n&&link[map[r + 2][c + 1]][map[r][c + 2]])
					{
						break;
					}
					if (r + 2 <= n && c + 2 <= n&&link[map[r][c + 1]][map[r + 2][c + 2]])
					{
						break;
					}
					if (r + 1 <= n&&c + 1 <= n&&r - 1 >= 0 && link[map[r + 1][c]][map[r - 1][c + 1]])
					{
						break;
					}
					if (r + 1 <= n&&c + 1 <= n&&c - 1 >= 0 && link[map[r + 1][c + 1]][map[r][c - 1]])
					{
						break;
					}
					if (r + 1 <= n&&c + 2 <= n&&r - 1 >= 0 && link[map[r + 1][c + 1]][map[r - 1][c + 2]])
					{
						break;
					}
					int a = map[peg[i].r][peg[i].c];
					int b = map[r][c];
					peg[a].connect[peg[a].pc++] = b;
					peg[b].connect[peg[b].pc++] = a;
					link[a][b] = link[b][a] = true;
					break;
				}
				case 5:
				{
					if (r - 1 >= 0 && c + 1 <= n&&c - 1 >= 0 && link[map[r - 1][c - 1]][map[r][c + 1]])
					{
						break;
					}
					if (r - 1 >= 0 && c + 2 <= n&&link[map[r - 1][c]][map[r][c + 2]])
					{
						break;
					}
					if (r - 1 >= 0 && c + 3 <= n&&link[map[r - 1][c + 1]][map[r][c + 3]])
					{
						break;
					}

					if (c + 1 <= n&&r - 2 >= 0 && link[map[r - 2][c]][map[r][c + 1]])
					{
						break;
					}
					if (r - 2 >= 0 && c + 2 <= n&&link[map[r - 2][c + 1]][map[r][c + 2]])
					{
						break;
					}
					if (r - 2 >= 0 && c + 2 <= n&&c + 1 <= n&&link[map[r - 2][c + 2]][map[r][c + 1]])
					{
						break;
					}

					if (r + 1 <= n&&c + 1 <= n&&r - 1 >= 0 && link[map[r - 1][c]][map[r + 1][c + 1]])
					{
						break;
					}
					if (r + 1 <= n&&c + 1 <= n&&r - 1 >= 0 && link[map[r - 1][c + 1]][map[r + 1][c]])
					{
						break;
					}
					if (r + 1 <= n&&c + 2 <= n && link[map[r + 1][c + 1]][map[r + 1][c + 2]])
					{
						break;
					}
					int a = map[peg[i].r][peg[i].c];
					int b = map[r][c];
					peg[a].connect[peg[a].pc++] = b;
					peg[b].connect[peg[b].pc++] = a;
					link[a][b] = link[b][a] = true;
					break;
				}
				case 6:
				{
					if (r + 1 <= n && c + 1 <= n&&r - 1 >= 0 && link[map[r - 1][c]][map[r + 1][c + 1]])
					{
						break;
					}
					if (r - 2 >= 0 && c + 1 <= n&&link[map[r - 2][c]][map[r][c + 1]])
					{
						break;
					}
					if (r - 3 >= 0 && c + 1 <= n&&link[map[r - 3][c]][map[r - 1][c + 1]])
					{
						break;
					}

					if (c + 2 <= n&&r - 1 >= 0 && link[map[r - 1][c]][map[r][c + 2]])
					{
						break;
					}
					if (r - 2 >= 0 && c + 2 <= n&&link[map[r - 1][c]][map[r - 2][c + 2]])
					{
						break;
					}
					if (r - 2 >= 0 && c + 2 <= n&&link[map[r - 2][c]][map[r - 1][c + 2]])
					{
						break;
					}

					if (c - 1 >= 0 && c + 1 <= n&&r - 2 >= 0 && link[map[r - 1][c + 1]][map[r - 2][c - 1]])
					{
						break;
					}
					if (c - 1 >= 0 && c + 1 <= n&&r - 1 >= 0 && link[map[r - 1][c + 1]][map[r][c - 1]])
					{
						break;
					}
					if (c + 1 <= n&&c - 1 >= 0 && r - 1 >= 0 && link[map[r][c + 1]][map[r - 1][c - 1]])
					{
						break;
					}
					int a = map[peg[i].r][peg[i].c];
					int b = map[r][c];
					peg[a].connect[peg[a].pc++] = b;
					peg[b].connect[peg[b].pc++] = a;
					link[a][b] = link[b][a] = true;
					break;
				}
				case 7:
				{
					if (r + 1 <= n && c - 1 >= 0 && r - 1 >= 0 && link[map[r + 1][c - 1]][map[r - 1][c]])
					{
						break;
					}
					if (r - 2 >= 0 && c - 1 >= 0 && link[map[r][c - 1]][map[r - 2][c]])
					{
						break;
					}
					if (c - 3 >= 0 && r - 1 >= 0 && link[map[r - 1][c - 1]][map[r][c - 3]])
					{
						break;
					}

					if (c - 1 >= 0 && c + 1 <= n&&r - 1 >= 0 && link[map[r][c - 1]][map[r - 1][c + 1]])
					{
						break;
					}
					if (r - 1 >= 0 && c + 1 <= n&&c - 1 >= 0 && link[map[r - 1][c - 1]][map[r][c + 1]])
					{
						break;
					}
					if (r - 2 >= 0 && c - 1 >= 0 && c + 1 <= n&&link[map[r - 1][c - 1]][map[r - 2][c + 1]])
					{
						break;
					}

					if (r - 1 >= 0 && c - 2 >= 0 && link[map[r - 1][c]][map[r][c - 2]])
					{
						break;
					}
					if (c - 2 >= 0 && r - 2 >= 0 && link[map[r - 1][c]][map[r - 2][c - 2]])
					{
						break;
					}
					if (c - 2 >= 0 && r - 2 >= 0 && link[map[r - 2][c]][map[r - 1][c - 2]])
					{
						break;
					}
					int a = map[peg[i].r][peg[i].c];
					int b = map[r][c];
					peg[a].connect[peg[a].pc++] = b;
					peg[b].connect[peg[b].pc++] = a;
					link[a][b] = link[b][a] = true;
					break;
				}
				case 8:
				{
					if (c + 1 <= n && c - 1 >= 0 && r - 1 >= 0 && link[map[r][c - 1]][map[r - 1][c + 1]])
					{
						break;
					}
					if (r - 1 >= 0 && c - 2 >= 0 && link[map[r][c - 2]][map[r - 1][c]])
					{
						break;
					}
					if (c - 3 >= 0 && r - 1 >= 0 && link[map[r][c - 3]][map[r - 1][c - 1]])
					{
						break;
					}

					if (c - 2 >= 0 && r + 1 <= n&&r - 1 >= 0 && link[map[r - 1][c - 1]][map[r + 1][c - 2]])
					{
						break;
					}
					if (r - 1 >= 0 && r + 1 <= n&&c - 1 >= 0 && link[map[r - 1][c - 1]][map[r + 1][c]])
					{
						break;
					}
					if (r - 1 >= 0 && c - 1 >= 0 && r + 1 <= n&&link[map[r - 1][c]][map[r + 1][c - 1]])
					{
						break;
					}

					if (r - 2 >= 0 && c - 2 >= 0 && link[map[r][c - 2]][map[r - 2][c - 1]])
					{
						break;
					}
					if (c - 2 >= 0 && r - 2 >= 0 && link[map[r][c - 1]][map[r - 2][c - 2]])
					{
						break;
					}
					if (c - 1 >= 0 && r - 2 >= 0 && link[map[r][c - 1]][map[r - 2][c]])
					{
						break;
					}
					int a = map[peg[i].r][peg[i].c];
					int b = map[r][c];
					peg[a].connect[peg[a].pc++] = b;
					peg[b].connect[peg[b].pc++] = a;
					link[a][b] = link[b][a] = true;
					break;
				}
				}
			}
		}
	}
	return;
}

bool checkwin(PEG *peg,bool flag)
{
	int NUM = -1;
	if (!flag)
		NUM = map[lastx][lasty];

	for (int k = 0; k <= n; k++)
	{
		int p = map[0][k];
		if (p&&p != NUM&&peg[p].color == 1)
		{
			int queue[num];
			bool visit[num] = { false };
			int head = 0;
			int tail = 0;
			queue[tail++] = p;
			visit[p] = true;

			while (head < tail)
			{
				int s = queue[head++];
				if (peg[s].r == n)
					return true;

				for (int i = 0; i < peg[s].pc; i++)
				{
					int x = peg[s].connect[i];
					if (!visit[x])
					{
						visit[x] = true;
						if (!flag&&x==NUM)
						{
							continue;
						}
						queue[tail++] = x;
					}
				}
			}
		}
	}
	return false;
}

int main()
{
	//freopen("i.txt","r",stdin);
	//freopen("o.txt","w",stdout);

	while (cin >> n >> m)
	{
		if (!n&&!m)
			break;
		memset(map, 0, sizeof(map));
		memset(link, false, sizeof(link));

		PEG *peg = new PEG[m + 1];
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			cin >> x >> y;
			map[x][y] = i;

			peg[i].r = x;
			peg[i].c = y;

			if (i % 2)
				peg[i].color = 1;
			else
				peg[i].color = 0;
			if (i == m)
			{
				lastx = x;
				lasty = y;
			}
			line_peg(peg, i);
		}
		if (checkwin(peg, true) && !checkwin(peg, false))
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	//system("pause");
	return 0;
}
