#include <iostream>

using namespace std;

typedef struct {
	int id;
	char name[30];
	int amo;
}info;

void add(info list[],int num) {
	cout << "[���°���]" << endl;
	cout << "���� ID: "; cin >> list[num].id;
	cout << "���� �̸�: "; cin >> list[num].name;
	cout << "�Աݾ�: "; cin >> list[num].amo;
}

void imp(info list[], int num) {
	int sid;
	int sprice;
	int loc;
	cout << "[�� ��]" << endl;
	cout << "���� ID: "; cin >> sid;
	for (int i = 0; i < num; i++) {
		if (sid==list[i].id)
			loc = i;
	}
	cout << "�Աݾ�: "; cin >> sprice;
	list[loc].amo += sprice;
	cout << "�ԱݿϷ�" << endl;
}

void exp(info list[], int num) {
	int sid;
	int sprice;
	int loc;
	cout << "[�� ��]" << endl;
	cout << "���� ID: "; cin >> sid;
	for (int i = 0; i < num; i++) {
		if (sid == list[i].id)
			loc = i;
	}
	cout << "��ݾ�: "; cin >> sprice;
	list[loc].amo -= sprice;
	cout << "��ݿϷ�" << endl;
}

void showall(info list[], int num) {
	for (int i = 0; i < num; i++) {
		cout << i <<endl;
		cout << "���� ID: "<< list[i].id << endl;
		cout << "���� �̸�: "<<list[i].name << endl;
		cout << "�Աݾ�: "<<list[i].amo << endl;
	}
}

int main(void) {
	int sel=0;
	info list[101];
	int num = 0;

	while (sel!=5) {
		cout << "------MENU------ " << endl;
		cout << "1. ���°輳" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "���� : "; cin >> sel;
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