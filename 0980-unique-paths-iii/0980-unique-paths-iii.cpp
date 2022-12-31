class Solution {
public:
    
    int dfs(vector<vector<int>> grid, int start_x, int start_y, int zero){
        if(start_x<0 || start_y<0 || start_x>=grid.size() || start_y>=grid[0].size() || grid[start_x][start_y]==-1) return 0;
        if(grid[start_x][start_y]==2){
            if(zero==-1){
                return 1;
            }
            return 0;
        }
        grid[start_x][start_y]=-1;
        zero--;
        int totalPaths = dfs(grid, start_x+1, start_y, zero) +
                        dfs(grid, start_x, start_y+1, zero) +
                        dfs(grid, start_x-1, start_y, zero) +
                        dfs(grid, start_x, start_y-1, zero);
        grid[start_x][start_y]=0;
        zero++;
        return totalPaths;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int zero=0, start_x=0, start_y=0; 
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    start_x=i;
                    start_y=j;
                }
                else if(grid[i][j]==0) zero++;
            }
        }
        return dfs(grid, start_x, start_y, zero);
    }
};