#include <bits/stdc++.h>
#define ll long long
#define mem(a,b) memset(a,b,sizeof a)
using namespace std;
const int MAXN=20;
const int INF=0x3f3f3f3f;
const double eps=1e-6;
const double pi=acos(-1.0);
int board[MAXN][MAXN];
int status[MAXN][MAXN]; //表示当前状态 1为联通块中 2为联通块外
int mx[4]={0,1,0,-1};
int my[4]={1,0,-1,0};
int maxdp,N;
void flood(int i,int j,int col)
{
    status[i][j]=1;
    for(int k=0;k<4;k++){
        int x,y;
        x=i+mx[k];
        y=j+my[k];
        if(x>N||y>N||x<1||y<1)  continue;
        if(status[x][y]==1)     continue;
        status[x][y]=2;
        if(board[x][y]==col)
            flood(x,y,col);
    }
}
int h(){
    int num[10],cnt=0;
    mem(num,0);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(status[i][j]!=1&&num[board[i][j]]==0)
                cnt++,num[board[i][j]]++;
        }
    }
    return cnt;
}
int chooseColor(int col)
{
    int cnt=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(board[i][j]==col&&status[i][j]==2){
                cnt++;
                flood(i,j,col);
            }
        }
    }
    return cnt;
}
bool dfs(int depth)
{
    if(depth+h()>maxdp) return false;
    if(depth==maxdp) return true;
    int sta[MAXN][MAXN];
    memcpy(sta,status,sizeof sta);
    for(int i=0;i<6;i++){
        if(!chooseColor(i)) continue;
        if(dfs(depth+1))    return true;
        memcpy(status,sta,sizeof sta);
    }
    return false;
}
void solve()
{
    for(maxdp=0; ;maxdp++){
        mem(status,0);
        flood(1,1,board[1][1]);
        if(dfs(0))  break;
    }
    cout<<maxdp<<endl;
}
int main()
{
    //ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    while(cin>>N){
        if(N==0) break;
        for(int i=1;i<=N;i++)
            for(int j=1;j<=N;j++)
            cin>>board[i][j];
        solve();
    }
    return 0;
}
