#include <iostream>
#include "str.h"

//字符串初始化
void init(String &str) {
	str=*(String *)malloc(sizeof(String));
	str.ch = NULL;
	str.length = 0;
	printf("\n字符串初始化成功。。。。。。");
}

//字符串初始化并赋值
String initAndAssignStr(char * ch) {
	void init(String &str);
	String assignStr(String &str, char * ch);
	String str;
	init(str);
	return assignStr(str, ch);
}

//字符串的赋值操作
String assignStr(String &str, char * ch) {
	//初始化
	if (str.ch) {
		free(ch);
	}
	//计算字符串长度
	int length = 0;
	char * c = ch;
	while (*c) {
		length++;
		c++;
	}
	if (length == 0) {
		str.ch = NULL;
		str.length = 0;
		return str;
	}
	else {
		//存放\0
		str.ch=(char *)malloc(sizeof(char)*(length + 1));
		//<=是为了存放结束标志\0
		for (int i = 0; i <= length; i++, ch++) {
			str.ch[i] = *ch;
		}
		str.length = length;
		return str;
	}
}

//取串长度
int length(String str) {
	return str.length;
}

//字符串的比较
int compare(String s1, String s2) {
	for (int i = 0; i < s1.length&&i < s2.length; i++) {
		if (s1.ch[i] != s2.ch[i]) {
			return s1.ch[i] - s2.ch[2];
		}
	}
	return s1.length - s2.length;
}

//字符串连接
int connect(String &s1, String s2, String s3) {
	//初始化
	if (s1.ch) {
		free(s1.ch);
		s1.ch = NULL;
	}
	s1.length = s2.length + s3.length;
	s1.ch = (char *)malloc(sizeof(char)*(s1.length+1));
	int i = 0;
	while (i < s2.length) {
		s1.ch[i] = s2.ch[i];
		i++;
	}
	int j = 0;
	//等于是因为要赋值结束符
	while (j <= s3.length) {
		s1.ch[i + j] = s3.ch[j];
		j++;
	}
	return 1;
}

//字符串的截取
int subString(String &str, String s2, int start, int end) {
	if (str.ch) {
		free(str.ch);
		str.ch = NULL;
	}
	
	if (end > s2.length - 1) {
		end = s2.length - 1;
	}

	str.length = end - start + 1;

	int i = 0;

	str.ch = (char *)malloc(sizeof(char)*(str.length + 1));
	while (i +start <=end) {
		str.ch[i] = s2.ch[i + start];
		i++;
	}
	str.ch[str.length + 1] = '\0';
	return 1;
}

//字符串匹配
int index(String str, String subStr) {
	//记录匹配成功的开始位置
	int k;
	//父串的长度
	int i = 0;
	//子串的长度
	int j = 0;
	k = i;
	while (i < str.length && j<subStr.length) {
		if (str.ch[i] == subStr.ch[j]) {
			i++;
			j++;
			continue;
		}
		else {
			k++;
			i = k;
			j = 0;
		}
	}

	if (j == subStr.length ) {
		return k;
	}
	else {
		return -1;
	}
}

//next数组
void getNext(String str, int next[]) {
	int i = 1,j = 0;
	next[1] = 0;
	while (i < str.length) {
		if (j == 0 || str.ch[i] == str.ch[j]) {
			++i;
			++j;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
}