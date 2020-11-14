

bool foo(int x);

int main() {
	for (;;) {
		int x = 3;
		int y = -3 + x * 5;
		foo(6) ? 7 : (8);
		return 0;
	}
}
