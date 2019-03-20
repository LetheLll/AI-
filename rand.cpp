#include <bits/stdc++.h>
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int MAXN=1e5+100;
const int INF=0x3f3f3f3f;
const double eps=1e-6;
const double pi=acos(-1.0);
int main(){
    //ios::sync_with_stdio(false);
    freopen("in.txt","w",stdout);
    for(int i=0;i<20;i++){
        int N=rand()%8+1;
        cout<<N<<endl;
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                if(k==0)
                cout<<rand()%6;
                else
                cout<<' '<<rand()%6;
            }
            cout<<endl;
        }
    }
    return 0;
}
