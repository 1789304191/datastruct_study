#ifndef _STR_H_

#define _STR_H_

//�ַ����Ľṹ�嶨��
typedef struct {
	char * ch;
	int length;
} String;

//�ַ�����ʼ��
void init(String &str);

//�ַ����ĸ�ֵ����
String assignStr(String &str, char * ch);

//�ַ�����ʼ������ֵ
String initAndAssignStr(char * ch);

//ȡ������
int length(String str);

//�ַ����ıȽ�
int compare(String str1, String str2);

//�ַ�������
int connect(String &s1, String s2, String s3);

//�ַ����Ľ�ȡ
int subString(String &str, String s2, int start, int end);

#endif
