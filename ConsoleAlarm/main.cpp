#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>
#include <fstream>
#include <string.h>
#include <string>
#include <ctime>
#include <stdlib.h>
#pragma comment(lib,"winmm.lib")
/*
�������е�û����д��
�кܶ�ط���д�Ĳ��Ǻܺ�
��Ӣ��д����װX
by Reiz
VERSION:1.0
*/
using namespace std;
const char _space = ' ';
string filename;//������ļ���
string mpath;//��ʾ��·��
int timeh;//ʱ
int timem;//��
string atype;//��������
string msg1;//��ת������ʾ��Ϣ
wchar_t* msg2;//������ʾ


void hideCur()//���ع��
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void showCur()//��ʾ���
{
	HANDLE h_GAME = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor_info;
	GetConsoleCursorInfo(h_GAME, &cursor_info);
	cursor_info.bVisible = true;
	SetConsoleCursorInfo(h_GAME, &cursor_info);
}

void HomePage();
void CreateAlarm();
void DelAlarm();
void StartA();
void UseAlarm();
void SelectAlarm();
void SaveAlarm();
void selmenuref();

wchar_t* mwstr;//bgm·��ת��wchar_t*�����
int main()
{
	system("color f");
	system("title Console Alarm 1.0 by Reiz");
	hideCur();
	printf("\n\n\n               Console Alarm\n                Starting...");
	Sleep(1000);
	HomePage();
	return 0;
}

void HomePage()//��ҳ
{
	hideCur();
	UseAlarm();
	//atp = atype.c_str();
	const char* mp1 = mpath.c_str();
	char* mp2 = const_cast <char*>(mp1);
	size_t len = strlen(mp2) + 1;
	size_t converted = 0;
	mwstr = (wchar_t*)malloc(len * sizeof(wchar_t));//����string=> const char*=> char*=>wchar_t*��
	mbstowcs_s(&converted, mwstr, len, mp2, _TRUNCATE);

	const char* temp = msg1.c_str();
	char* temp1 = const_cast <char*>(temp);
	size_t len1 = strlen(temp1) + 1;
	size_t converted1 = 0;
	msg2 = (wchar_t*)malloc(len * sizeof(wchar_t));
	mbstowcs_s(&converted1, msg2, len1, temp1, _TRUNCATE);

	system("cls");
	system("color a");
	char ch;//���µļ�
	printf("\n\n%35cWelcome to use the Console Alarm\n",_space);
	printf("%35cWhat are You going to do?\n",_space);
	//system("pause");
	printf("\n%35c[C] Create Alarm\n",_space);
	printf("\n%35c[U] Select Alarm\n", _space);
	printf("\n%35c[D] Delete Alarm\n",_space);
	printf("\n%35c[E] Exit\n",_space);
	while (1)
	{
		ch = getch();//�ж�����
		if (ch == 'c')
		{
			printf("Create a Alarm\n");
			CreateAlarm();
		}
		else if (ch == 'u')
		{
			printf("Select Alarm\n");
			SelectAlarm();
			
		}
		else if (ch == 'd')
		{
			printf("Delete Alarm\n");
			DelAlarm();
		}
		else if (ch == 'e')
		{
			printf("Exit\n");
			exit(0);
		}
	}
}

void CreateAlarm()//��������
{
	char chh;
	int IsLoop = 1;
	hideCur();
	system("cls");
	printf("\n\n%35cCreate a Alarm\n\n",_space);
	printf("%35c[M] Set BGM\n",_space);
	printf("%35c[T] Set Time\n",_space);
	printf("%35c[S] Set Type\n",_space);
	printf("%35c[E] Set a Message\n",_space);
	printf("%35c[O] Save Settings\n",_space);
	printf("%35c[B] Back\n",_space);
	while (IsLoop)
	{
		chh = getch();
		if (chh == 'm')//���ӵ�BGM
		{
			IsLoop = 0;
			system("cls");
			//char path[100];
			showCur();
			printf("Please Type Your WAV music path here(type 'back' can back)\nlike this ��d:\\\\\sth2.wav��\nType the path:");
			
			cin >> mpath;
			if (mpath == "")
			{
				system("color r");
				printf("type error!");
				CreateAlarm();
			}
			else
			{
				if (mpath == "back")
				{
					CreateAlarm();
				}
				else
				{
					//fs << mpath << endl;
					//fs.close();
					printf("Set up successfully!");
					Sleep(1000);
					hideCur();
					CreateAlarm();
				}
				
			}
			
			
			
		}
		else if (chh == 't')//��������ʱ��
		{
			IsLoop = 0;
			system("cls");
			showCur();

			printf("Please Set Time(within Today)\n");
			printf("Hour:");
			cin >> timeh;
			printf("Minutes:");
			cin >> timem;
			printf("Set up Successfully!\nAlarm in %d:%d Today\n",timeh,timem);
			Sleep(1000);
			CreateAlarm();
		}
		else if (chh == 's')//������������
		{
			IsLoop = 0;
			showCur();
			system("cls");
			printf("Please Set Type:\n\no.Only play once\nl.Loop\nb.Back\n\nPlease Type:");
			cin >> atype;
			if (atype == "b")
			{
				printf("Back...\n");
				Sleep(1000);
				CreateAlarm();
			}
			else
			{
				printf("Set UP SUCCESSFULLY!\n");
				Sleep(1000);
				CreateAlarm();
			}
			
		}
		else if (chh == 'o')//����
		{
			IsLoop = 0;
			SaveAlarm();
			system("cls");
			printf("Save Alarm Successfully!\n");
			Sleep(1000);
			HomePage();
		}
		else if (chh == 'e')//������ʾ��Ϣ
		{
			showCur();
			system("cls");
			printf("Please Type Your Alarm Message:\n>");
			cin >> msg1;
			if (msg1 != "")
			{
				//fs << msg1 << endl;
				//fs.close();
				printf("Set up Successfully!!!\n");
			}
			Sleep(1000);
			CreateAlarm();

		}
		else if (chh == 'b')//������ҳ
		{
			IsLoop = 0;
			HomePage();
		}
	//=====================================
	}
}

