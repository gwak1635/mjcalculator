#include <stdio.h>
#include <math.h>
#include <windows.h>
//역전각 확인하기

//i를 a의 자리에서 올림. math.h 필요
/*
int up(int i, int a){
	int j = (int)pow(10, a);
	return (i + j - 1)/ j* j;
}
*/
//근데 여기선 10의 자리에서 올리는 것만 자주 쓰니까...
int tenup(int i) {
	return (i + 99) / 100 * 100;
}
//점수 출력, 각 게산 결과를 10의 자리에서 올림.

void printscore(int a) {
	printf("친의 경우\n쯔모: %d All,\t 론 %d\n", tenup(2 * a), tenup(6 * a));
	printf("자의 경우\n쯔모: (%d, %d), 론 %d\n", tenup(a), tenup(2 * a), tenup(4 * a));
}


//score=부수*2^(판수+2)
int getscore(int pan, int bu) {
	return bu * (int)pow(2, pan) * 4;
}



int bpts() {
	unsigned int pan = 0;
	unsigned int bu = 0;
	unsigned int score = 0;

	printf("\n마작 부/판→점수 계산기.");
	while (1) {
		printf("\n판수 입력(0 입력시 종료): ");
		scanf_s("%d", &pan);
		if (pan == 0){
			break;
		}
		printf("부수 입력(자동 올림): ");
		scanf_s("%d", &bu);

		if (bu < 20) {
			printf("부수가 올바르지 않습니다!\n (최소 20부 이상 입력하세요)");
			return 0;
		}
		if (bu != 25)
			bu = (bu + 9) / 10 * 10;

		score = getscore(pan, bu);
		printf("\n기반 점수: %d\n\n", score);

		if (pan >= 13) {
			printf("헤아림 역만(카조에 역만)\n");
			printscore(8000);
		}
		else if (pan >= 11) {
			printf("삼배만\n");
			printscore(6000);
		}
		else if (pan >= 8) {
			printf("배만\n");
			printscore(4000);
		}
		else if (pan >= 6) {
			printf("하네만\n");
			printscore(3000);
		}
		else if (pan >= 5 || score >= 2000) {
			printf("만관\n");
			printscore(2000);
		}
		else if (score >= 0)
			printscore(score);
		else {
			printf("예상하지 못한 값이 입력되었습니다. 프로그램을 종료합니다.");
			return 1;
		}
		
	}
	return 0;
}

void ronscore(int pan, int bu, int ron) {
	printf("%d판 %d부 이상 론. %d점.\n", pan, bu, ron);
}

void chintsumoscore(int pan, int bu, int tsumo) {
	printf("%d판 %d부 이상 쯔모. %d점.\n", pan, bu, tsumo);
}

void jatsumoscore(int pan, int bu, int jtsumo, int ctsumo, int tsumo) {
	printf("%d판 %d부 이상 쯔모(%d, %d). 총 %d점.\n", pan, bu, jtsumo, ctsumo, tsumo);
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
		printf("\n점수를 입력하세요(0 입력시 종료): ");
		scanf_s("%d", &wscore);
		if (wscore == 0)
			break;
		//판별 최소 부수 표기
		printf("친의 경우\n");
		if (wscore > 48000 * 6)
			printf("너무 높은 값이 입력되었습니다.\n");
		else if (wscore > 48000 * 5)
			printf("6배역만 화료\n");
		else if (wscore > 48000 * 4)
			printf("5배역만 화료\n");
		else if (wscore > 48000 * 3)
			printf("4배역만 화료\n");
		else if (wscore > 48000 * 2)
			printf("3배역만 화료\n");
		else if (wscore > 48000)
			printf("2배역만 화료\n");
		else if (wscore > 36000)
			printf("역만 화료\n");
		else if (wscore > 24000)
			printf("삼배만 화료\n");
		else if (wscore > 18000)
			printf("배만 화료\n");
		else if (wscore > 12000)
			printf("하네만 화료\n");
		else if (wscore > 11700)
			printf("만관 화료\n");
		else {
			//1판 20부 부터 차례대로 계산
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
		printf("자의 경우\n");
		if (wscore > 32000 * 6)
			printf("너무 높은 값이 입력되었습니다.\n");
		else if (wscore > 32000 * 5)
			printf("6배역만 화료\n");
		else if (wscore > 32000 * 4)
			printf("5배역만 화료\n");
		else if (wscore > 32000 * 3)
			printf("4배역만 화료\n");
		else if (wscore > 32000 * 2)
			printf("3배역만 화료\n");
		else if (wscore > 32000)
			printf("2배역만 화료\n");
		else if (wscore > 24000)
			printf("역만 화료\n");
		else if (wscore > 16000)
			printf("삼배만 화료\n");
		else if (wscore > 12000)
			printf("배만 화료\n");
		else if (wscore > 8000)
			printf("하네만 화료\n");
		else if (wscore > 7900)
			printf("만관 화료\n");
		else {
			//1판 20부 부터 차례대로 계산

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
	printf("1등과의 점수 차이를 입력하시오: ");
	scanf_s("%d", &score);
	int isjin = 0;
	printf("내가 1등보다 진동에 가까우면 1 입력, 아니라면 0 입력\n");
	scanf_s("%d", &isjin);
	if (isjin == 0)
		score += 100;
	printf("론 화료 시\n타가를 쏘아 1등으로 역전 : %d점 이상\n1등을 쏘아 1등으로 역전 : %d점 이상\n\n", tenup(score), tenup(score / 2));
	printf("쯔모 화료 시\n내가 친일 때 : %d점 이상\n1등이 친일 때 : %d점 이상\n1등이 친이 아닐 때 : %d점 이상\n", tenup(score*3/4), tenup(score*2/3), tenup(score*4/5));
	system("PAUSE");
}
int main() {
	int menu = 0;
	while (1) {
		printf("마작 점수 계산기 (Made By Pangu)\n1. 부/판→점수 계산기\n2. 점수→부/판 계산기\n3. 1등역전 점수계산\n4. 프로그램 종료\n원하시는 메뉴를 선택해주세요 : ");
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
			printf("프로그램을 종료합니다.");
			break;
		}
		system("cls");
	}
	
}