#include <stdio.h>
#include <math.h>
#include <windows.h>
//������ Ȯ���ϱ�

//i�� a�� �ڸ����� �ø�. math.h �ʿ�
/*
int up(int i, int a){
	int j = (int)pow(10, a);
	return (i + j - 1)/ j* j;
}
*/
//�ٵ� ���⼱ 10�� �ڸ����� �ø��� �͸� ���� ���ϱ�...
int tenup(int i) {
	return (i + 99) / 100 * 100;
}
//���� ���, �� �Ի� ����� 10�� �ڸ����� �ø�.

void printscore(int a) {
	printf("ģ�� ���\n���: %d All,\t �� %d\n", tenup(2 * a), tenup(6 * a));
	printf("���� ���\n���: (%d, %d), �� %d\n", tenup(a), tenup(2 * a), tenup(4 * a));
}


//score=�μ�*2^(�Ǽ�+2)
int getscore(int pan, int bu) {
	return bu * (int)pow(2, pan) * 4;
}



int bpts() {
	unsigned int pan = 0;
	unsigned int bu = 0;
	unsigned int score = 0;

	printf("\n���� ��/�ǡ����� ����.");
	while (1) {
		printf("\n�Ǽ� �Է�(0 �Է½� ����): ");
		scanf_s("%d", &pan);
		if (pan == 0){
			break;
		}
		printf("�μ� �Է�(�ڵ� �ø�): ");
		scanf_s("%d", &bu);

		if (bu < 20) {
			printf("�μ��� �ùٸ��� �ʽ��ϴ�!\n (�ּ� 20�� �̻� �Է��ϼ���)");
			return 0;
		}
		if (bu != 25)
			bu = (bu + 9) / 10 * 10;

		score = getscore(pan, bu);
		printf("\n��� ����: %d\n\n", score);

		if (pan >= 13) {
			printf("��Ƹ� ����(ī���� ����)\n");
			printscore(8000);
		}
		else if (pan >= 11) {
			printf("��踸\n");
			printscore(6000);
		}
		else if (pan >= 8) {
			printf("�踸\n");
			printscore(4000);
		}
		else if (pan >= 6) {
			printf("�ϳ׸�\n");
			printscore(3000);
		}
		else if (pan >= 5 || score >= 2000) {
			printf("����\n");
			printscore(2000);
		}
		else if (score >= 0)
			printscore(score);
		else {
			printf("�������� ���� ���� �ԷµǾ����ϴ�. ���α׷��� �����մϴ�.");
			return 1;
		}
		
	}
	return 0;
}

void ronscore(int pan, int bu, int ron) {
	printf("%d�� %d�� �̻� ��. %d��.\n", pan, bu, ron);
}

void chintsumoscore(int pan, int bu, int tsumo) {
	printf("%d�� %d�� �̻� ���. %d��.\n", pan, bu, tsumo);
}

void jatsumoscore(int pan, int bu, int jtsumo, int ctsumo, int tsumo) {
	printf("%d�� %d�� �̻� ���(%d, %d). �� %d��.\n", pan, bu, jtsumo, ctsumo, tsumo);
}

