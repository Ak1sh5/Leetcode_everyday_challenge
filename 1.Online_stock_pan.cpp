/*
The span of the stock's price today is defined as the maximum number of consecutive days 
(starting from today and going backward) for which the stock price was less than or equal to today's price.
If the price of a stock over the next 7 days were [100,80,60,70,60,75,85], then the stock spans would be [1,1,1,2,1,4,6].
*/

//Optimal apporach is using stacks which is called as monotonically decreasing stack.Take a stack store a pair of price and ans
//If the price is greater than top of stack then update ans+= top of stack price and pop the top ,do it till condtion fails then 
// fially add this price with answer to the stack

//Code
//TC: O(1)
//SC: O(n)

class StockSpanner { 
public:
    stack<pair<int,int>> st;
  
    int next(int price) {
       int ans=1;
       while(!st.empty() && st.top().first<=price )
        {
              ans+=st.top().second;
               st.pop();
        }
        st.push({price,ans});
        return ans;
    }
};
