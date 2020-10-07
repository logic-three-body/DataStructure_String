#include<iostream>
#include<string>
#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* �洢�ռ��ʼ������ */

typedef int Status;		/* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int ElemType;	/* ElemType���͸���ʵ������������������Ϊint */
int *compute_prefix_function(const char * pattern)
{
	int m = strlen(pattern);
	int *next = new int[m];
	next[0] = 0;
	int k = 0;
	int q;

	for (q = 1; q < m; q++)
	{
		while (k > 0 && (pattern[k] != pattern[q]))
			k = next[k - 1];
		if (pattern[k] == pattern[q])
			k++;
		next[q] = k;
	}
	return next;
}

int * compute_prefix_function(std::string&str)
{
	int m = str.length();
	int *next = new int[m];
	next[0] = 0;
	int k = 0;
	int q;

	for (q = 1; q < m; q++)
	{
		while (k > 0 && (str[k] != str[q]))
			k = next[k - 1];
		if (str[k] == str[q])
			k++;
		next[q] = k;
	}
	return next;
}

int KMP_match(std::string&str,const char *pattern)
{
	int n = str.length();
	int m = strlen(pattern);
	int *next = compute_prefix_function(pattern);
	int q = 0;
	int i;

	for (i = 0; i < n; i++)
	{
		while (q > 0 && (pattern[q] != str[i]))
			q = next[q - 1];
		if (pattern[q] == str[i])
			q++;
		if (q == m)
			return i + 1 - m;
	}
	delete[] next;
	return ERROR;
}

int KMP_match(std::string str, std::string &pattern)
{
	int n = str.length();
	int m = pattern.length();
	int *next = compute_prefix_function(pattern);
	int q = 0;
	int i;

	for (i = 0; i < n; i++)
	{
		while (q > 0 && (pattern[q] != str[i]))
			q = next[q - 1];
		if (pattern[q] == str[i])
			q++;
		if (q == m)
			return i + 1 - m;
	}
	delete[] next;
	return ERROR;
}

int main()
{
	std::string Human, Virus;
	while (true)
	{
		std::cin >> Virus  >> Human;
		if (Human=="0"&&Virus=="0")
		{
			break;
		}
		std::string doctor = Virus +Virus;//��״DNA
		int len = Virus.length();
		int flag = ERROR;//�ж��Ƿ�ƥ��ɹ�
		for (int i = 0; i < len; i++)
		{
			std::string tmp = doctor.substr(i, len);
			flag = KMP_match(Human, tmp);
			if (flag!=ERROR)//�ӻ�״DNA����������ҵ��������
			{
				break;
			}
		}//for
		if (flag != ERROR)
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}