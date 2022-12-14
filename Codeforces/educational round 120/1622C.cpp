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
//int row[8]={0,-1,0,1,1,-1,-1,1};
//int col[8]={-1,0,1,0,-1,-1,1,1};
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
//replace less<int> to less_equal<int> to take duplicate values

int main(){
    ll i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;

    while(test--){
        cin>>n>>k;
        vll arr(n);
        
        for(auto &a: arr)cin>>a;
        
        sort(all(arr));
        for(i=1;i<n;i++)arr[i]+=arr[i-1];

        if(n==1){
            ll ans = arr[0]>k?arr[0] - k: 0;
            cout<<ans<<endl;
            continue;
        }
        // else if(arr[n-1]<=k){
        //     cout<<0<<endl;
        //     continue;
        // }
        ll mini = k/n;
        ll total = arr[n-1];

        for(i=0;i<=n;i++){
            ll chosen = mini-i;
            ll tem = 0;
            if(chosen<arr[0]) tem = arr[0]-chosen;
            else chosen = arr[0];
            // dbg(chosen,tem);
            ll pos=0;
            for(int i=n/2;i>=1;i/=2){
                while(pos+i<n and arr[pos+i]+(n-pos-i-1)*chosen-tem <= k)pos+=i;
            }
            // dbg(chosen,tem,n,pos);
            total = min(total,tem+n-pos-1);
        }
        // dbg("new new");
        cout<<total<<endl;

    }
    //free();   //if pointer array
    return 0;
}
