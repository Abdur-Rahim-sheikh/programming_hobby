#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
class Solution {
    private:
    void dfs(int node,vi net[],bool visible[],string &col,set<char> &st){
        if(visible[node]) return;
        visible[node]=true;
        
        for(int edge: net[node]){
            if(col[edge]==col[node])dfs(edge,net,visible,col,st);
            else{
                st.insert(col[edge]);
            }
        }
    }
    public:
    vector<string> solve(int N, int M, int Q, string col,
                         vector<vector<int> > &Edge, vector<string> &query) {
        // code here
        
        vector<int> net[N];
        for(auto it: Edge){
            net[it[0]].pb(it[1]);
            net[it[1]].pb(it[0]);
        }
        bool visible[N] = {false};
        bool dp[26][26][26] = {false};
       
        for(int i=0;i<N;i++){
            
            if(!visible[i]){
                // printf("%d %d\n",i,visible[i]);
                set<char> st;
                
                dfs(i,net,visible,col,st);
                
                // for(char it: st)cout<<col[i]<<' '<<it<<endl;
                // cout<<endl;
                for(auto it1: st){
                    for(auto it2: st){
                        dp[col[i]-'a'][it1-'a'][it2-'a'] = 1;
                    }
                }
                
            }
        }
        
        vector<string> solved;
        for(string q: query){
            int a=q[0]-'a',b=q[1]-'a',c=q[2]-'a';
            if(dp[a][b][c] or dp[a][c][b] or dp[b][a][c] or dp[b][c][a] or dp[c][a][b] or dp[c][b][a]){
                solved.pb("YES");
            }
            else solved.pb("NO");
        }
        return solved;
    }
    
};


int main(){
    int T,N,M,Q;
    cin>>T;
    while(T--){
        cin>>N>>M>>Q;
        string col;
        cin>>col;
        vector<vi> Edge(M,vi(2));
        for(int i=0;i<M;i++)cin>>Edge[i][0]>>Edge[i][1];
        vector<string> query(Q);
        for(int i=0;i<Q;i++)cin>>query[i];

        Solution ob;
        vector<string> answer = ob.solve(N,M,Q,col,Edge,query);
        for(string it: answer) cout<< it<<'\n';
    }
}
// 1
// 10 13 4
// ddbeffddfb
// 5 8
// 1 8
// 4 8
// 8 9
// 7 8
// 3 4
// 6 9
// 4 6
// 0 1
// 5 8
// 6 9
// 3 5
// 3 9
// abc
// dca
// dba
// dbc