#define _CRT_SECURE_NO_WARNINGS
#define CHAR_LENGTH 100

#include <stdio.h>
#include <stdlib.h>


// 凱薩解密
void decode(char* c)
{
	for (int i = 0; i < CHAR_LENGTH; i++)
	{
		if (c[i] == '\0') break;
		c[i] --;
	}

	puts("解密結果: \n");
	printf("%s \n", c);
}

// 凱薩加密
void encrypt(char* c)
{
	for (int i = 0; i < CHAR_LENGTH; i++)
	{
		if (c[i] == '\0') break;
		c[i] ++;
	}

	puts("加密結果: \n");
	printf("%s \n", c);
}


void enterSystem()
{
	puts("********** 歡迎使用凱薩加密系統 ********** \n");
	puts("請問你要加密(0)還是解密(1)? (請輸入 0 或是 1) \n");

	char option[100];
	scanf("%s", &option);

	puts("請輸入要加密/解密的明文: \n");
	char ch[CHAR_LENGTH];
	int succ = scanf("%s", &ch);

	switch (option[0])
	{
	case '0':
		encrypt(ch);
		break;

	case '1':
		decode(ch);
		break;

	default:
		puts("輸入錯誤... 請重新輸入");
		enterSystem();
		break;
	}
}

int main()
{
	enterSystem();


	system("pause");
}
