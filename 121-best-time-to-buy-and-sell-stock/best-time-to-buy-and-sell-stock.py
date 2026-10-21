class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        price = prices[0]
        profit = 0
        for x in prices:
            profit = max(profit,x-price)
            price = min(price,x)
        return profit
        