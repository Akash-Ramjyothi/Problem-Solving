class Solution {
public:
    typedef pair<int,int> P;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        
        int n=tasks.size();
        for(int i=0;i<n;i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(),tasks.end());
        
        int i=0;
        long long currentTime=0;
        while(i<n || !pq.empty()){
            if(pq.empty()){
                currentTime=max(currentTime, (long long) tasks[i][0]);
            }
            
            while(i<n && tasks[i][0]<=currentTime){
                pq.emplace(tasks[i][1],tasks[i][2]);
                i++;
            }
            
            auto[processingTime, index]=pq.top();
            pq.pop();
            currentTime+=processingTime;
            ans.push_back(index);
        }
        return ans;
    }
};