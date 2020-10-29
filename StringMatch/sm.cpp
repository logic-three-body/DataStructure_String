#include<iostream>//KMP match Virus vs Human
#include<string>
#define OK 1
#define ERROR -1
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;	/* ElemType类型根据实际情况而定，这里假设为int */
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
		std::string doctor = Virus +Virus;//环状DNA
		int len = Virus.length();
		int flag = ERROR;//判断是否匹配成功
		for (int i = 0; i < len; i++)
		{
			std::string tmp = doctor.substr(i, len);
			flag = KMP_match(Human, tmp);
			if (flag!=ERROR)//从环状DNA多种情况中找到合适情况
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