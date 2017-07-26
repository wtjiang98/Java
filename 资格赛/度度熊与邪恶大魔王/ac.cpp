#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int a[maxn],k[maxn],p[maxn],b[maxn];
int n,m;
int dp[1005][11];
const int inf = 1e9;
int main(){
    while(scanf("%d%d",&n,&m)!=EOF){
        int P = 0;
        for(int i=0;i<n;i++){
            scanf("%d%d",&a[i],&b[i]);
            P=max(P,b[i]);
        }
        int flag = 0;
        for(int i=0;i<m;i++){
            scanf("%d%d",&k[i],&p[i]);
            if(p[i]>P)
                flag = 1;
        }
        if(flag == 0){
            printf("-1\n");
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<1005;i++){
            for(int j=0;j<11;j++)
                dp[i][j]=inf;
        }
        for(int i=0;i<1005;i++){
            for(int j=0;j<11;j++){
                for(int i2=0;i2<m;i2++){
                    if(p[i2]<=j)continue;
                    int A = min(i+p[i2]-j,1000);
                    dp[A][j]=min(dp[A][j],dp[i][j]+k[i2]);
                }
            }
        }
        for(int i=1003;i>=0;i--){
            for(int j=0;j<11;j++){
                dp[i][j]=min(dp[i+1][j],dp[i][j]);
            }
        }
        long long Ans = 0;
        for(int i=0;i<n;i++){
            Ans+=dp[a[i]][b[i]];
        }
        printf("%lld\n",Ans);
    }

}
