#include <iostream>
#include <math.h>
using namespace std;

const int max_n = 1000001;
int w[8];

void init() {
	for(int i = 0; i < 8; i++) {
		w[i] = 0;
	}
}

int main(void) {
	init();
	int n, len = 1;

 	cin >> n;

	int a = 1, b = a * 10;
	while(true) {
		if(a <= n and n < b) {
			break;
		}
		len++;
		if(len > 7) {
			break;
		}
		a *= 10;
		b *= 10;
	}

	if(len != 1) {
		for(int i = 0; i < len; i++) {
			w[i] = pow(10, len - i - 1);
		}
	}

	// n = ¢²( (Wn + 1) * An )
	int result = 0, min_n = max_n;
	for(int a0 = 0; a0 < 10; a0++) {
		int x6 = 0;
		if(w[6] != 0) { x6 = a0 * (w[6] + 1); }
		for(int a1 = 0; a1 < 10; a1++) {
			int x5 = 0;
			if(w[5] != 0) { x5 = a1 * (w[5] + 1); }

			for(int a2 = 0; a2 < 10; a2++) {
				int x4 = 0;
				if(w[4] != 0) { x4 = a2 * (w[4] + 1); }

				for(int a3 = 0; a3 < 10; a3++) {
					int x3 = 0;
					if(w[3] != 0) { x3 = a3 * (w[3] + 1); }

					for(int a4 = 0; a4 < 10; a4++) {
						int x2 = 0;
						if(w[2] != 0) { x2 = a4 * (w[2] + 1); }

						for(int a5 = 0; a5 < 10; a5++) {
							int x1 = 0;
							if(w[1] != 0) { x1 = a5 * (w[1] + 1); }

							for(int a6 = 0; a6 < 10; a6++) {
								int x0 = 0;
								if(w[0] != 0) { x0 = a6 * (w[0] + 1); }

								if(x1 + x2 + x3 + x4 + x5 + x0 + x6 == n) {
									result = a0 * w[6] + a1 * w[5] + a2 * w[4] + a3 * w[3] + a4 * w[2] + a5 * w[1] + a6 * w[0];
									if(result <= min_n) {
										min_n = result;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	if(min_n == max_n) {
		cout << 0 << endl;
	}
	else {
		cout << min_n << endl;
	}
	return 0;
}