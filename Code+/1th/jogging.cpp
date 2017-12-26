#include <iostream>
using namespace std;
long long a, b, c;
long long x;
long long GCD(long long a, long long b) {
	if(b) while((a %= b) && (b %= a));
	return a + b;
}
long long LCM(long long a, long long b) {
	return a * b / GCD(a, b);
}

int main() {
    cin >> a >> b >> c;
    long long temp = LCM(a, b);
    x = LCM(temp, c);
    cout << x;
    
    return 0;
}