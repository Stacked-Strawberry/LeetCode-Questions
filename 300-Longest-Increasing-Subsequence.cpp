#include <iostream>
#include <vector>
using namespace std;

vector<int> findLIS(vector<int> nums) {
    int n = nums.size();
    if (n == 0) return {};
    vector<vector<int>> dp(n);  // dp[i] stores the LIS ending at index i

    // Every number alone is a valid subsequence
    for (int i = 0; i < n; i++) {
        dp[i].push_back(nums[i]);
    }

    // Build dp array
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i] && dp[j].size() + 1 > dp[i].size()) {
                dp[i] = dp[j]; // copy the best previous sequence
                dp[i].push_back(nums[i]); // add current number
            }
        }
    }

    // Find the longest sequence in dp[]
    vector<int> longest = dp[0];
    for (int i = 1; i < n; i++) {
        if (dp[i].size() > longest.size()) {
            longest = dp[i];
        }
    }
    return longest;
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2, 6};
    vector<int> lis = findLIS(nums);
    cout << "Length of LIS: " << lis.size() << endl;
    cout << "LIS: ";
    for (int num : lis) cout << num << " ";
    cout << endl;
}
