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
		/* 这里减1是因为字符串从1开始，不相等时说明差异时从i开始
		则开始比较next值的元素
		比如a="ABAB|C"
			   ABAB|D
			     AB|AB next[5]=next[4]+1=3
		求next5时  此时发生差异的地方时C 此时i=4 
		此时next[4]为2 j=2
		因此比较a[1]和a[3],如果相等则next[5]=next[4]+1
		*/
		if (j == 0 || str.ch[i-1] == str.ch[j-1]) {

			next[++i] = ++j;
		}
		else {
			//next[j]为0表示模式串第一个字符与主串i不相等
			j = next[j];
		}
	}
}

//next函数优化版
void getNextAdvance(String str, int next[]) {
	int i = 1, j = 0;
	next[1] = 0;
	while (i < str.length) {
		/* 这里减1是因为字符串从1开始，不相等时说明差异时从i开始
		则开始比较next值的元素
		比如a="ABAB|C"
			   ABAB|D
		         AB|AB next[5]=next[4]+1=3
		求next5时  此时发生差异的地方时C 此时i=4
		此时next[4]为2 j=2
		因此比较a[1]和a[3],如果相等则next[5]=next[4]+1
		i-1是因为当求next[5]时 i应该等于4 因为比的是 a[3]和a[1]
		而此时next[j]=2实际上是字符串1的位置 因此需要j-1
		*/
		if (j == 0 || str.ch[i - 1] == str.ch[j - 1]) {
			++i;
			++j;
			/*			1234567
				对于	ABABAAB
				next值：0112342
				本来next[3]等于1，但是要判断一下3与1是否相等
				即a[2]和next[3]=j (j需要减1，因为字符串从0开始)
				如果相等则next[i]=next[j];
			*/
			if (str.ch[i - 1] == str.ch[j-1]) {
				next[i] = next[j];
			}
			else {
				next[i] = j;
			}
		}
		else {
			//next[j]为0表示模式串第一个字符与主串i不相等
			j = next[j];
		}
	}
}

//kmp算法
int kmp(String str, String subStr, int next[]) {
	int i = 0, j = 0;
	while (i < str.length && j < subStr.length) {
		
		if ( str.ch[i] == subStr.ch[j] ) {
			i++;
			j++;
		}
		else {
			//下一个所比较的位置 +1是因为字符串从0开始 且next[0]时-1，next函数是
			//从next[1]开始 入ab j=0时与主串不相等实际上是要求next[1]的值
			j = next[j+1];
			//如果等于1则字符串第一位与当前i相比
			if (j == 1) {
				j = 0;
			}
			//j等于0，则主串的下一个字符和子串第一个字符相比
			else if (j == 0) {
				i++;
			}
		}
		
	}
	if (j == subStr.length) {
		return i - subStr.length;
	}
	else {
		return -1;
	}
}