#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long k;
    cin >> k;

    
    long long remainder = a[0] % k;
    for (int i = 1; i < n; ++i) {
        if (a[i] % k != remainder) {
            
            cout << -1 << "\n";
            return 0;
        }
    }

    
    sort(a.begin(), a.end());

   
    long long target = a[n / 2];

   
    long long min_operations = 0;
    for (int i = 0; i < n; ++i) {
        
        min_operations += abs(a[i] - target) / k;
    }

   
    cout << min_operations << "\n";

    return 0;
}