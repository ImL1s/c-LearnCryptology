#define _CRT_SECURE_NO_WARNINGS
#define CHAR_LENGTH 30
#define GROUP_LENGTH CHAR_LENGTH/2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 柵欄解密
void decode(char* c)
{
	char aGroup[GROUP_LENGTH];
	char bGroup[GROUP_LENGTH];
	char group[CHAR_LENGTH];

	int aGroupIndex = 0;
	int bGroupIndex = 0;

	int charLength = 0;

	// 取得字符串長度
	while (1)
	{
		if (c[charLength] == '\0') break;
		charLength++;
	}

	// 找出a組文字
	for (int i = 0; i < charLength / 2; i++)
	{
		aGroup[aGroupIndex] = c[i];
		aGroupIndex++;
	}

	// 找出b組的文字
	for (int i = charLength / 2; i < charLength; i++)
	{
		bGroup[bGroupIndex] = c[i];
		bGroupIndex ++ ;
	}

	int i = 0,aIndex = 0, bIndex = 0;
	char result[CHAR_LENGTH];
	memset(result, '\0', sizeof(result));
	int end = 1;

	// 解密
	while (end)
	{
		if (!(aIndex >= aGroupIndex))
		{
			result[i++] = aGroup[aIndex++];
		}
		else
		{
			end = 0;
		}
		if (!(bIndex >= bGroupIndex))
		{
			result[i++] = bGroup[bIndex++];
		}
		else
		{
			end = 0;
		}
	}

	printf("%s \n", result);
}

// 柵欄加密
void encrypt(char* c)
{
	char aGroup[GROUP_LENGTH];
	char bGroup[GROUP_LENGTH];

	int aGroupIndex = 0;
	int bGroupIndex = 0;

	for (int i = 0; i < CHAR_LENGTH; i++)
	{
		// 當達到用戶輸入的字符結尾時，退出
		if (c[i] == '\0')
		{
			aGroup[aGroupIndex] = '\0';
			bGroup[bGroupIndex] = '\0';
			break;
		}

		// 將字母們分為兩個一組，這部分為取出第一個字母
		if ((i + 1) % 2 != 0)
		{
			aGroup[aGroupIndex] = c[i];
			aGroupIndex++;
		}
		// 將字母們分為兩個一組，這部分為取出第二個字母
		else
		{
			bGroup[bGroupIndex] = c[i];
			bGroupIndex++;
		}
	}

	char result[CHAR_LENGTH];
	memset(result, '\0', sizeof(result));

	// 複製字符陣列到目的
	strcat(result, aGroup);
	strcat(result, bGroup);

	puts("加密結果: \n");
	printf("%s \n", result);
}


void enterSystem()
{
	puts("********** 歡迎使用柵欄加密系統 ********** \n");
	puts("請問你要加密(0)還是解密(1)? (請輸入 0 或是 1) \n");

	char option[100];
	scanf("%s", &option);

	puts("請輸入要加密/解密的明文:(請勿超過30個字) \n");
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