#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "ArgumentManager.h"
using namespace std;

int main(int argc, char* argv[])
{
	ArgumentManager am(argc, argv);
	string input = am.get("input");
	string output = am.get("output");

	ifstream ifs(input);
	ofstream ofs(output);
	string line, arr[4];
	int count = 0;

	while (getline(ifs, line))
	{
		if (line != "") 
		{
			arr[count] = line;
			count++;
		}
	}

	int m = arr[0].length();
	int n = arr[1].length();
	int o = arr[2].length();
	int p = arr[3].length();

	string X = arr[0];
	string Y = arr[1];
	string Z = arr[2];
	string W = arr[3];

	int len = 0;
	if (count == 0) 
	{
		ofs << "Len: " << arr[count - 1].length();
	}

	if (count == 2)
	{
		int **L = new int*[m + 1];
		for (int i = 0; i < m + 1; i++)
			L[i] = new int[n + 1];

		for (int i = 0; i < m + 1; i++)
			for (int j = 0; j < n + 1; j++)
				L[i][j] = -1;

		int i, j;
		for (i = 0; i <= m; i++)
		{
			for (j = 0; j <= n; j++)
			{
				if (i == 0 || j == 0)
					L[i][j] = 0;


				else if (X[i - 1] == Y[j - 1])
					L[i][j] = L[i - 1][j - 1] + 1;


				else
					L[i][j] = max(L[i - 1][j], L[i][j - 1]);
			}
		}
		len = L[m][n];
		ofs << "Len: " << len;
	}
	else if (count == 3) 
	{
		int ***L = new int**[m + 1];
		for (int i = 0; i < m + 1; i++)
		{
			L[i] = new int*[n + 1]();
			for (int j = 0; j < n + 1; j++) 
			{
				L[i][j] = new int[o + 1]();
			}
		}

		for (int i = 0; i < m + 1; i++)
			for (int j = 0; j < n + 1; j++)
				for (int k = 0; k < o + 1; k++)
					L[i][j][k] = -1;

		int i, j, k;
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				for (int k = 0; k <= o; k++)
				{
					if (i == 0 || j == 0 || k == 0)
					{
						L[i][j][k] = 0;
					}
					else if (X[i - 1] == Y[j - 1] && X[i - 1] == Z[k - 1])
					{
						L[i][j][k] = L[i - 1][j - 1][k - 1] + 1;
					}
					else
					{
						L[i][j][k] = max(max(L[i - 1][j][k], L[i][j - 1][k]), L[i][j][k - 1]);
					}
				}
			}
		}
		
		len = L[m][n][o];
		ofs << "Len: " << len;
	}
	else
	{
		int ****L = new int***[m + 1];
		for (int i = 0; i < m + 1; i++)
		{
			L[i] = new int**[n + 1]();
			for (int j = 0; j < n + 1; j++)
			{
				L[i][j] = new int*[o + 1]();
				for (int k = 0; k < o + 1; k++) 
				{
					L[i][j][k] = new int[p + 1]();
				}
			}
		}

		for (int i = 0; i < m + 1; i++)
			for (int j = 0; j < n + 1; j++)
				for (int k = 0; k < o + 1; k++)
					for(int l = 0; l < p + 1; l++)
					L[i][j][k][l] = -1;

		int i, j, k, l;
		for (int i = 0; i <= m; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				for (int k = 0; k <= o; k++)
				{
					for (int l = 0; l <= p; l++)
					{
						if (i == 0 || j == 0 || k == 0 || l == 0)
						{
							L[i][j][k][l] = 0;
						}
						else if (X[i - 1] == Y[j - 1] && X[i - 1] == Z[k - 1] && X[i-1] == W[l-1])
						{
							L[i][j][k][l] = L[i - 1][j - 1][k - 1][l-1] + 1;
						}
						else
						{
							L[i][j][k][l] = max(max(max(L[i - 1][j][k][l], L[i][j - 1][k][l]), L[i][j][k - 1][l]),L[i][j][k][l-1]);
						}
					}
				}
			}
		}

		len = L[m][n][o][p];
		ofs << "Len: " << len;
	}
	return 0;
}
