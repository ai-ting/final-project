#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void range();
void norange();

int main(void)
{
	int mode = 0;
	do {
		printf("�w��Ө�q�Ʀr�C��!\n�п�ܹC���Ҧ�(1�O5�����q�X�ӡA2�O�q������):");
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
	printf("�п�J�|��Ʀr:");
	for (i = 0; i < 4 && (ans[i] = rand() % 10 + 48); i++)
	{
		for (j = 0; j < i; j++)
		{
			if (ans[j]==ans[i])
			{
				i--;
			}//��ثe���q���Ʀr�����ˬd�A�Y�ۦP�Bi���O0�hi��1���s����

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
			printf("���G�G%dA%dB�A�٦�%d�����|...\n", a, b, times);

		}
	} while (a != 4 && times != 0);

	if (a == 4)
	{
		printf("����F!");
	}
	else
	{
		printf("���ѡA�q�W�L5���A���׬O%s\n", ans);
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
	printf("�п�J�|��Ʀr:");
	for (i = 0; i < 4 && (ans[i] = rand() % 10 + 48); i++)
	{
		for (j = 0; j < i; j++)
		{
			if (ans[j] == ans[i])
			{
				i--;
			}
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

		printf("���G�G%dA%dB \n", a, b);
		count++;

	} while (a != 4);

	if (a == 4)
	{
		printf("�q��F!�`�@�q�F%d�� \n", count);
	}

	system("pause");
	return 0;
}

