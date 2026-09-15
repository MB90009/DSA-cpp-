#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(int V, vector<int> adj[]){
    vector<int> vis(V,0);
    queue<int> q;
    vector<int> ans;

    for(int i = 0; i < V; i++){
        if(vis[i]) continue;

        q.push(i);
        vis[i] = 1;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto x : adj[node]){
                if(vis[x]) continue;

                q.push(x);
                vis[x] = 1;
            }
        }
    }

    return ans;
}


int main(){
    int n , m;
    cout<<"Enter n and m" <<endl;
    cin >> n >> m;

    vector<int> adj[n];

    for(int i = 0; i < m; i++){
        int u, v;
        cout<<"Enter edge: "<<endl;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    vector<int> ans;

    ans = bfs(n, adj);

    for(auto x : ans){
        cout<< x << " ";
    }

    return 0;

}