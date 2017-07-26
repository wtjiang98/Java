#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("1.in","w",stdout);
    srand(time(NULL));
    for(int cas=0;cas<=100;cas++){
        int n=10,m=5;
        cout<<n<<" "<<m<<endl;
        for(int i=0;i<n;i++){
            cout<<rand()%20+1<<" "<<rand()%11<<endl;
        }
        for(int i=0;i<m;i++){
            cout<<rand()<<" "<<rand()%10+1<<endl;
        }
    }
    for(int cas=0;cas<=100;cas++){
        int n=10,m=5;
        cout<<n<<" "<<m<<endl;
        for(int i=0;i<n;i++){
            cout<<rand()%1000+1<<" "<<rand()%11<<endl;
        }
        for(int i=0;i<m;i++){
            cout<<rand()<<" "<<rand()%10+1<<endl;
        }
    }
    for(int cas=0;cas<=2;cas++){
        int n=100000,m=500;
        cout<<n<<" "<<m<<endl;
        for(int i=0;i<n;i++){
            cout<<rand()%1000+1<<" "<<rand()%11<<endl;
        }
        for(int i=0;i<m;i++){
            cout<<rand()%10000+90000<<" "<<rand()%11+1<<endl;
        }
    }
}
