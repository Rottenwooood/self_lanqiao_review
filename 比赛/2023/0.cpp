//0.冷门函数
int gcd_val = gcd(a,b);
int lcm_val = lcm(a,b);

string s = "abcdefg";
string subs = s.substr(2,3);//cde

vector<int> arr1;
//初始化
sort(arr1.begin(),arr1.end());
auto it = s.lower_bound(4);
auto it2 = s.lower_bound(4);

int sum = accumulate(arr1.begin(),arr1.end(),0); 

ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);

double x = -3.14;
double abs_x = fabs(x);

double log2_x = log2(x);
double round_x = round(x);
double base = 2.0,exp = 3.0;
double res = pow(base,exp);
double x = 16.0;
double sqrt_x = sqrt(x);
