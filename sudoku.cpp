
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
#define pii pair<int, int>
#define pid pair<int, double>
#define pli pair<long long, int>
#define pb push_back
#define llu long long unsigned
#define ll long long
#define vi vector<int>
#define MAX 1000000009
#define MAXSZ 45
#define MOD 1000000007
#define LOGSZ 17
#define EPS 0.000000000001
#define f first
#define s second
using namespace std;

int N;
int arr[10][10];
int st[10][10];
int r[10][10];
int c[10][10];
int b[10][10];
bool found = false;

int gb(int i) 
{
	return ((i-1) / 3) + 1;
}
int gbb(int i, int j)
{
	return 3*(i - 1) + j;
}

pii next(int i, int j)
{
	if(i == 9 && j == 9)
		return pii(-1, -1);
	if(j < 9)
		return pii(i, j+1);
	else
		return pii(i+1, 1);
}

void solve(int i, int j) 
{
	if(found) return;
	if(i == -1 && j == -1)
	{
		for(int i=1; i < 10; i++)
			for(int j=1; j< 10; j++)
				if(!r[i][j])
					return;
				else if(!c[i][j])
					return;
				else if(!b[i][j])
					return;
					
		for(int i=1; i < 10; i++)
		{
			for(int j=1; j < 10; j++)
				cout <<  arr[i][j] << " ";
			cout << endl;
		}
		found = true;
		return;
	}
	
	if(st[i][j])
	{
		pii p = next(i, j);
		solve(p.f, p.s);
		return;
	}
		
	for(int k = 1; k < 10; k++)
	{
		if(!r[i][k] && !c[j][k] && !b[gbb(gb(i), gb(j))][k])
		{
			r[i][k] = 1;
			c[j][k] = 1;
			b[gbb(gb(i), gb(j))][k] = 1;
			arr[i][j] = k;
			pii p = next(i, j);
			solve(p.f, p.s);
			r[i][k] = 0;
			c[j][k] = 0;
			b[gbb(gb(i), gb(j))][k] = 0;
		} 
	}
}

int main() 
{
	
	cin >> N;
	for(int i = 0; i < N; i++)
	{
		int x,y,z;
		cin >> x >> y >> z;
		arr[x][y] = z;
		st[x][y] = 1;
		r[x][z] = 1;
		c[y][z] = 1;
		b[gbb(gb(x), gb(y))][z] = 1;
	}
	solve(1, 1);
    return 0;
}
