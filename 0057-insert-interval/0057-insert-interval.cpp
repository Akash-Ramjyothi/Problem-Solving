class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        for(auto it:intervals){
            if(newInterval[0]>it[1]){
                res.push_back(it);
            }
            else if(newInterval[1]<it[0]){
                res.push_back(newInterval);
                newInterval=it;
            }
            else{
                newInterval[0]=min(newInterval[0],it[0]);
                newInterval[1]=max(newInterval[1],it[1]);
            }
        }
        res.push_back(newInterval);
        return res;
    }
};