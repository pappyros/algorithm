
#include <stdio.h>
#include <malloc.h>

void kruskal(int n, int *X, int *F[2], int su);
void sort(int *X, int *sortededge[2], int su);

int *weight;

void main()
{


	int i;
	int X[25] =
	{
		0,1,2,0,0,
		1,0,2,3,0,
		2,2,0,6,4,
		0,3,6,0,1,
		0,0,4,1,0,
	};

	int *F[2];
	int su = 7;

	F[0] = (int *)malloc(sizeof(int)*su);
	F[1] = (int *)malloc(sizeof(int)*su);
	// �׷����� ������ �־��� �׷����� ����Ѵ�. ������ ������� ǥ�⸦ �� ����.
	printf("\n                       <Kruskal �˰���>                         \n");
	printf("\n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");
	printf("\n +                                                                 +");
	printf("\n +                         [0]-------2-------[2]                   +");
	printf("\n +                          |              ( /|                    +");
	printf("\n +                          |    ___ 2 ___( / |                    +");
	printf("\n +                          1   (          3  |                    +");
	printf("\n +                          | (           /   |                    +");
	printf("\n +                          |(          /     |                    +");
	printf("\n +                         [1]---3--- [3]     |                    +");
	printf("\n +                                    (       4                    +");
	printf("\n +                                     (      |                    +");
	printf("\n +                                       1    |                    +");
	printf("\n +                                        (   |                    +");
	printf("\n +                                         (  |                    +");
	printf("\n +                                           [4]                   +");
	printf("\n +                                                                 +");
	printf("\n +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	////////////////////////////////////////////////////////////////////////////////////
	kruskal(5, X, F, su);
	printf("\n");
	printf("\t<kruskal's result>\n");

	for (i = 0; i<4; i++)
	{
		printf("\t%d��° ���� \t(V%d , V%d)\n", i + 1, F[0][i], F[1][i]);
	}
}

void kruskal(int n, int *X, int *F[2], int su)
{
	int *sortededge[2];
	int e1, e2;
	int i, j;
	int num_selected = 0;
	int so_flag;                //���μ����� Ȯ���ϴ� flag

	sortededge[0] = (int *)malloc(sizeof(int)*su);
	sortededge[1] = (int *)malloc(sizeof(int)*su);
	sort(X, sortededge, su);
	printf("\n");
	printf("<kruskal�˰����� ���� ����>\n");
	//���� ������ �̹� ���õ� �������� ���տ�
	//�߰��϶� ����Ŭ�� �����ϴ� ���� üũ �ϴ°��Դϴ�.
	printf("\n");
	for (i = 0; i<su; i++)
	{
		e1 = sortededge[0][i];
		e2 = sortededge[1][i];           //���μ����� Ȯ���մϴ�.                                  
		so_flag = 0;                     //�� ���� �����ϴ��� Ȯ���ϴ� �̴ϴ�.
										 //���μ��̸� =1, ���μҰ� �ƴϸ� =0
		for (j = 0; j<num_selected; j++)
		{
			if ((X[e1 * 5 + F[0][j]])>0 && (X[e2 * 5 + F[0][j]]>0))
			{
				so_flag = 1;
				break;
			}

		}

		if (so_flag == 0)
		{
			F[0][num_selected] = e1;
			F[1][num_selected] = e2;
			num_selected++;

			printf("(V%d , V%d)  ����\n", e1, e2);

		}
		if (so_flag == 1)
		{
			F[0][num_selected] = e1;
			F[1][num_selected] = e2;
			num_selected++;

			printf("(V%d ,V%d)�� �̹� �ٸ� ��ο� ���� ����Ǿ� �ִ� �����Դϴ�.\n", e1, e2);
			printf("\t����Ŭ ����->�������� ����\n");
		}

	}
}

void sort(int *X, int *sortededge[2], int su)
{
	int j, k;

	int num = 0;
	int start, end;
	int temp;

	weight = (int *)malloc(sizeof(int)*su);
	//���� ���� ���մϴ�.
	for (j = 0; j<5; j++)
	{
		for (k = j; k<5; k++)
		{
			if (X[j * 5 + k]>0)
			{
				sortededge[0][num] = j;
				sortededge[1][num] = k;
				weight[num] = X[j * 5 + k];
				num++;
			}
		}
	}

	for (j = 0; j<su - 1; j++)
	{
		for (k = 0; k<su - 1; k++)
		{
			if (weight[k]>weight[k + 1])
			{
				temp = weight[k];
				weight[k] = weight[k + 1];
				weight[k + 1] = temp;

				start = sortededge[0][k];
				sortededge[0][k] = sortededge[0][k + 1];
				sortededge[0][k + 1] = start;

				end = sortededge[1][k];

				sortededge[1][k] = sortededge[1][k + 1];
				sortededge[1][k + 1] = end;
			}
		}
	}
	printf("\n");
	printf("��� �������� ����ġ�� ������������ ����\n");
	printf("\t<sorted result>\n");

	for (j = 0; j<su; j++)
	{
		printf("\t(V%d , V%d) ����ġ= %d\n", sortededge[0][j], sortededge[1][j], weight[j]);
	}
	printf("\n");
}






