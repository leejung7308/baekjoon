#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
int d;
string dnum;
long long movex, movey;
bool changecheck = false;

void change(int num,int startdnum, bool xy)
{
	//x기준
	if (startdnum <0)
	{
		changecheck = true;
		return;
	}
	if (xy)
	{
		if (dnum[startdnum] == '2')
		{
			if (num == 1)
			{
				dnum[startdnum] = '1';
			}
			else if (num == -1)
			{
				dnum[startdnum] = '1';
				change(num, startdnum - 1, xy);
			}
		}
		else if (dnum[startdnum] == '1')
		{
			if (num == 1)
			{
				dnum[startdnum] = '2';
				change(num, startdnum - 1, xy);
			}
			else if (num == -1)
			{
				dnum[startdnum] = '2';
			}
		}
		else if (dnum[startdnum] == '3')
		{
			if (num == 1)
			{
				dnum[startdnum] = '4';
			}
			else if (num == -1)
			{
				dnum[startdnum] = '4';
				change(num, startdnum - 1, xy);
			}
		}
		else if (dnum[startdnum] == '4')
		{
			if (num == 1)
			{
				dnum[startdnum] = '3';
				change(num, startdnum - 1, xy);
			}
			else if (num == -1)
			{
				dnum[startdnum] = '3';
			}
		}
	}

	//y기준
	else
	{
		if (dnum[startdnum] == '2')
		{
			if (num == 1)
			{
				dnum[startdnum] = '3';
				change(num, startdnum - 1, xy);
			}
			else if (num == -1)
			{
				dnum[startdnum] = '3';
			}
		}
		else if (dnum[startdnum] == '1')
		{
			if (num == 1)
			{
				dnum[startdnum] = '4';
				change(num, startdnum - 1, xy);
			}
			else if (num == -1)
			{
				dnum[startdnum] = '4';
			}
		}
		else if (dnum[startdnum] == '3')
		{
			if (num == 1)
			{
				dnum[startdnum] = '2';
			}
			else if (num == -1)
			{
				dnum[startdnum] = '2';
				change(num, startdnum - 1, xy);
			}
		}
		else if (dnum[startdnum] == '4')
		{
			if (num == 1)
			{
				dnum[startdnum] = '1';
			}
			else if (num == -1)
			{
				dnum[startdnum] = '1';
				change(num, startdnum - 1, xy);
			}
		}
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> d >> dnum;
	cin >> movex >> movey;
	//dnum바꿀위치
	int startdnum = 0;
	
	while (d)
	{
		long long dpow = pow(2, d-1);
		long long movexcount = movex / dpow;
		long long moveycount = movey / dpow;
		movex = movex % dpow;
		movey = movey % dpow;
		
		change(movexcount, startdnum, true);
		change(moveycount, startdnum, false);
		if (changecheck)
		{
			cout << "-1";
			return 0;
		}
		startdnum++;
		d--;

	}
	cout << dnum;
}