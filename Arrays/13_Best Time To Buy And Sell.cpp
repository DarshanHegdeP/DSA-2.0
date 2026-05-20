#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost=prices[0];
        int profit=0;
        for(auto item: prices){
            profit=max(profit,item-cost);
            cost=min(cost,item);

            // Time Complexity: O(n) for iterating through the prices array once
            // Space Complexity: O(1) for using only a constant amount of extra space

            //or
            // for(int i=1;i<prices.size();i++){
            //     profit=max(profit,prices[i]-cost);
            //     if(prices[i]<cost){
            //         cost=prices[i];
            //     }        
            // }
        }
        return profit;
    }
};

int main(){
    Solution s;
    vector<int> prices={7,1,5,3,6,4};
    cout<<s.maxProfit(prices)<<endl;
    return 0;
}