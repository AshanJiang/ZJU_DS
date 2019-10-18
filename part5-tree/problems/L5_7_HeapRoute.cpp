#include <iostream>
constexpr auto MAXN = 1001;
constexpr auto MINH = -10001;
int H[MAXN], size;
void insert(int x);
int main() {
	H[0] = MINH;
	int N, M, a, i;
	std::cin >> N >> M;
	size = 0;
	while (N--) {
		std::cin >> a;
		insert(a);
	}
	for (i = 0; i < M; i++) {
		std::cin >> a;
		std::cout << H[a];
		while (a > 1) {
			a /= 2;
			std::cout << " " << H[a];
		}
		std::cout << std::endl;
	}
	return 0;
}

void insert(int x) {
	if (size == MAXN)
		return;
	int i;
	for (i = ++size; H[i / 2] > x; i /= 2)
		H[i] = H[i / 2];
	H[i] = x;
}
