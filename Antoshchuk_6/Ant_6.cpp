#include <iostream> //Developed by Roman Antoshchuk on 12.03.2024
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;

// A = {a = 1, b = 2, ... z = 24}
int charToIndex(char c) {
    return c - 'a' + 1;
}

// matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (auto val : row) {
            cout << setw(2) << val << " ";
        }
        cout << endl;
    }
}

// calculating Levenstein
int levensteinDistance(const string& s, const string& t) {
    int m = s.length(), n = t.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) dp[i][0] = i ? dp[i - 1][0] + charToIndex(s[i - 1]) : 0;
    for (int j = 0; j <= n; j++) dp[0][j] = j ? dp[0][j - 1] + charToIndex(t[j - 1]) : 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            int costReplace = abs(charToIndex(s[i - 1]) - charToIndex(t[j - 1]));
            int costDelete = charToIndex(s[i - 1]);
            int costInsert = charToIndex(t[j - 1]);

            dp[i][j] = min({
                dp[i - 1][j] + costDelete,    // delete
                dp[i][j - 1] + costInsert,    // paste
                dp[i - 1][j - 1] + costReplace // change
                });
        }
    }

    printMatrix(dp);

    return dp[m][n];
}

int main() {
    string s, t;

    cout << "s: ";
    cin >> s;

    cout << "t: ";
    cin >> t;

    cout << "s = " << s << endl;
    cout << "t = " << t << endl;

    int result = levensteinDistance(s, t);
    cout << "result: " << result << endl;

    return 0;
}