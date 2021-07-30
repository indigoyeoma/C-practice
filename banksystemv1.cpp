#include <iostream>

using namespace std;

typedef struct {
	int id;
	char name[30];
	int amo;
}info;

void add(info list[],int num) {
	cout << "[계좌개설]" << endl;
	cout << "계좌 ID: "; cin >> list[num].id;
	cout << "계좌 이름: "; cin >> list[num].name;
	cout << "입금액: "; cin >> list[num].amo;
}

void imp(info list[], int num) {
	int sid;
	int sprice;
	int loc;
	cout << "[입 금]" << endl;
	cout << "계좌 ID: "; cin >> sid;
	for (int i = 0; i < num; i++) {
		if (sid==list[i].id)
			loc = i;
	}
	cout << "입금액: "; cin >> sprice;
	list[loc].amo += sprice;
	cout << "입금완료" << endl;
}

void exp(info list[], int num) {
	int sid;
	int sprice;
	int loc;
	cout << "[출 금]" << endl;
	cout << "계좌 ID: "; cin >> sid;
	for (int i = 0; i < num; i++) {
		if (sid == list[i].id)
			loc = i;
	}
	cout << "출금액: "; cin >> sprice;
	list[loc].amo -= sprice;
	cout << "출금완료" << endl;
}

void showall(info list[], int num) {
	for (int i = 0; i < num; i++) {
		cout << i <<endl;
		cout << "계좌 ID: "<< list[i].id << endl;
		cout << "계좌 이름: "<<list[i].name << endl;
		cout << "입금액: "<<list[i].amo << endl;
	}
}

int main(void) {
	int sel=0;
	info list[101];
	int num = 0;

	while (sel!=5) {
		cout << "------MENU------ " << endl;
		cout << "1. 계좌계설" << endl;
		cout << "2. 입 금" << endl;
		cout << "3. 출 금" << endl;
		cout << "4. 계좌정보 전체 출력" << endl;
		cout << "5. 프로그램 종료" << endl;
		cout << "선택 : "; cin >> sel;
		cout << endl;

		switch (sel) {
		case 1:
			add(list, num);
			num++;
			break;
		case 2:
			imp(list, num);
			break;
		case 3:
			exp(list, num);
			break;
		case 4:
			showall(list,num);
			break;
		case 5:

			break;
		}

	}

	return 0;
}