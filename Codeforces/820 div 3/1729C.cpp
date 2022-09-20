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

int main(){
    int i,j,k,n,m,val,t=0,test;
    //freopen("000input.txt","r",stdin);
    cin>>test;
    while(test--){
        string tem;
        cin>>tem;
        int n = tem.size();
        vvi arr(26);
        char a = tem[0],b=tem[n-1];
        if(a>b)swap(a,b);
        int cnt = 0;
        for(i=0;i<tem.size();i++)
            if(tem[i]>=a and tem[i]<=b){
                arr[tem[i]-'a'].pb(i+1);
                cnt++;
            }
        
        vi ans;
        cout<<abs(tem[0] - tem[n-1])<<' '<<cnt<<endl;
        if(tem[0]<=tem[n-1]){
            for(auto vec: arr){
                for(int val: vec) cout<<val<<' ';
            }
            cout<<endl;
        }
        else {
            for(i=25;i>=0;i--){
                for(int val: arr[i]) cout<<val<<' ';
            }
            cout<<endl;
        }

    }
    //free();   //if pointer array
    return 0;
}