int stbp() {
	int wscore = 0;
	int pan = 0;
	int bu = 0;
	int tsumo = 0;
	int ctsumo = 0;
	int jtsumo = 0;
	int ron = 0;
	int menu = 0;

	

	while (1) {
		printf("\n������ �Է��ϼ���(0 �Է½� ����): ");
		scanf_s("%d", &wscore);
		if (wscore == 0)
			break;
		//�Ǻ� �ּ� �μ� ǥ��
		printf("ģ�� ���\n");
		if (wscore > 48000 * 6)
			printf("�ʹ� ���� ���� �ԷµǾ����ϴ�.\n");
		else if (wscore > 48000 * 5)
			printf("6�迪�� ȭ��\n");
		else if (wscore > 48000 * 4)
			printf("5�迪�� ȭ��\n");
		else if (wscore > 48000 * 3)
			printf("4�迪�� ȭ��\n");
		else if (wscore > 48000 * 2)
			printf("3�迪�� ȭ��\n");
		else if (wscore > 48000)
			printf("2�迪�� ȭ��\n");
		else if (wscore > 36000)
			printf("���� ȭ��\n");
		else if (wscore > 24000)
			printf("��踸 ȭ��\n");
		else if (wscore > 18000)
			printf("�踸 ȭ��\n");
		else if (wscore > 12000)
			printf("�ϳ׸� ȭ��\n");
		else if (wscore > 11700)
			printf("���� ȭ��\n");
		else {
			//1�� 20�� ���� ���ʴ�� ���
			pan = 1;
			for (bu = 30; bu <= 100; bu += 10) {
				tsumo = tenup(getscore(pan, bu) * 2) * 3;
				if (tsumo >= wscore) {
					chintsumoscore(pan, bu, tsumo);
					break;
				}
			}
			for (bu = 20; bu <= 110; bu += 10) {
				ron = tenup(getscore(pan, bu) * 6);
				if (ron >= wscore) {
					ronscore(pan, bu, ron);
					break;
				}
			}

			pan = 2;
			for (bu = 20; bu <= 110; bu += 10) {
				tsumo = tenup(getscore(pan, bu) * 2) * 3;
				if (tsumo >= wscore) {
					chintsumoscore(pan, bu, tsumo);
					break;
				}
			}
			for (bu = 20; bu <= 110; bu += 10) {
				ron = tenup(getscore(pan, bu) * 6);
				if (ron >= wscore) {
					ronscore(pan, bu, ron);
					break;
				}

				if (bu == 20)
					ron = tenup(getscore(pan, 25) * 6);
				if (ron >= wscore) {
					ronscore(pan, bu, ron);
					break;
				}
			}

			pan = 3;
			for (bu = 20; bu <= 60; bu += 10) {
				tsumo = tenup(getscore(pan, bu) * 2) * 3;
				if (tsumo >= wscore) {
					chintsumoscore(pan, bu, tsumo);
					break;
				}
				if (bu == 20)
					tsumo = tenup(getscore(pan, 25) * 2) * 3;
				if (tsumo >= wscore) {
					chintsumoscore(pan, bu, tsumo);
					break;
				}
			}
			for (bu = 20; bu <= 60; bu += 10) {
				ron = tenup(getscore(pan, bu) * 6);
				if (ron >= wscore) {
					ronscore(pan, bu, ron);
					break;
				}

				if (bu == 20)
					ron = tenup(getscore(pan, 25) * 6);
				if (ron >= wscore) {
					ronscore(pan, bu, ron);
					break;
				}
			}

			pan = 4;
			for (bu = 20; bu <= 30; bu += 5) {
				tsumo = tenup(getscore(pan, bu) * 2) * 3;
				if (tsumo >= wscore) {
					chintsumoscore(pan, bu, tsumo);
					break;
				}
			}
			for (bu = 20; bu <= 30; bu += 5) {
				ron = tenup(getscore(pan, bu) * 6);
				if (ron >= wscore) {
					ronscore(pan, bu, ron);
					break;
				}
			}



		}
		printf("���� ���\n");
		if (wscore > 32000 * 6)
			printf("�ʹ� ���� ���� �ԷµǾ����ϴ�.\n");
		else if (wscore > 32000 * 5)
			printf("6�迪�� ȭ��\n");
		else if (wscore > 32000 * 4)
			printf("5�迪�� ȭ��\n");
		else if (wscore > 32000 * 3)
			printf("4�迪�� ȭ��\n");
		else if (wscore > 32000 * 2)
			printf("3�迪�� ȭ��\n");
		else if (wscore > 32000)
			printf("2�迪�� ȭ��\n");
		else if (wscore > 24000)
			printf("���� ȭ��\n");
		else if (wscore > 16000)
			printf("��踸 ȭ��\n");
		else if (wscore > 12000)
			printf("�踸 ȭ��\n");
		else if (wscore > 8000)
			printf("�ϳ׸� ȭ��\n");
		else if (wscore > 7900)
			printf("���� ȭ��\n");
		else {
			//1�� 20�� ���� ���ʴ�� ���

			pan = 1;
			for (bu = 30; bu <= 100; bu += 10) {
				ctsumo = tenup(getscore(pan, bu) * 2);
				jtsumo = tenup(getscore(pan, bu));
				tsumo = ctsumo + jtsumo * 2;
				if (tsumo >= wscore) {
					jatsumoscore( pan, bu, jtsumo, ctsumo, tsumo);
					break;
				}
			}
			for (bu = 20; bu <= 110; bu += 10) {
				ron = tenup(getscore(pan, bu) * 4);
				if (ron >= wscore) {
					ronscore(pan, bu, ron);
					break;
				}
			}

			pan = 2;
			for (bu = 20; bu <= 110; bu += 10) {
				ctsumo = tenup(getscore(pan, bu) * 2);
				jtsumo = tenup(getscore(pan, bu));
				tsumo = ctsumo + jtsumo * 2;
				if (tsumo >= wscore) {
					jatsumoscore( pan, bu, jtsumo, ctsumo, tsumo);
					break;
				}
			}
			for (bu = 20; bu <= 110; bu += 10) {
				ron = tenup(getscore(pan, bu) * 4);
				if (ron >= wscore) {
					ronscore(pan, bu, ron);
					break;
				}

				if (bu == 20)
					ron = tenup(getscore(pan, 25) * 4);
				if (ron >= wscore) {
					ronscore(pan, bu, ron);
					break;
				}
			}

			pan = 3;
			for (bu = 20; bu <= 60; bu += 10) {
				ctsumo = tenup(getscore(pan, bu) * 2);
				jtsumo = tenup(getscore(pan, bu));
				tsumo = ctsumo + jtsumo * 2;
				if (tsumo >= wscore) {
					jatsumoscore( pan, bu, jtsumo, ctsumo, tsumo);
					break;
				}
				if (bu == 20) {
					ctsumo = tenup(getscore(pan, 25) * 2);
					jtsumo = tenup(getscore(pan, 25));
					tsumo = ctsumo + jtsumo * 2;
					if (tsumo >= wscore) {
						jatsumoscore( pan, bu, jtsumo, ctsumo, tsumo);
						break;
					}
				}
			}
			for (bu = 20; bu <= 60; bu += 10) {
				ron = tenup(getscore(pan, bu) * 4);
				if (ron >= wscore) {
					ronscore(pan, bu, ron);
					break;
				}

				if (bu == 20)
					ron = tenup(getscore(pan, 25) * 4);
				if (ron >= wscore) {
					ronscore(pan, bu, ron);
					break;
				}
			}
			pan = 4;
			for (bu = 20; bu <= 30; bu += 5) {
				ctsumo = tenup(getscore(pan, bu) * 2);
				jtsumo = tenup(getscore(pan, bu));
				tsumo = ctsumo + jtsumo * 2;
				if (tsumo >= wscore) {
					jatsumoscore( pan, bu, jtsumo, ctsumo, tsumo);
					break;
				}
			}
			for (bu = 20; bu <= 30; bu += 5) {
				ron = tenup(getscore(pan, bu) * 4);
				if (ron >= wscore) {
					ronscore(pan, bu, ron);
					break;
				}
			}



		}
	}

	return 0;
}

