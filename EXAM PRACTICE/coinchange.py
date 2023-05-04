
coins = list(map(int, (input("Enter coins: ").split())))
coins.sort()
denomination = int(input("Enter denomination: "))

def minCoins(coins, denomination):
    dp = [[0 for i in range(denomination + 1)] for j in range(len(coins) + 1)]
    for i in range(len(coins) + 1):
        dp[i][0] = 0
    for i in range(denomination + 1):
        dp[0][i] = float("inf")
    for i in range(1, len(coins) + 1):
        for j in range(1, denomination + 1):
            if(j < coins[i - 1]):
                dp[i][j] = dp[i - 1][j]
            else:
                dp[i][j] = min(dp[i][j - coins[i - 1]] + 1, dp[i - 1][j])
    return dp[len(coins)][denomination]

print(minCoins(coins, denomination))