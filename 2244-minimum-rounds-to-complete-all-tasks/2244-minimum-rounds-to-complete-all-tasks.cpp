class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int> mp;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        int minround=0;
        for(auto it:mp){
            int count=0;
            if(it.second==1) return -1;
            while(it.second>=3){
                it.second-=3;
                count++;
            }
            if(it.second) count++;
            minround+=count;
        }
        return minround;
    }
};