// my_string.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "my_string.h"
#include <iostream>

using namespace std;
using namespace my_string;

void printStringInfo(const char *str) {
	cout << "stringContext:" << str << " length:" << my_strlen(str) << endl;
}

void my_test() {
	cout << "--- StringOperations TEST ---" << endl;

	cout << "\n0.my_strlen(src): returns the length of a null-terminated('\\0') string.\n";
	cout << "    The length of 'Hello' is: " << my_strlen("Hello") << endl;

	cout << "\n1.my_strcpy(des,src): copy src to des.\n";
	const char* src = "HaHa";
	char *des = new char[my_strlen(src) + 1]();
	cout << "    Before copy: " << "src - " << src << "   des - " << des << endl;
	my_strcpy(des, src);
	cout << "    After copy: " << "src - " << src << "   des - " << des << endl;

	cout << "\n2.my_strncpy(des,src+1,2): copy 2 chs from src+1 to des.\n";
	cout << "    Before copy: " << "src - " << src << "   des - " << des << endl;
	my_strncpy(des, src + 1, 2);
	cout << "    After copy: " << "src - " << src << "   des - " << des << endl;

	char des_c[20] = "Hello";
	cout << "\n3.my_strcat(des_c,\",World\"): append src after des.(char des_c[20] = \"Hello\").\n";
	cout << "    Before catch:  " << "src - " << ",Wolrd" << "  des - " << des_c << endl;
	my_strcat(des_c, ",World");
	cout << "    After catch:  " << "src - " << ",Wolrd" << "  des - " << des_c << endl;

	cout << "\n4.my_strncat(des_c,\"!-!~!\",3): append 3 chs of src after des.\n";
	cout << "    Before catch:  " << "src - " << "!-!~!" << "  des - " << des_c << endl;
	my_strncat(des_c, "!-!~!", 3);
	cout << "    After catch:  " << "src - " << "!-!~!" << "  des - " << des_c << endl;

	cout << "\n5.my_strchr/my_r_strchr (src,ch): search first ch in src forward/inversely.\n";
	cout << "Search 'l' in \"Hello\"'s position:\n";
	cout << "ForwardSearch, l's position is: " << my_strchr("Hello", 'l') << endl;
	cout << "InverselySearch, l's position is: " << my_r_strchr("Hello", 'l') << endl;

	cout << "\n6.my_strmat(src,str): find str in src.\n";
	cout << "Search 'llo' in \"Hello\":\n";
	cout << my_strmat("Hello", "llo");
}

int main()
{
	my_test();

	cin.get();
	return 0;
}