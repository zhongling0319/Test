#include <iostream>
using namespace std;

int main() {
	int num = 0x12345678;
	char* p = (char*)&num;
	if (*p == 0x12) {
		cout << "大端字节序" << endl;
	}
	else {
		cout << "小端字节序" << endl;
	}
	return 0;
}