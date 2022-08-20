#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483648
#define mod 1000000007
#define ll long long
#define endl '\n'
#define PI (2*acos(0.0))
using namespace std;
char gap = 32;
template<typename T> 
ostream& operator<<(ostream &os, const vector<T> &v) { 
    os << '{'; 
    for (const auto &x : v) os << gap << x;
        return os << '}'; 
}
template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) {
        return os << '(' << p.first <<gap<<','<< gap << p.second << ')';
}
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { 
    cerr << ' ' << H;
     dbg_out(T...); 
}
#define dbg(...) cerr << '(' << #__VA_ARGS__ << ')'<<':', dbg_out(__VA_ARGS__)
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll,ll>
#define x first
#define y second
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define on(val,pos) (val|(1<<pos))
#define off(val,pos) (val&(~(1<<pos)))
#define check(val,pos) (val&(1<<pos))
#define all(n) n.begin(),n.end()
//first four adjacent,second four corner
// first four also work for 90-degree clock-wise rotation
//int row[8]={0,1,0,-1,1,-1,-1,1};
//int col[8]={1,0,-1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//replace less<int> to less_equal<int> to take duplicate values
const int N = 200005;
bool primo[N];
vi indexed[18000];
void priming(int n){
    for(int i=2;i*i<n;i++){
        if(!primo[i]){
            for(int j=i*i;j<=n;j+=i) primo[j]=1;
        }
    }
}
int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    priming(N-2);
    vi prime;
    map<int,int> id;
    for(i=2;i<N-2;i++) if(!primo[i]){
        prime.pb(i);
        id[i] = prime.size();
    } 
    // printf("%d",prime.size());
    //cout<<primo[1000]<<endl;
    scanf("%d %d",&n,&m);
    bool has;
    for(i=0;i<n;i++){
        scanf("%d",&val);
        for(j=0;prime[j]*prime[j]<=val;j++){
            has=false;
            while(val%prime[j]==0){
                val/=prime[j];
                has=true;
            }
            if(has)indexed[id[prime[j]]].pb(i);
        }
        if(val>1)indexed[id[val]].pb(i);
    }
    
    // for(i=0;i<20;i++)dbg(indexed[i]);
    
    for(i=0;i<m;i++){
        scanf("%d",&val);
        
        if(val==1){
            printf("%d\n",n);
            continue;
        }
        
        set<int> no_coprimes;
        for(j=0;prime[j]*prime[j]<=val;j++){
            has=false;
            while(val%prime[j]==0){
                val/=prime[j];
                has=true;
            }
            if(has){
                for(int u: indexed[id[prime[j]]]) no_coprimes.emplace(u);
            }
        }
        if(val>1)for(int u: indexed[id[val]]) no_coprimes.emplace(u);
        printf("%d\n",n-no_coprimes.size());
    }
    //free();   //if pointer array
    return 0;
}
