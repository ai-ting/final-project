#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void range();
void norange();

int main(void)
{
	int mode = 0;
	do {
		printf("歡迎來到猜數字遊戲!\n請選擇遊戲模式(1是5次內猜出來，2是猜中為止):");
		scanf("%d", &mode);
		switch (mode)
		{
		case 1:
			range();
			break;
		case 2:
			norange();
			break;
		}
	} while (mode != 1 || mode != 2);
}
void range()
{
	char ans[5] = "", guess[5] = "";
	int i, j, a, b, times = 5;
	srand(time(NULL));
	printf("請輸入四位數字:");
	for (i = 0; i < 4 && (ans[i] = rand() % 10 + 48); i++)
	{
		for (j = 0; j < i; j++)
		{
			ans[j] == ans[i] && i--; //把目前的電腦數字全部檢查，若相同且i不是0則i減1重新產生

		}
	}
	do {
		a = b = i = scanf("%4s", guess) & 0;
		fflush(stdin);
		for (i = 0; i<4; i++)
			for (j = 0; j < 4; j++)
			{
				guess[i] == ans[j] && (i == j ? a++ : b++);
			}
		if (a != 4 && times != 0)
		{
			--times;
			printf("結果：%dA%dB，還有%d次機會...\n", a, b, times);

		}
	} while (a != 4 && times != 0);

	if (a == 4)
	{
		printf("猜對了!答案是%d\n", ans);
	}
	else
	{
		printf("失敗，猜超過5次，答案是%s\n", ans);
	}
	system("pause");
	return 0;
}
void norange()
{
	char ans[5] = "", guess[5] = "";
	int count = 0;
	int i, j, a, b;
	srand(time(NULL));
	printf("請輸入四位數字:");
	for (i = 0; i < 4 && (ans[i] = rand() % 10 + 48); i++)
	{
		for (j = 0; j < i; j++)
		{
			ans[j] == ans[i] && i--;
		}
	}

	do {

		a = b = i = scanf("%4s", guess) & 0;
		fflush(stdin);
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				guess[i] == ans[j] && (i == j ? a++ : b++);
			}
		}

		printf("結果：%dA%dB \n", a, b);
		count++;

	} while (a != 4);

	if (a == 4)
	{
		printf("猜對了!總共猜了%d次 \n", count);
	}

	system("pause");
	return 0;
}