void DelAlarm()//ɾ��
{
	char ch;
	system("cls");
	printf("Are you sure you want to delete it\n      Y.yes      N.No\n");
	while (1)
	{
		ch = getch();
		if (ch == 'y')
		{
			system("cls");
			system("color f");
			remove("1.txt");
			printf("Deleted The Alarm!!!\n");
			Sleep(1000);
			HomePage();
		}
		else if (ch == 'n')
		{
			system("cls");
			printf("Back Home Page...\n");
			Sleep(1000);
			HomePage();
		}
	}
}

void SelectAlarm()//ѡ�����ӵĲ˵�
{
	char ch;
	system("cls");
	printf("\n\n%35cPlease Select a Alarm to use\n",_space);
	printf("%35c[1] First Alarm\n",_space);
	
	while (1)
	{
		ch = getch();
		if (ch == '1')
		{
			fstream fs;
			fs.open("1.txt",ios::in);
			if (fs.fail())
			{
				printf("Read File Error!\n");
				Sleep(1000);
				HomePage();
			}
			
			
			UseAlarm();
			showCur();
			system("cls");
			printf("Alarm Type:%s\n",atype.c_str());
			printf("Background Music:%s\n",mpath.c_str());
			printf("Alarm Message:%s\n",msg1.c_str());
			printf("Alarm Time: %d:%d Today\n",timeh,timem);
			printf("\n...................................\n");
			printf("1.Use the Alarm       2.Back   3.play BGM 4.Stop BGM\n\n");
			selmenuref();
			
		}
	}
}

void UseAlarm()//��ȡ����
{
	fstream fs;
	fs.open("1.txt", ios::in);//��1
	if (fs.fail())
	{
		ofstream txt("1.txt");
		UseAlarm();
	}
	string th;
	string tm;
	getline(fs, mpath);//��ȡ�ļ� music path line:1
	getline(fs, atype);// alarm type���Ӹ�ʽ  line:2
	getline(fs,th = to_string (timeh));//ʱ�� hour  line:3
	getline(fs,tm = to_string(timem));// ʱ�� minutes  line:4
	timeh = atoi(th.c_str());//string ת char*��ת��int  
	timem = atoi(tm.c_str());
	
	fs.close();
}

void StartA()//��ʼ�������ӵ�BGM�͵�������
{
	time_t t;  //��ʱ��
	tm* local; //����ʱ��
	char buf[128] = { 0 };
	t = time(NULL); //��ȡĿǰ��ʱ��
	local = localtime(&t); //תΪ����ʱ��
	strftime(buf, 64, "%Y-%m-%d %H:%M:%S", local);

	system("cls&&color a");
	printf("Start Time:"); cout << buf << "\n";
	printf("Please Wait Alarm Time: %d:%d\n",timeh,timem);
	//fstream fs;
	//fs.open("1.txt",ios::in);

	while (1)
	{
		tm tm_;
		time_t nowt;
		time(&nowt);
		localtime_s(&tm_,&nowt);
		if (tm_.tm_hour == timeh)
		{
			if (tm_.tm_min == timem)
			{
				if (atype.c_str() == "o")
				{
					PlaySound(mwstr, NULL, SND_FILENAME | SND_ASYNC);
				}
				if (atype.c_str() == "l")
				{
					PlaySound(mwstr, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				}
				if (atype.c_str() != "o" && atype.c_str() != "l")
				{
					PlaySound(mwstr, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
				}
				MessageBox(NULL, msg2, L"Alarm", MB_ICONWARNING);
				MessageBox(NULL, msg2, L"Alarm", MB_ICONWARNING);
				MessageBox(NULL, msg2, L"Alarm", MB_ICONWARNING);
				MessageBox(NULL, msg2, L"Alarm", MB_ICONINFORMATION);
				Sleep(1000);
				system("pause");
				PlaySound(NULL,NULL,SND_FILENAME);
				HomePage();
				
			}
		}
	}
}

void SaveAlarm()//��������
{
	fstream fst;
	fst.open("1.txt",ios::out);
	hideCur();
	system("cls");
	if (!fst)
	{
		printf("�ļ���ʧ�ܣ�\n");
	}
	else
	{
		//line:1 mpath��������
		fst << mpath << endl;
		//line:2 atype
		fst << atype << endl;
		//line:3,4 time hour and minutes
		fst << timeh << endl << timem << endl;
		printf("Save alarm Successfully!!!\n");
	}
	fst.close();

}

void selmenuref()//ѡ������ѡ���ж�
{
	showCur();
	int input = 1;
	while (input)
	{
		printf("\n>");
		scanf("%d",&input);
		switch (input)
		{
		case 1:
			//PlaySound(NULL, NULL, SND_FILENAME);
			StartA();
			
			break;
		case 2:
			//PlaySound(NULL, NULL, SND_FILENAME);
			HomePage();
			break;
		case 3:
			PlaySound(mwstr, NULL, SND_FILENAME | SND_ASYNC);
			break;
		case 4:
			PlaySound(NULL, NULL, SND_FILENAME);
			break;
		default:
			printf("Type ERROR!\n");
		}
	}
}