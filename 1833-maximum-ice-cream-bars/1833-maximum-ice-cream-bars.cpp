class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count=0;
        sort(costs.begin(),costs.end());
        if(coins<costs[0]) return count;
        for(int i=0;i<costs.size();i++){
            // if(coins<=0) return count;
            coins-=costs[i];
            if(coins<0) return count;
            count++;
        }
        return count;
    }
};