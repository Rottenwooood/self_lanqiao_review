#include <bits/stdc++.h>
#include <string>
using namespace std;

int a[100] = { 5 ,6 ,8 ,6 ,9 ,1 ,6 ,1 ,2, 4, 9, 1, 9, 
8, 2, 3, 6, 4, 7, 7, 5, 9, 5, 0, 3, 8, 7, 5, 8, 
1, 5, 8, 6, 1, 8, 3, 0, 3, 7, 9, 2, 7 ,0 ,5 ,8,
8 ,5 ,7 ,0 ,9 ,9 ,1 ,9 ,4 ,4 ,6 ,8 ,6 ,3 ,3 ,8,
5 ,1 ,6 ,3 ,4 ,6 ,7 ,0 ,7, 8, 2, 7, 6, 8, 9, 5, 
6, 5, 6, 1, 4, 0, 1, 0, 0, 9, 4, 8, 0, 9, 1, 2, 
8, 5, 0, 2, 5, 3, 3};

int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};


int main()
{
	int ans = 0;
	for(int month = 1 ; month <= 12 ; month ++) 
	{
		for(int day = 1 ; day <= days[month] ; day ++ )
		{
			int date[8] = { 2 , 0 , 2 , 3 , month / 10 , month % 10 , day / 10 , day % 10} ;   // 枚举每一个日期 
			int index = 0 ;
			for(int i = 0 ; i < 100 ; i ++ )
			{
				if(a[i] == date[index])   // 逐位检查日期  
				{
					index ++ ; 
					if(index == 8)
					{
						ans ++;
						break ;
					}
				}
			}
		}	
	}
	cout << ans << endl ;
	return 0;
}