int tofirst() {
	int score = 0;
	printf("1����� ���� ���̸� �Է��Ͻÿ�: ");
	scanf_s("%d", &score);
	int isjin = 0;
	printf("���� 1��� ������ ������ 1 �Է�, �ƴ϶�� 0 �Է�\n");
	scanf_s("%d", &isjin);
	if (isjin == 0)
		score += 100;
	printf("�� ȭ�� ��\nŸ���� ��� 1������ ���� : %d�� �̻�\n1���� ��� 1������ ���� : %d�� �̻�\n\n", tenup(score), tenup(score / 2));
	printf("��� ȭ�� ��\n���� ģ�� �� : %d�� �̻�\n1���� ģ�� �� : %d�� �̻�\n1���� ģ�� �ƴ� �� : %d�� �̻�\n", tenup(score*3/4), tenup(score*2/3), tenup(score*4/5));
	system("PAUSE");
}
int main() {
	int menu = 0;
	while (1) {
		printf("���� ���� ���� (Made By Pangu)\n1. ��/�ǡ����� ����\n2. �������/�� ����\n3. 1��� �������\n4. ���α׷� ����\n���Ͻô� �޴��� �������ּ��� : ");
		scanf_s("%d", &menu);
		if (menu == 1) {
			menu = 0;
			bpts();
		}
			
		else if (menu == 2) {
			menu = 0;
			stbp();
		}
		else if (menu == 3) {
			menu = 0;
			tofirst();
		}
		else {
			printf("���α׷��� �����մϴ�.");
			break;
		}
		system("cls");
	}
	
}