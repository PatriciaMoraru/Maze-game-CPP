#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

char a[100][100];
int n, m, fi, fj, si, sj, ci, cj;


void print()
{
	int i, j;
	
	system("cls");
	
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			cout << a[i][j];
		}
		
		cout << endl;
	}
	
}

void move(int i, int j)
{
	if (i>=n || i<0) return;
	
	if (j>=m || j<0) return;
	
	if (a[i][j]=='#') return;
	
	a[ci][cj] = '.';
	
	ci = i;
	cj = j;
	
	a[ci][cj]='O';
	
}

int main ()
{
	int hi = 0;
	
	for (hi = 1; true ; hi++)
	{
		ifstream fin ("harta" + to_string(hi) + ".in");
		int i, j;
		char key;
		
		if (fin.is_open()==false)
		{
			return -1;
		}
		
		fin >> n;
		fin >> m;
		
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				fin >> a[i][j];
				
				if (a[i][j]=='X')
				{
					fi = i;
					fj = j;
				}
				
				else if (a[i][j]=='O')
				{
					si = i;
					sj = j;
				}
			}
		}
		
		ci = si;
		cj = sj;
		
		while (!(ci==fi && cj==fj))
		{
			
			print ();
			key = getch();
			
			//cout << key << endl;	
			
			switch (key)
			{
				case 75:
					move(ci, cj-1);
					break;
					
				case 72:
					move(ci-1, cj);
					break;
					
				case 77:
					move(ci, cj+1);
					break;
					
				case 80:
					move(ci+1, cj);
					break;
			}
		}
		
		
		print();
		cout << "Ai trecut nivelul !"<< endl;
		system("pause");
	}
	
	
	
	
	
	
}
