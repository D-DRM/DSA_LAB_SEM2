//program to remove duplicates(codeforces)
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main(){

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for(int & x : a) cin >> x;

        unordered_set<int> suffix;

        int count = 0;
        for(int i=n-1; i>=0; --i) {

            if(suffix.count(a[i])) break;

            suffix.insert(a[i]);
            count++;

        }

        cout << n - count << endl; 

    }

    return 0;
}