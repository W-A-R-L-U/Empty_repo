#include <bits/stdc++.h>
using namespace std;


int findMaximumDistance(vector<string>& grid){
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
    queue<pair<int,int>> qu;
    pair<int,int> ps,pe;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]=='*'){
                qu.push({i,j});
                dis[i][j]=0;
            }else if(grid[i][j]=='S'){
                ps={i,j};
            }else if(grid[i][j]=='E'){
                pe={i,j};
            }
        }
    }
    vector<vector<int>> dirs={{-1,0},{1,0},{0,1},{0,-1}};
    while(!qu.empty()){
        auto [r,c]=qu.front();
        qu.pop();
        for(auto& dir:dirs){
            int nr=dir[0]+r;
            int nc=dir[1]+c;
            if(nr>=0 && nr<n && nc>=0 && nc<m && dis[nr][nc]==INT_MAX){
                dis[nr][nc]=dis[r][c]+1;
                qu.push({nr,nc});
            }
        }
    }
    // for(auto& v:dis){
    //     for(auto& i:v) cout<<i<<" ";
    //     cout<<"\n";
    // }
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({dis[ps.first][ps.second],ps});
    vector<vector<int>> vis(n,vector<int>(m,0));
    vis[ps.first][ps.second]=true;
    while(!pq.empty()){
        auto fr=pq.top();
        pq.pop();
        int d=fr.first;
        int r=fr.second.first;
        int c=fr.second.second;
        if(fr.second==pe){
            return d;
        }
        for(auto& dir:dirs){
            int nr=dir[0]+r;
            int nc=dir[1]+c;
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!='*'){
                int val=min(d,dis[nr][nc]);
                if(val>vis[nr][nc]){
                    vis[nr][nc]=val;
                    pq.push({val,{nr,nc}});
                }
            }
        }
    }
    return -1;
}

int main() {
    vector<string> grid={"S..*","..*.","....","...E"};
    cout<<findMaximumDistance(grid)<<"\n";
	
}
