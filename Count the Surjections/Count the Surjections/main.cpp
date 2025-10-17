#include <iostream>
#include <cstdint>

using namespace std;
using uin = std::uint64_t;

uin factorial(uin m) {
	if (m > 0) {
		return (m * factorial(m - 1));
	}
	else {
		return 1;
	}
}

uin power(uin n, uin m) {
	uin pow = n;
	for (uin i = 1; i < m; i++) {
		pow *= n;
	}
	return pow;
}

uin C(uin n, uin i) {
	if (i == 0 || n == 0 || i == n) {
		return 1;
	}
	else {
		return (C(n - 1, i - 1) + C(n - 1, i));
	}
}

uin S(uin m, uin n) {
	if (n == 1) {
		return 1;
	}
	else if (m < n) {
		return 0;
	}
	else if (m == n) {
		return (factorial(m));
	}
	else {
		uin chunks = 0;
		for (uin i = 1; i < n; i++) {
			uin chunk = C(n, i) * S(m, i);
			chunks += chunk;
		}
		return (power(n, m) - chunks);
	}
}

int main() {
	uin a, b;
	cout << "Enter the sizes for two sets to calulate the surjections. 0 0 will end the program.\n";

	while (cin >> a >> b && (a != 0 || b != 0)) {
		uin result = S(a, b);
		cout << "S(" << a << "," << b << ") = " << result << "\n";
	}

	return 0;
}