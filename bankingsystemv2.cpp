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
			cout <<"���� ID: " << this->id << endl;
			cout << "���� �̸�: " << this->name << endl;
			cout << "�Աݾ�: " << this->amo << endl;
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
		cout << "1. ���°輳" << endl;
		cout << "2. �� ��" << endl;
		cout << "3. �� ��" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		cout << "���� : "; cin >> sel;
		cout << endl;

		switch (sel) {
		case 1:
			cout << "[���� �Է�]" << endl;
			cout << "ID �Է�: ";
			cin >> sid;
			cout << "�̸� �Է�: ";
			cin >> sname;
			cout << "�ݾ� �Է�: ";
			cin >> samo;
			arr[num] = new Account(sid, sname, samo);
			num++;
			break;

		case 2:
			cout << "[�� ��]" << endl;
			cout << "�Ա��Ͻ� ID �Է�: ";
			cin >> sid;
			cout << "�Ա��Ͻ� �ݾ� �Է�: ";
			cin >> samo;
			i = 0;
			while (1) {
				if (sid == arr[i]->getid()) break;
				else i++;
			}
			arr[i]->impamo(samo);
			break;

		case 3:
			cout << "[�� ��]" << endl;
			cout << "����Ͻ� ID �Է�: ";
			cin >> sid;
			cout << "����Ͻ� �ݾ� �Է�: ";
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