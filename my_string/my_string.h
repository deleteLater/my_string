#pragma once

#include <assert.h>

namespace my_std {
	int my_tolower(int c) {
		//for ASCII Codec
		if (c >= 'A' && c <= 'Z')
			return (c + ('a' - 'A'));
		return c;
	}
	bool my_isDigit(char ch) {
		if (ch >= '0' && ch <= '9')
			return true;
		return false;
	}
}

namespace my_string {
	int no_pos = -1;	//0xffffffff
	using namespace my_std;
	//can deal with overlapMemory
	char* my_memcpy(char* des, const char* src, size_t len) {
		assert(des != nullptr && src != nullptr);
		char *ret = des;
		bool overlapMemeryAfterSrc = (des > src && src + len >= des);
		if (overlapMemeryAfterSrc) {
			//copy reversely

			des += len - 1;
			src += len - 1;
			while ((len--) > 0 && (*des-- = *src--) != '\0');
			return ret;
		}
		else {
			while ((len--) > 0 && (*des++ = *src++) != '\0');
			*des = '\0';
			return ret;
		}
	}

	size_t my_strlen(const char* src) {
		assert(src != nullptr);
		size_t ret = 0;
		while (*src != '\0') {
			ret++;
			src++;
		}
		return ret;
		/*
		code 1:
			const char* eos = src;
			while(*eos++);
			return (size_t)(eos - src - 1);
		*/

		/*
		code 2:
			assert(src != nullptr);
			if(*src == '\0')
				return 0;
			return 1+my_strlen(++src);

			more simple:
			assert(src != nullptr);
			return (*src == '\0') ? 0 : my_strlen(++str);
		*/
	}

	char* my_strcpy(char* des, const char* src) {
		my_memcpy(des, src, my_strlen(src));
		return des;
	}

	char* my_strncpy(char* des, const char* src, size_t len) {
		my_memcpy(des, src, len);
		return des;
	}

	char* my_strcat(char* des, const char* src) {
		char* ret = des;
		while (*des != '\0') {
			des++;
		}
		my_memcpy(des, src, my_strlen(src));
		return ret;
	}

	char* my_strncat(char* des, const char* src, size_t len) {
		char* ret = des;
		while (*des != '\0') {
			des++;
		}
		my_memcpy(des, src, len);
		return ret;
	}

	int my_strchr(const char* src, char ch) {
		const char* sos = src;
		while (*src != '\0') {
			if (*src == ch)
				return (int)(src - sos);
			src++;
		}
		return no_pos;
	}

	int my_r_strchr(const char* src, char ch) {
		const char *eos = src + my_strlen(src);
		while (eos != src) {
			if (*eos == ch)
				return (int)(eos - src);
			eos--;
		}
		return (*eos == ch) ? 0 : no_pos;
	}

	int my_strcmp(const char* f_str, const char* s_str) {
		while (*f_str == *s_str && *f_str != '\0') {}
		if (*f_str == '\0')
			return 0;
		return (*(unsigned char*)f_str > *(unsigned char*)s_str ? 1 : -1);
	}

	int my_strncmp(const char* f_str, const char* s_str, size_t len) {
		while (*f_str == *s_str && *f_str != '\0' && len--) {}
		if (*f_str == '\0' || len)
			return 0;
		return (*(unsigned char*)f_str > *(unsigned char*)s_str ? 1 : -1);
	}

	int my_strcmp_case(const char* f_str, const char* s_str) {
		while (my_tolower(*f_str) == my_tolower(*s_str) && *f_str != '\0') {}
		if (*f_str == '\0')
			return 0;
		return (my_tolower(*(unsigned char*)f_str) > my_tolower(*(unsigned char*)s_str) ? 1 : -1);
	}

	int my_strncmp_case(const char* f_str, const char* s_str, size_t len) {
		while (my_tolower(*f_str == my_tolower(*s_str)) && *f_str != '\0' && len--) {}
		if (*f_str == '\0' || len)
			return 0;
		return (my_tolower(*(unsigned char*)f_str) > my_tolower(*(unsigned char*)s_str) ? 1 : -1);
	}
	//KMP's nextArray
	void caculateNext(const char* pat, int next[]) {
		int pat_len = my_strlen(pat);
		next[0] = -1;
		next[1] = 0;
		int k = 0;
		int pat_ptr = 2;
		while (pat_ptr < pat_len) {
			if (pat[pat_ptr - 1] == pat[k]) {
				next[pat_ptr++] = ++k;
			}
			else if (k > 0) {
				k = next[k];
			}
			else {
				next[pat_ptr++] = k;
			}
		}
	}

	int my_strmat(const char* txt, const char* pat) {
		int txt_len = my_strlen(txt);
		int pat_len = my_strlen(pat);
		int *next = new int[pat_len] {};
		caculateNext(pat, next);	//init nextArray
		int txt_ptr = 0;
		int pat_ptr = 0;
		//The point is txt_ptr never back!!
		while (txt_ptr < txt_len && pat_ptr < pat_len) {
			if (pat_ptr == -1 || txt[txt_ptr] == pat[pat_ptr]) {
				txt_ptr++;
				pat_ptr++;
			}
			else {
				pat_ptr = next[pat_ptr];
			}
		}
		delete next;
		if (pat_ptr == pat_len)
			return txt_ptr - pat_ptr;
		else
			return -1;
	}

	double my_strtod(const char* s) {
		double _ret = 0.0;
		int _int = 0;
		double _dec = 0.0;
		int dotPos = my_strchr(s, '.');
		if (dotPos == my_string::no_pos) {
			while (*s != '\0') {
				_int = _int * 10 + (*s - 48);
			}
			return (double)_int;
		}
		else {
		}
	}
