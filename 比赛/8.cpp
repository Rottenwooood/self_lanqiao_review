#include <bits/stdc++.h>
using namespace std;
#define int long long 
typedef pair<pair<int,int>,int>pii;
#define N 10100

int s[N],a[N];
signed main(){  
	//优化 
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);   
    
    int n;
    cin>>n;
    vector<pii>v;
    //输入，计算前缀和 
    for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
    //找出所有子数组，标记左右边界 
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            v.push_back({{s[j]-s[i-1],i},j});
        }
    }
    //按照前缀和的大小排序，从小到大 
    sort(v.begin(),v.end());
    int ans=1e18;
    
    for(size_t i=0;i<v.size()-1;i++){
        if(v[i].first.second > v[i+1].second ||v[i].second < v[i+1].first.second) 
            ans=min(ans,v[i+1].first.first-v[i].first.first);
    }
    cout<<ans<<endl;
    return 0 ;
}


