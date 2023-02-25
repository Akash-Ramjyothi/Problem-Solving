class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low=INT_MAX;
        int profittoday=0;
        int totalprofit=0;
        for(int i=0;i<prices.size();i++){
            //low=min(low,prices[i]);
            if(prices[i]<low){
                low=prices[i];
            }
            profittoday=prices[i]-low;
            //totalprofit=min(totalprofit,profittoday);
            if(totalprofit<profittoday){
                totalprofit=profittoday;
            }
        }
        return totalprofit;
    }
};