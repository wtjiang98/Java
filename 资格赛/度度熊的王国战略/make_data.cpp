#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("1.in","w",stdout);
    srand(time(NULL));
    for(int cas=0;cas<=300;cas++){
        int n=15,m= 100;
        cout<<n<<" "<<m<<endl;
        for(int i=0;i<m;i++){
            cout<<rand()%n+1<<" "<<rand()%n+1<<" "<<rand()%1000+1<<endl;
        }
    }
    for(int cas=0;cas<=10;cas++){
        int n=100,m=10000;
        cout<<n<<" "<<m<<endl;
        for(int i=0;i<n;i++){
            int a = i+1,b=rand()%n+1;
            if(a==b)b=5;
            cout<<a<<" "<<b<<" "<<rand()%1000+1<<endl;
        }
        for(int i=0;i<m-n;i++){
            cout<<rand()%n+1<<" "<<rand()%n+1<<" "<<rand()%100+1<<endl;
        }
    }
    for(int cas=0;cas<3;cas++){
        int n=2000,m=10000;
        cout<<n<<" "<<m<<endl;
        for(int i=0;i<n;i++){
            int a = i+1,b=rand()%n+1;
            if(a==b)b=5;
            cout<<a<<" "<<b<<" "<<rand()%1000+1<<endl;
        }
        for(int i=0;i<m-n;i++){
            cout<<rand()%n+1<<" "<<rand()%n+1<<" "<<rand()%100+1<<endl;
        }
    }
}
