#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+7;
int a[maxn];
int n;
vector<int> V;
map<int,int>H;
int dp[maxn];
int main(){
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<=n;i++)
            dp[i]=0;
        V.clear(),H.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            V.push_back(a[i]);
        }
        sort(V.begin(),V.end());
        V.erase(unique(V.begin(),V.end()),V.end());
        for(int i=0;i<V.size();i++)
            H[V[i]]=i+1;
        for(int i=0;i<n;i++){
            a[i]=H[a[i]];
        }
        int Ans = 0;
        for(int i=0;i<n;i++){
            dp[a[i]]=max(dp[a[i]],dp[a[i]-1])+1;
            Ans=max(dp[a[i]],Ans);
        }
        printf("%d\n",n-Ans);
    }
}
