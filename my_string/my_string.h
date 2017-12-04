#pragma once

#include <assert.h>
namespace my_string {
#define no_pos -1;	//0xffffffff

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

	int my_strmat(const char* txt, char *pat) {
		int txt_len = my_strlen(txt);
		int pat_len = my_strlen(pat);
		int *next = new int[pat_len];
		my_space::caculateNext(pat, next);	//init nextArray
		int src_ptr = 0;
		int pat_ptr = 0;
		while (src_ptr < txt_len && pat_ptr < pat_len) {
			if (pat_ptr == -1 || txt[src_ptr] == pat[pat_ptr]) {
				src_ptr++;
				pat_ptr++;
			}
			else {
				pat_ptr = next[pat_ptr];
			}
		}
		if (pat_ptr == pat_len)
			return src_ptr - pat_ptr;
		delete next;	//my_space::caculateNext(char *pat) function returns an arrayPtr on heap
	}
}

namespace my_space {
	void* caculateNext(char *pat, int next[]) {
		int pat_len = my_strlen(pat);
		next[0] = -1;

		int k = -1;
		int pat_ptr = 0;
		while (pat_ptr < pat_len - 1) {
			if (k == -1 || next[pat_ptr] == next[k]) {
				k++;
				pat_ptr++;
				next[pat_ptr] = k;
			}
			else {
				k = next[pat_ptr];
			}
		}
	}
}
