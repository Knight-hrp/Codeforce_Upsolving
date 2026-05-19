#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    // Array to store the suffix counts of '1' and '3'
    vector<int> suff13(n + 1, 0);
    
    // Build suffix array from right to left
    for (int i = n - 1; i >= 0; --i) {
        suff13[i] = suff13[i + 1] + (s[i] == '1' || s[i] == '3' ? 1 : 0);
    }
    
    int max_kept = 0;
    int pref2 = 0;
    
    // Iterate through all possible split points
    for (int i = 0; i <= n; ++i) {
        // Calculate characters kept if we split before index i
        max_kept = max(max_kept, pref2 + suff13[i]);
        
        // Update the prefix count of '2' for the next iteration
        if (i < n && s[i] == '2') {
            pref2++;
        }
    }
    
    // Minimum removals is total length minus maximum kept characters
    cout << n - max_kept << "
";
}
 
int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}