#ifndef _STR_H_

#define _STR_H_

//字符串的结构体定义
typedef struct {
	char * ch;
	int length;
} String;

//字符串初始化
void init(String &str);

//字符串的赋值操作
String assignStr(String &str, char * ch);

//字符串初始化并赋值
String initAndAssignStr(char * ch);

//取串长度
int length(String str);

//字符串的比较
int compare(String str1, String str2);

//字符串连接
int connect(String &s1, String s2, String s3);

//字符串的截取
int subString(String &str, String s2, int start, int end);

#endif
