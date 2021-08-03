#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Account {
private:
	int id;
	char* name;
	int amo;

public:
	Account(int newid, char *newname, int newamo) 
	{
		int len = strlen(newname) + 1;
		name = new char[len];
		id = newid;
		strcpy(name, newname);
		amo = newamo;

	}
	
	int getid() {
		return id;
	}
	
	void impamo(int desamo) {
		this->amo += desamo;
	}

	void expamo(int desamo) {
		this->amo -= desamo;
	}

	void showinfo() {
		{
			cout <<"계좌 ID: " << this->id << endl;
			cout << "계좌 이름: " << this->name << endl;
			cout << "입금액: " << this->amo << endl;
		}
		
	}
	~Account() {
		delete[]name;
	}

};

int main(void) {
	char sname[40];
	int sid;
	int samo;
	Account* arr[100];
	int sel = 0;

	int num = 0;
	int i = 0;
	

	while (sel != 5) {
		
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
			cout << "[계좌 입력]" << endl;
			cout << "ID 입력: ";
			cin >> sid;
			cout << "이름 입력: ";
			cin >> sname;
			cout << "금액 입력: ";
			cin >> samo;
			arr[num] = new Account(sid, sname, samo);
			num++;
			break;

		case 2:
			cout << "[입 금]" << endl;
			cout << "입금하실 ID 입력: ";
			cin >> sid;
			cout << "입금하실 금액 입력: ";
			cin >> samo;
			i = 0;
			while (1) {
				if (sid == arr[i]->getid()) break;
				else i++;
			}
			arr[i]->impamo(samo);
			break;

		case 3:
			cout << "[출 금]" << endl;
			cout << "출금하실 ID 입력: ";
			cin >> sid;
			cout << "출금하실 금액 입력: ";
			cin >> samo;
			i = 0;
			while (1) {
				if (sid == arr[i]->getid()) break;
				else i++;
			}
			arr[i]->expamo(samo);
			break;

			break;

		case 4:
			for (int x = 0; x < num; x++) {
				arr[x]->showinfo();
				cout << endl;
			}
			break;
		case 5:

			break;
		}

	}

	return 0;
}