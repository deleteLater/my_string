// my_string.cpp : Defines the entry point for the console application.
// https://github.com/deleteLater/my_string

#include "stdafx.h"
#include "my_string.h"
#include <iostream>
#include <sstream>

using namespace std;
using namespace my_string;

void printStringInfo(const char *str) {
	cout << "stringContext:" << str << " length:" << my_strlen(str) << endl;
}

void my_test() {
	cout << "- - - 字符串操作测试 - - -" << endl;

	cout << "\n第一项:获取以'\\0\'结尾的字符串长度\n";
	cout << "  函数: " << "my_strlen(...)" << endl;
	cout << "    Hello: " << my_strlen("Hello") << endl;
	cout << "    This is a test :" << my_strlen("This is a test") << endl;

	cout << "\n第二项:字符串的复制(能够处理内存重复的情况): \n";
	cout << "  函数: " << "my_strcpy(...) && my_strncpy(...)" << endl;
	const char* src = "HaHa";
	char *des = new char[my_strlen(src) + 1]{};
	cout << "    全复制前: " << "src: " << src << "   des: " << des << endl;
	my_strcpy(des, src);
	cout << "    全复制后: " << "src: " << src << "   des: " << des << endl;
	src = "Wowo";
	cout << "    部分复制前: " << "src: " << src << "   des: " << des << endl;
	my_strncpy(des, src, 2);
	cout << "    部分复制后: " << "src: " << src << "   des: " << des << endl;
	delete des;

	cout << "\n第三项:字符串的拼接: \n";
	cout << "  函数: " << "my_strcat(...) && my_strncat(...)" << endl;
	des = new char[20]{ "Hello" };
	cout << "    全拼接前:  " << "src: " << ",Wolrd" << "  des: " << des << endl;
	my_strcat(des, ",World");
	cout << "    全拼接后:  " << "src: " << ",Wolrd" << "  des: " << des << endl;
	cout << "    部分拼接前:  " << "src: " << "!!@#@!!" << "  des: " << des << endl;
	my_strncat(des, "!!@#@!!", 2);
	cout << "    部分拼接后:  " << "src: " << "!!@#@!!" << "  des: " << des << endl;

	cout << "\n第四项:字符串中查找字符: \n";
	cout << "  函数: " << "my_strchr(...) && my_r_strchr(...)" << endl;
	cout << "  在 \"Hello\" 中查找字符 'l':\n";
	cout << "    正向查找: " << my_strchr("Hello", 'l') << endl;
	cout << "    逆向查找: " << my_r_strchr("Hello", 'l') << endl;

	cout << "\n第五项:字符串的比较\n";
	cout << "  函数: " << "my_strcmp(...) && my_strcmp_case(...) && my_strncmp(...) && my_strncmp_case(...)" << endl;
	cout << "     比较字符串 \"HeLlo~world\" && \"HElLo~WorLd\" :\n";
	cout << "       正常全比较:" << my_strcmp("HeLlo~world", "HElLo~WorLd") << endl;
	cout << "       忽略大小写的全比较:" << my_strcmp_case("HeLlo~world", "HElLo~WorLd") << endl;
	cout << "       正常部分比较前5个:" << my_strncmp("HeLlo~world", "HElLo~WorLd", 5) << endl;
	cout << "       忽略大小写部分比较前5个:" << my_strncmp_case("HeLlo~world", "HElLo~WorLd", 5) << endl;

	cout << "\n第六项:字串的查找\n";
	cout << "  文本: \"abdasnzdfzdfadava\"  模式:\"zdfz\"";
	const char* txt = "abdasnzdfzdfadava";
	int next[17];
	caculateNext(txt, next);
	ostringstream oos;
	for (int value : next)
		oos << value << " ";
	cout << "\n\t  -pattern's nextArray: " << oos.str() << endl;
	cout << "\t  -find 'zdfz' in it: " << my_strmat(txt, "zdfz") << endl;
	cout << "\t  -find 'zzzz' in it: " << my_strmat(txt, "zzzz") << endl;
}

int main()
{
	my_test();
	cin.get();
	return 0;
}