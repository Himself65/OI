#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    while (cin >> N) {
        ll n = N;          
        ll k = 1;          
        ll nums = 10;       
        while (n - k * nums >= 0) {
            n -= k * nums;
            k++;
            if (k == 2) nums *= 9;
            else nums *= 10;
        }
        ll m = k == 1 ? 0 : pow(10, k - 1);
        ll nn = n / k + m;   
        ll mm = n % k;        
        cout << (nn % ll(pow(10, k - mm))) 
            / ll(pow(10, k - mm - 1)) << endl;
    }
    return 0;
}