#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("1.in","w",stdout);
    srand(time(NULL));
    for(int i=0;i<100;i++){
        int n = 10;
        cout<<n<<endl;
        for(int j=0;j<n;j++)
            cout<<rand()%10+5<<" ";
        cout<<endl;
    }
    for(int i=0;i<5;i++){
        int n = 100000;
        cout<<n<<endl;
        for(int j=0;j<n;j++)
            cout<<abs(rand()*rand()*rand()*rand())<<" ";
        cout<<endl;
    }
}
