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
ll ask(ll a,ll b){
    ll x;
    cout<<"? "<<a<<' '<<b<<endl;
    cin>>x;
    fflush(stdout);
    return x;
}
int main(){
    ll i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    ll ans;
    for(i=2;i<=20;i++){
        ll x = ask(1,i);
        ll y = ask(i,1);
        if(x==-1){
            ans = i-1;
            break;
        }
        
        else if(x!=y){
            ans = x+y;
            break;
        }
    }
    cout<<"! "<<ans<<endl;
    //free();   //if pointer array
    return 0;
}
