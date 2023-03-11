#include<iostream>
#include<algorithm>
using namespace std;
const int N=100;
int nodeset[N];
int n, m;
struct Edge{
    int u;
    int v;
    int w;
}e[N*N];
bool comp(Edge x, Edge y){
    return x.w<y.w;
}
void Init(int n)
{
    for(int i=1;i<=n;i++)
        nodeset[i]=i;
}
int Merge(int a, int b)
{
    int p=nodeset[a];
    int q=nodeset[b];
    if(p==q) return 0;
    for(int i=1;i<=n;i++)//检查所有结点，把集合号是q的改为p
    {
      if(nodeset[i]==q)
        nodeset[i]=p;//a的集合号赋值给b集合号
    }
    return 1;
}
int Kruskal(int n)
{
    int ans=0;
    for(int i=0;i<m;i++)
        if(Merge(e[i].u,e[i].v))
        {
            ans+=e[i].w;
            n--;
            if(n==1)
                return ans;
        }
    return 0;
}
int main()
{
    cout<<"输入结点数n和边数m:"<<endl;
    cin>>n>>m;
    Init(n);
    cout<<"输入结点数u,v和边值w:"<<endl;
    for(int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e,e+m,comp);
    int ans=Kruskal(n);
    cout<<"最小的花费是："<<ans<<endl;
    return 0;
}
