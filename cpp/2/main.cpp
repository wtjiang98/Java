#include<algorithm>
#include<iostream>
#include<cstring>
#include<fstream>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#define LL long long
#define FF(i,a,b) for(int i=a;i<=b;++i)
#define RR(i,a,b) for(int i=a;i>=b;--i)
#define SC(x) scanf("%d",&x)
#define SCC(x,y) scanf("%d%d",&x,&y)
#define SCCC(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define SS(x) scanf("%s",x)
#define PR(x) printf("%d\n",x)
#define CL(a,b) memset(a,b,sizeof(a))
#define ll rt<<1
#define rr rt<<1|1
#define mid int m=(x+((y-x)>>1))
#define lson x,m,rt<<1
#define rson m+1,y,rt<<1|1
#define lowbit(x) (x&-x)
#define PB push_back
#define pii pair<int, int>
#define mp(x, y) make_pair(x, y)
#define IN freopen("in.txt","r",stdin)
#define OUT freopen("out.txt","w",stdout)
#define fi freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;

const int N = 100000 + 10;
const int inf = 1e9;

int d[1010];
vector<int>path[1010];
int val[105], cost[105];

int n, m;

bool better(vector<int> a, vector<int> b)
{
    int sza = a.size(), szb = b.size(), i = 1, j = 1;
    while(i < sza && j < szb)
    {
        if(a[i] != b[j])
            return a[i] < b[j];
        ++i;
        ++j;
    }
    return i == sza;
}

int main()
{
#ifndef ONLINE_JUDGE
    IN;
#endif

    int _; SC(_); int cc = 0;
    while(_--)
    {
        SCC(m, n);
        FF(i, 0, m) path[i].clear(), path[i].PB(0);
        ///scan
        FF(i, 1, n){
            SCC(val[i], cost[i]);
        }
        ///go dp
        FF(i, 1, n)
        {
            RR(j, m, 0)
            {
                if(j - cost[i] >= 0){
                    if(d[j-cost[i]] + val[i] > d[j]){
                        d[j] = d[j-cost[i]] + val[i];
                        ///
                        path[j] = path[j-cost[i]];
                        path[j].PB(i);
                        path[j][0] += i;
                    }
                    else if(d[j-cost[i]]+val[i] == d[j]){
                        ///d[j] ²»±ä
                        if(path[j-cost[i]][0] + i < path[j][0]){
                            path[j] = path[j-cost[i]];
                            path[j].PB(i);
                            path[j][0] += i;
                        }
                        else if(path[j-cost[i]][0] + i == path[j][0]){
                            path[j-cost[i]].PB(i);
                            path[j-cost[i]][0] += i;
                            if(better(path[j-cost[i]], path[j])){
                                path[j] = path[j-cost[i]];
                            }
                            path[j-cost[i]].pop_back();
                            path[j-cost[i]][0] -= i;
                        }
                    }
                }
            }
        }

    }
    return 0;
}
