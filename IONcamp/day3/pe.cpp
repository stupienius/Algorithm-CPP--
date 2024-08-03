# include <bits/stdc++.h>
using namespace std;
#define int long long

int link[100005],len[100005];

int find(int n){
    while(n!=link[n]) n=link[n];
    return n;
}

void join(int x,int y){
    if(find(x) == find(y)) return;
    int a = find(x) , b = find(y);
    if (len[a]>len[b]) swap(a,b);
    len[b]+=len[a];
    link[a] = b;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin >> n >> m;

    vector<tuple<int,int,int>> e;
    int a,b,w;
    for(int i=0;i<m;++i){
        cin >> a >> b >> w;
        e.push_back({w,a,b});
    }

    sort(e.begin(),e.end());
    for(int i=1;i<n+1;++i){
        link[i]=i;
        len[i]=1;
    }
    int s=0;
    for (auto [w,a,b]:e){
        if (find(a)==find(b)) continue;
        s+=w;
        join(a,b);
    }
    int c=0;
    for(int i=1;i<n+1;++i) if(link[i]==i) c++;
    if (c==1) cout << s;
    else cout << "IMPOSSIBLE";

    return 0;
}
