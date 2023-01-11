class Solution {
public:
    
    int solve(vector<int> adj[], vector<bool> &hasApple, vector<bool> &vis, int node){
        if(vis[node]) return 0;
        vis[node]=true;
        int time=0;
        for(auto child : adj[node]){
            time+=solve(adj, hasApple, vis, child);
        }
        if(node==0) return time;
        if(hasApple[node] || time>0) time+=2;
        return time;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> adj[n];
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<bool> vis(n, false);
        int ans = solve(adj, hasApple, vis, 0);
        return ans;
    }
};