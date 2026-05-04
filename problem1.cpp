#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    if (!(cin >> s)) return 0;

    int n = s.length();
    int max_sum = 0;

    
    for (int i = 0; i < n; ++i) {
        int current_sum = 0;
        int seen = 0; 
        
        
        int limit = min(n, 26); 
        
        for (int j = 0; j < limit; ++j) {
            
            int idx = i + j;
            if (idx >= n) {
                idx -= n; 
            }
            
            int char_val = s[idx] - 'a';
            
           
            if ((seen & (1 << char_val)) != 0) {
                break; 
            }

            seen |= (1 << char_val);
            
            current_sum += (char_val + 1);
            
            
            if (current_sum > max_sum) {
                max_sum = current_sum;
            }
        }
    }

    cout << max_sum << "\n";

    return 0;
}
