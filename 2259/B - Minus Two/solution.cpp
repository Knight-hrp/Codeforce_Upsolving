#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int even0 = 0,even2 = 0, odd = 0, maxi = 0;
 
        unordered_map <int, int> mp;
        for(int i = 0; i < n; i++)
        {
            mp[a[i]]++;
            maxi = max(maxi, mp[a[i]]);
            if(a[i] % 2 == 0)
            {
                if(a[i] % 4 == 0) even0++;
                else even2++;
            }
            else odd++;
        }
        cout << max(maxi, max(even0, max(even2, odd))) << endl;
 
    }
    return 0;
}
 