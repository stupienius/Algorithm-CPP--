#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> maxProfitWithQueries(const vector<int>& prices, const vector<int>& queries) {
    int n = prices.size();
    int maxK = *max_element(queries.begin(), queries.end());
    vector<int> results(queries.size());
    
    if (n <= 1) {
        return results;  // 所有查詢結果為0
    }

    vector<vector<int>> dp(2, vector<int>(maxK + 1, 0));
    vector<int> maxDiff(maxK + 1, -prices[0]);
    int curr = 0, prev = 1;

    for (int i = 1; i < n; i++) {
        swap(curr, prev);

        for (int k = 1; k <= maxK; k++) {
            dp[curr][k] = max(dp[prev][k], prices[i] + maxDiff[k]);
            maxDiff[k] = max(maxDiff[k], dp[prev][k-1] - prices[i]);
        }
    }

    for (size_t i = 0; i < queries.size(); i++) {
        results[i] = dp[curr][queries[i]];
    }

    return results;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, p;
    cin >> n >> p;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    vector<int> queries(p);
    for (int i = 0; i < p; i++) {
        cin >> queries[i];
    }

    vector<int> results = maxProfitWithQueries(prices, queries);

    for (int result : results) {
        cout << result << '\n';
    }

    return 0;
}
