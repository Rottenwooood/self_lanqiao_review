#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// 计算逆序对数量
int count(const vector<int>& arr) {
	int ans = 0;
	for(int i = 0;i < 51;i++){
		for(int j = i + 1;j < 51;j++){
			if(arr[j] < arr[i]){
				ans++;
			}
		}
	}
	return ans;
}

// 主函数
int main() {
	int n = 51;
	vector<int> arr(51);
	for(int i = 0;i < n;i++){
		arr[i] = i;
	}
	int times = 0;
	double total_num = 0;
	for(int i1 = 0;i1 < n;i1++){
		for(int j1 = i1 + 1;j1 < n;j1++){
			swap(arr[i1],arr[j1]);
			for(int i2 = 0;i2 < n;i2++){
				for(int j2 = i2 + 1;j2 < n;j2++){
					swap(arr[i2],arr[j2]);
					total_num += count(arr);
					times++;
					swap(arr[i2],arr[j2]);
				}

			}
			swap(arr[i1],arr[j1]);
		}
	}
	
	double excepted_num = total_num / times;
	printf("%.2f",excepted_num);
    return 0;
}
