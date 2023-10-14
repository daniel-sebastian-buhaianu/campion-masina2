#include <fstream>
#define NMAX 54
#define MMAX 54
#define NRDMAX 1002
#define DIMMAX 6
using namespace std;
ifstream fin("masina2.in");
ofstream fout("masina2.out");
struct punct
{
	int x, y;
};
int dl[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};
punct cd[2][NMAX*MMAX];
int main()
{
	int n, m, i, j, nrd, dir[NRDMAX], lg[2], x, y;
	char a[NMAX][MMAX], s[DIMMAX];
	punct ps;
	fin >> n >> m;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			fin >> a[i][j];
			if (a[i][j] == '*')	
			{
				ps.x = i;
				ps.y = j;
			}
		}
	}
	fin >> nrd;
	for (i = 1; i <= nrd; i++)
	{
		fin >> s;
		switch(s[0])
		{
			case 'N':
				dir[i] = 0;
				break;
			case 'E':
				dir[i] = 1;
				break;
			case 'S':
				dir[i] = 2;
				break;
			default:
				dir[i] = 3;
		}
	}
	fin.close();
	for (j = 0; j <= m+1; j++)
	{
		a[0][j] = a[n+1][j] = 'X';
	}
	for (i = 0; i <= n+1; i++)
	{
		a[i][0] = a[i][m+1] = 'X';
	}
	lg[0] = 0;
	cd[0][lg[0]++] = ps;
	for (i = 1; i <= nrd; i++)
	{
		for (j = 0; j < lg[0]; j++)
		{
			a[cd[0][j].x][cd[0][j].y] = '.';
		}
		for (lg[1] = j = 0; j < lg[0]; j++)
		{
			x = cd[0][j].x;
			y = cd[0][j].y;
			while (1)
			{
				x += dl[dir[i]];
				y += dc[dir[i]];
				if (a[x][y] == '.')
				{
					cd[1][lg[1]].x = x;
					cd[1][lg[1]++].y = y;
					a[x][y] = '*';
				}
				else
				{
					break;
				}
			}
		}
		for (j = 0; j < lg[1]; j++)
		{
			cd[0][j] = cd[1][j];
		}
		lg[0] = lg[1];
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			fout << a[i][j];
		}
		fout << '\n';
	}
	fout.close();
	return 0;
}
// scor 100
