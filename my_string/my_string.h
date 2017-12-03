#pragma once

#include <assert.h>
namespace my_string {
	#define no_pos -1;	//0xffffffff

	//can deal with overlapMemory 
	char* my_memcpy(char* des, const char* src,size_t len) {
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
		my_memcpy(des,src,len);
		return des;
	}
	
	char* my_strcat(char* des, const char* src) {
		char* ret = des;
		while (*des != '\0') {
			des++;
		}
		my_memcpy(des,src,my_strlen(src));
		return ret;
	}
	
	char* my_strncat(char* des, const char* src, size_t len) {
		char* ret = des;
		while (*des != '\0') {
			des++;
		}
		my_memcpy(des,src,len);
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
	
	int my_strmat(const char* src, char *str) {
		int N = my_strlen(src);
		int M = my_strlen(str);
		int *next = new int[M] {0};
		for (int p = 1,q = 0; p < M; p++) {
			while (q > 0 && str[p] != str[q]) {
				q = next[q-1];
			}
			if (str[p] == str[q])
				q++;
			next[p] = q;
		}
		int i = 0;
		int j = 0;
		while (j > 0 && src[i] != str[j]) {

		}
		delete next;
		if (j == M)
			return i - j;
		else
			return no_pos;
	}
}
