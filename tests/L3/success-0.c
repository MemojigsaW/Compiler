

bool foo(int x, int y);

int main(int x) {
	int x = 4 + 5;
	float y = -5.2+4.3-2.5*10.8;
	int z = -3*-2*-1;

	if (false) {
		foo(1,2);
	}
	while(false){
		foo(2,2);
	}
	false?foo(3,2):foo(4,2);



	for (;;) {
		int x = 3;
		int y = -3 + x * 5;
		foo(6, 5) ? 7 : (8);
		return 0;
	}
	return 1;
}
