#include<iostream>
#include<string>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<fstream>
#include<graphics.h>
#include<conio.h>
#include<windows.h>
#include<math.h>
#include<easyx.h>
#include <tchar.h> 

using namespace std;

vector<char> reuserName;//ע���û���
vector<char> repassWord;//ע������
vector<char> userName;//��¼�û���
vector<char> passWord;//��¼����
//��
vector<char> aw1;
vector<char> aw2;
vector<char> aw3;
vector<char> aw4;
vector<char> aw5;
vector<vector<char>> aw; 
vector<int> an1;
vector<int> an6;
vector<int> an7;
vector<int> an8;
vector<int> an9;
vector<int> an10;
vector<vector<int>> an;
//��Ŀ
vector<int> ti1;
vector<int> ti2;
vector<int> ti3;
vector<int> ti4;
vector<int> ti5;
vector<int> ti6;
vector<int> ti7;
vector<int> ti8;
vector<int> ti9;
vector<int> ti10;
vector<vector<int>> tiL;
vector<vector<int>> tiS;
vector<vector<char>>saw;
vector<vector<int>>san;
vector<vector<int>> thro;
//��ظ�������ı���
int ree = 0, lg = 0, count1 = 1, count2 = 1, i1 = 170, i2 = 170, i = 170, is = 170, page = 1, listen_answer = 0, record = 0, cc = 0, tie = 0, limt = 0, count_c = 0, gl = 0;
int tee = 0, judd = 0, mei = 0;
int max_page = 0;
MSG msg;
char mon = 33;

void answer_c(vector<int>);//�����ѡ����
void answer_t(vector<int>);//����������
void answer_cs(vector<int>);//�����ѡ����
void answer_ts(vector<int>);//����������
void answer_cc(vector<int>);//���������ѡ�����ܽ�
void answer_tt(vector<int>);//���������������ܽ�
void answer(vector<vector<int>>);//����ѡ�����յ�����
int menu();//���⡢�������
int first();//��ʼ����
int log();//��¼����
int log_s();//��¼�ɹ�����
int log_f();//��¼ʧ�ܽ���
void re();//ע��
int re_s();//ע��ɹ�����
void pe();//������Ŀԭʼ����
void daan();//�����������
int cou_s();//û�д������
int test();//�����ı�
int test_s();//����ɹ�����
void monitor();
LRESULT CALLBACK LowLevelKeyboardProc(
	_In_ int nCode,		// �涨������δ�����Ϣ��С�� 0 ��ֱ�� CallNextHookEx
	_In_ WPARAM wParam,	// ��Ϣ����
	_In_ LPARAM lParam	// ָ��ĳ���ṹ���ָ�룬������ KBDLLHOOKSTRUCT(�ͼ����������¼�)
	);
HHOOK keyboardHook = 0;		// ���Ӿ��

//������Ŀ
void pe(){
	//���������
	srand((unsigned)time(NULL));

	//����Ŀ�������
	tiL.push_back(ti1);//��һ��
	tiL.push_back(ti2);//�ڶ��� ��������
	tiL.push_back(ti3);
	tiL.push_back(ti4);
	tiL.push_back(ti5);
	tiL.push_back(ti6);
	tiL.push_back(ti7);
	tiL.push_back(ti8);
	tiL.push_back(ti9);
	tiL.push_back(ti10);

	//���ɷ�����������Ŀ
	for(int i=0;i<tiL.size();i++)
	{
		//����������ѡ����
		if(i < 5)
		{
			while(tiL[i].empty())
			{
				int t1 = rand()%100;//��һ��������
				int t2 = rand()%100;//�ڶ���������
				int t3 = rand()%2;//�б�Ӽ�
				int t4 = rand()%100;//����ѡ��
				int t5 = rand()%100;//����ѡ��
				int t6 = rand()%100;//����ѡ��
				int t7 = rand()%4;//��ȷѡ��λ��
				//�����ж� ����һ�������Ҵ����㡢����ѡ�����ȷ��ͬ
				if((t3 == 0 && t1 + t2 < 100 && t4 != t1 - t2 && t5 != t1 - t2 && t6 != t1 - t2 )|| (t3 == 1 && t1 >= t2 && t1 - t2 < 100 && t4 != t1 - t2 && t5 != t1 - t2 && t6 != t1 - t2))
				{
					//����ѡ��ҲҪ������ͬ
					if(t4 != t6 && t4 != t5 && t5 != t6)
					{
						//�����ɷ����������߸����ݲ�����Ŀ
						tiL[i].push_back(t1);
						tiL[i].push_back(t2);
						tiL[i].push_back(t3);
						tiL[i].push_back(t4);
						tiL[i].push_back(t5);
						tiL[i].push_back(t6);
						tiL[i].push_back(t7);
					}
				}
			}
		}else//�������µ����������
		{
			while(tiL[i].empty())
			{
				int t1 = rand()%100;//��һ��������
				int t2 = rand()%100;//�ڶ���������
				int t3 = rand()%2;//�б�Ӽ�
				//�����ж� �𰸴�����С��һ��
				if((t3 == 0 && t1 + t2 <= 100)|| (t3 == 1 && t1 >= t2 && t1 - t2 <= 100))
				{
					tiL[i].push_back(t1);
					tiL[i].push_back(t2);
					tiL[i].push_back(t3);
				}
			}
		}
	}
	//�����Ǽ�����Ŀ�Ƿ��ظ�
	//���ظ���Ŀ
	int cf = 0;

	while(1)
	{
		cf = 0;//����cfֵ
		for(int j=0;j<tiL.size()-1;j++)
		{
			for(int k=j+1;k<tiL.size();k++)
			{
				//�����Աȸ���Ŀǰ�������֣���ͬ��cf��һ
				if(tiL[j][0] == tiL[k][0] && tiL[j][1] == tiL[k][1] && tiL[j][2] == tiL[k][2])
				{
					cf++;
				}
			}
		}
		//��Ŀ����ͬ��ֹͣѭ��������Ŀ���
		if(cf == 0){
			break;
		}
		//�������������Ŀ������ѭ��ֱ���������ظ�����Ŀ
		for(int j=0;j<tiL.size();j++){
			tiL[j].clear();
		}
		for(int i=0;i<tiL.size();i++)
		{
			if(i < 5)
			{
				while(tiL[i].empty())
				{
					int t1 = rand()%100;
					int t2 = rand()%100;
					int t3 = rand()%2;
					int t4 = rand()%100;
					int t5 = rand()%100;
					int t6 = rand()%100;
					int t7 = rand()%4;
					if((t3 == 0 && t1 + t2 < 100 && t4 != t1 - t2 && t5 != t1 - t2 && t6 != t1 - t2 )|| (t3 == 1 && t1 >= t2 && t1 - t2 < 100 && t4 != t1 - t2 && t5 != t1 - t2 && t6 != t1 - t2))
					{
						if(t4 != t6 && t4 != t5 && t5 != t6)
						{
							tiL[i].push_back(t1);
							tiL[i].push_back(t2);
							tiL[i].push_back(t3);
							tiL[i].push_back(t4);
							tiL[i].push_back(t5);
							tiL[i].push_back(t6);
							tiL[i].push_back(t7);
						}
					}
				}
			}else
			{
				while(tiL[i].empty())
				{
					int t1 = rand()%100;
					int t2 = rand()%100;
					int t3 = rand()%2;
					if((t3 == 0 && t1 + t2 <= 100)|| (t3 == 1 && t1 >= t2 && t1 - t2 <= 100))
					{
						tiL[i].push_back(t1);
						tiL[i].push_back(t2);
						tiL[i].push_back(t3);
					}
				}
			}
		}

	}

	//���𰸲���𰸿�
	aw.push_back(aw1);
	aw.push_back(aw2);
	aw.push_back(aw3);
	aw.push_back(aw4);
	aw.push_back(aw5);
	for(int i=0;i<5;i++){ an.push_back(an1); }
	an.push_back(an6);
	an.push_back(an7);
	an.push_back(an8);
	an.push_back(an9);
	an.push_back(an10);
}

//��������
void answer_t(vector<int> ti){
	//��ʾ��Ŀ
	char cu[12];
	int zhi = 0;
	if(ti[0] < 10){
		cu[zhi] = ti[0] + 48;
		zhi++;
	}else{
		cu[zhi] = ti[0]/10 + 48;
		zhi++;
		cu[zhi] = ti[0]%10 + 48;
		zhi++;
	}
	cu[zhi] = ' ';
	zhi++;
	if(ti[2] == 0){
		cu[zhi] = '+';
		zhi++;
	}else{
		cu[zhi] = '-';
		zhi++;
	}
	if(ti[1] < 10){
		cu[zhi] = ti[1] + 48;
		zhi++;
	}else{
		cu[zhi] = ti[1]/10 + 48;
		zhi++;
		cu[zhi] = ti[1]%10 + 48;
		zhi++;
	}
	cu[zhi] = ' ';
	zhi++;

	cu[zhi] = ' ';
	zhi++;
	cu[zhi] = '=';
	zhi++;
	cu[zhi] = '\0';

	outtextxy(400, 90, cu);


	//��ʾҳ��
	char p[3];
	if(page < 10){
		p[0] = page + 48;
		p[1] = '\0';
	}else{
		p[0] = page/10 + 48;
		p[1] = page%10 + 48;
		p[2] = '\0';
	}

	//����
	rectangle(30, 180, 150, 300);
	line(70, 180, 70, 340);
	line(110, 180, 110, 300);
	line(30, 220, 150, 220);
	line(30, 260, 150, 260);
	rectangle(30, 300, 150, 340);
	outtextxy(30 + 16, 180 + 10, "1");
	outtextxy(70 + 16, 180 + 10, "2");
	outtextxy(110 + 16, 180 + 10, "3");
	outtextxy(30 + 16, 220 + 10, "4");
	outtextxy(70 + 16, 220 + 10, "5");
	outtextxy(110 + 16, 220 + 10, "6");
	outtextxy(30 + 16, 260 + 10, "7");
	outtextxy(70 + 16, 260 + 10, "8");
	outtextxy(110 + 16, 260 + 10, "9");
	outtextxy(30 + 16, 300 + 10, "0");
	line(80, 320, 140, 320);
	line(80, 320, 90, 310);
	line(80, 320, 90, 330);
	outtextxy(40, 30, "��");
	outtextxy(68, 30, p);
	char mp[3];
	if(max_page < 10){
		mp[0] = max_page + 48;
		mp[1] = '\0';
	}else{
		mp[0] = max_page/10 + 48;
		mp[1] = max_page%10 + 48;
		mp[2] = '\0';
	}
	outtextxy(90, 30, "�� ����");
	outtextxy(160, 30, mp);
	outtextxy(200, 30, "�⣩");
	line(470, 105, 500, 105);//

	//�л�ǰ����
	rectangle(360, 280, 420, 320);
	outtextxy(360+10, 280+15, "��һ��");
	rectangle(420, 280, 480, 320);
	outtextxy(420+10, 280+15, "��һ��");
	rectangle(480, 280, 540, 320);
	outtextxy(480+15, 280+15, "�ύ");

	//ʵ�ָ�������ť����
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 360 && m.x <= 420 && m.y >= 280 && m.y <= 320){
		if(page > 1){
			page--; 
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 420 && m.x <= 480 && m.y >= 280 && m.y <= 320){
		if(page < max_page){
			page++; 
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 30 && m.x <= 70 && m.y >= 180 && m.y <= 220){
		if(an[page-1].size()<2){
			outtextxy(470 + an[page-1].size()*10, 90, "1");
			an[page-1].push_back(1);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 70 && m.x <= 110 && m.y >= 180 && m.y <= 220){
		if(an[page-1].size()<2){
			outtextxy(470 + an[page-1].size()*10, 90, "2");
			an[page-1].push_back(2);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 110 && m.x <= 150 && m.y >= 180 && m.y <= 220){
		if(an[page-1].size()<2){
			outtextxy(470 + an[page-1].size()*10, 90, "3");
			an[page-1].push_back(3);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 30 && m.x <= 70 && m.y >= 220 && m.y <= 260){
		if(an[page-1].size()<2){
			outtextxy(470 + an[page-1].size()*10, 90, "4");
			an[page-1].push_back(4);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 70 && m.x <= 110 && m.y >= 220 && m.y <= 260){
		if(an[page-1].size() < 2){
			outtextxy(470 + an[page-1].size()*10, 90, "5");
			an[page-1].push_back(5);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 110 && m.x <= 150 && m.y >= 220 && m.y <= 260){
		if(an[page-1].size() < 2){
			outtextxy(470 + an[page-1].size()*10, 90, "6");
			an[page-1].push_back(6);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 30 && m.x <= 70 && m.y >= 260 && m.y <= 300){
		if(an[page-1].size() < 2){
			outtextxy(470 + an[page-1].size()*10, 90, "7");
			an[page-1].push_back(7);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 70 && m.x <= 110 && m.y >= 260 && m.y <= 300){
		if(an[page-1].size() < 2){
			outtextxy(470 + an[page-1].size()*10, 90, "8");
			an[page-1].push_back(8);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 110 && m.x <= 150 && m.y >= 260 && m.y <= 300){
		if(an[page-1].size() < 2){
			outtextxy(470 + an[page-1].size()*10, 90, "9");
			an[page-1].push_back(9);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 30 && m.x <= 70 && m.y >= 300 && m.y <= 340){
		if(an[page-1].size() < 2){
			outtextxy(470 + an[page-1].size()*10, 90, "0");
			an[page-1].push_back(0);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 70 && m.x <= 150 && m.y >= 300 && m.y <= 340){
		if(!an[page-1].empty()){
			an[page-1].pop_back();
			setfillcolor(BLACK);
			solidrectangle(460 + an.size()*10, 90, 460 + an[page-1].size()*10 + 10, 90+25);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 480 && m.x <= 540 && m.y >= 280 && m.y <= 320){
		listen_answer = 1;
		page = 1;
		gl = 1;
	}
}

//ѡ�����
void answer_c(vector<int> ti){
	//��ʾ��Ŀ
	char cu[12];
	int zhi = 0;
	if(ti[0] < 10){
		cu[zhi] = ti[0] + 48;
		zhi++;
	}else{
		cu[zhi] = ti[0]/10 + 48;
		zhi++;
		cu[zhi] = ti[0]%10 + 48;
		zhi++;
	}
	cu[zhi] = ' ';
	zhi++;
	if(ti[2] == 0){
		cu[zhi] = '+';
		zhi++;
	}else{
		cu[zhi] = '-';
		zhi++;
	}
	if(ti[1] < 10){
		cu[zhi] = ti[1] + 48;
		zhi++;
	}else{
		cu[zhi] = ti[1]/10 + 48;
		zhi++;
		cu[zhi] = ti[1]%10 + 48;
		zhi++;
	}
	cu[zhi] = ' ';
	zhi++;

	cu[zhi] = ' ';
	zhi++;
	cu[zhi] = '=';
	zhi++;
	cu[zhi] = '\0';

	outtextxy(230, 105, cu);

	//��ʾ��ȷ��
	int ass;
	if(ti[2] == 0){
		ass = ti[0] + ti[1];
	}else{
		ass = ti[0] - ti[1];
	}
	char cr[5];
	int zi = 0;
	if(ass < 10){
		cr[zi] = ass + 48;
		zi++;
	}else{
		cr[zi] = ass/10 + 48;
		zi++;
		cr[zi] = ass%10 + 48;
		zi++;
	}
	cr[zi] = '\0';
	outtextxy(60+35+120*ti[6], 200+15, cr);
	vector<int> ne;
	ne.push_back(ti[3]);
	ne.push_back(ti[4]);
	ne.push_back(ti[5]);

	//��ʾ����ѡ��
	if(ti[6] != 0){
		int ass1 = ne.back();
		ne.pop_back();
		char cr1[5];
		int zi1 = 0;
		if(ass1 < 10){
			cr1[zi1] = ass1 + 48;
			zi1++;
		}else{
			cr1[zi1] = ass1/10 + 48;
			zi1++;
			cr1[zi1] = ass1%10 + 48;
			zi1++;
		}
		cr1[zi1] = '\0';
		outtextxy(60+35, 200+15, cr1);
	}
	if(ti[6] != 1){
		int ass2 = ne.back();
		ne.pop_back();
		char cr2[5];
		int zi2 = 0;
		if(ass2 < 10){
			cr2[zi2] = ass2 + 48;
			zi2++;
		}else{
			cr2[zi2] = ass2/10 + 48;
			zi2++;
			cr2[zi2] = ass2%10 + 48;
			zi2++;
		}
		cr2[zi2] = '\0';
		outtextxy(180+35, 200+15, cr2);
	}
	if(ti[6] != 2){
		int ass3 = ne.back();
		ne.pop_back();
		char cr3[5];
		int zi3 = 0;
		if(ass3 < 10){
			cr3[zi3] = ass3 + 48;
			zi3++;
		}else{
			cr3[zi3] = ass3/10 + 48;
			zi3++;
			cr3[zi3] = ass3%10 + 48;
			zi3++;
		}
		cr3[zi3] = '\0';
		outtextxy(300+35, 200+15, cr3);
	}
	if(ti[6] != 3){
		int ass4 = ne.back();
		ne.pop_back();
		char cr4[5];
		int zi4 = 0;
		if(ass4 < 10){
			cr4[zi4] = ass4 + 48;
			zi4++;
		}else{
			cr4[zi4] = ass4/10 + 48;
			zi4++;
			cr4[zi4] = ass4%10 + 48;
			zi4++;
		}
		cr4[zi4] = '\0';
		outtextxy(420+35, 200+15, cr4);
	}


	//��ʾҳ��
	char p[3];
	if(page < 10){
		p[0] = page + 48;
		p[1] = '\0';
	}else{
		p[0] = page/10 + 48;
		p[1] = page%10 + 48;
		p[2] = '\0';
	}
	outtextxy(40, 30, "��");
	outtextxy(68, 30, p);
	char mp[3];
	if(max_page < 10){
		mp[0] = max_page + 48;
		mp[1] = '\0';
	}else{
		mp[0] = max_page/10 + 48;
		mp[1] = max_page%10 + 48;
		mp[2] = '\0';
	}
	outtextxy(90, 30, "�� ����");
	outtextxy(160, 30, mp);
	outtextxy(200, 30, "�⣩");
	line(300, 120, 330, 120);//
	//��ʾABCD
	rectangle(60, 200, 120, 240);
	outtextxy(60+15, 200+15, "A");
	rectangle(180, 200, 240, 240);
	outtextxy(180+15, 200+15, "B");
	rectangle(300, 200, 360, 240);
	outtextxy(300+15, 200+15, "C");
	rectangle(420, 200, 480, 240);
	outtextxy(420+15, 200+15, "D");
	rectangle(360, 280, 420, 320);

	//��ʾ�л���Ŀ
	outtextxy(360+10, 280+15, "��һ��");
	rectangle(420, 280, 480, 320);
	outtextxy(420+10, 280+15, "��һ��");
	rectangle(480, 280, 540, 320);
	outtextxy(480+15, 280+15, "�ύ");

	//ʵ�ָ�����������
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 60 && m.x <= 120 && m.y >= 200 && m.y <= 240){
		if(!aw[page-1].empty()){
			aw[page-1].push_back('A');
		}else{
			aw[page-1].pop_back();
			aw[page-1].push_back('A');
			setfillcolor(BLACK);
			solidrectangle(310, 100, 310 + 10, 100+25);
		}
		outtextxy(310, 100, "A");
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 180 && m.x <= 240 && m.y >= 200 && m.y <= 240){
		if(!aw[page-1].empty()){
			aw[page-1].push_back('B');
		}else{
			aw[page-1].pop_back();
			aw[page-1].push_back('B');
			setfillcolor(BLACK);
			solidrectangle(310, 100, 310 + 10, 100+25);
		}
		outtextxy(310, 100, "B");
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 300 && m.x <= 360 && m.y >= 200 && m.y <= 240){
		if(!aw[page-1].empty()){
			aw[page-1].push_back('C');
		}else{
			aw[page-1].pop_back();
			aw[page-1].push_back('C');
			setfillcolor(BLACK);
			solidrectangle(310, 100, 310 + 10, 100+25);
		}
		outtextxy(310, 100, "C");
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 420 && m.x <= 480 && m.y >= 200 && m.y <= 240){
		if(!aw[page-1].empty()){
			aw[page-1].push_back('D');
		}else{
			aw[page-1].pop_back();
			aw[page-1].push_back('D');
			setfillcolor(BLACK);
			solidrectangle(310, 100, 310 + 10, 100+25);
		}
		outtextxy(310, 100, "D");
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 360 && m.x <= 420 && m.y >= 280 && m.y <= 320){
		if(page > 1){
			page--; 
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 420 && m.x <= 480 && m.y >= 280 && m.y <= 320){
		if(page < max_page){
			page++; 
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 480 && m.x <= 540 && m.y >= 280 && m.y <= 320){
		listen_answer = 1;
		page = 1;
		gl = 1;
	}
}

//����
void answer(vector<vector<int>> tiLL){
		max_page = tiLL.size();
		for(int j=1;j<=tiLL.size();j++){
			if(j == page){
				if(!aw[page-1].empty() && record == 1 && tiLL[page-1].size()>5){
					char aww[2];
					aww[0] = aw[page-1][0];
					aww[1] = '\0';
					outtextxy(310, 100, aww);
					record = 0;
				}
				if(!an[page-1].empty() && record == 1 && tiLL[page-1].size()<5){
					char anw[3];
					anw[0] = an[page-1][0] + 48;
					anw[1] = an[page-1][1] + 48;
					anw[2] = '\0';
					outtextxy(470, 90, anw);
					record = 0;
				}
				if(tiLL[page-1].size()>5){ answer_c(tiLL[page-1]); }
				if(tiLL[page-1].size()<5){ answer_t(tiLL[page-1]); }
				if(page != j){
					cleardevice();
					record = 1;
				}
				break;
			}
		}
	

}

//�������
void answers(vector<vector<int>> tiLL){
	max_page = tiLL.size();
		for(int j=1;j<=tiLL.size();j++){
			if(j == page){
				if(!saw[page-1].empty() && record == 1 && tiLL[page-1].size()>5){
					char aww[2];
					aww[0] = saw[page-1][0];
					aww[1] = '\0';
					outtextxy(310, 100, aww);
					record = 0;
				}
				if(!san[page-1].empty() && record == 1 && tiLL[page-1].size()<5){
					char anw[3];
					anw[0] = san[page-1][0] + 48;
					anw[1] = san[page-1][1] + 48;
					anw[2] = '\0';
					outtextxy(470, 90, anw);
					record = 0;
				}
				if(tiLL[page-1].size()>5){ answer_cs(tiLL[page-1]); }
				if(tiLL[page-1].size()<5){ answer_ts(tiLL[page-1]); }
				if(page != j){
					cleardevice();
					record = 1;
				}
				break;
			}
		}

}

//���������
void answer_ts(vector<int> ti){
	//��ʾ��Ŀ
	char cu[12];
	int zhi = 0;
	if(ti[0] < 10){
		cu[zhi] = ti[0] + 48;
		zhi++;
	}else{
		cu[zhi] = ti[0]/10 + 48;
		zhi++;
		cu[zhi] = ti[0]%10 + 48;
		zhi++;
	}
	cu[zhi] = ' ';
	zhi++;
	if(ti[2] == 0){
		cu[zhi] = '+';
		zhi++;
	}else{
		cu[zhi] = '-';
		zhi++;
	}
	if(ti[1] < 10){
		cu[zhi] = ti[1] + 48;
		zhi++;
	}else{
		cu[zhi] = ti[1]/10 + 48;
		zhi++;
		cu[zhi] = ti[1]%10 + 48;
		zhi++;
	}
	cu[zhi] = ' ';
	zhi++;

	cu[zhi] = ' ';
	zhi++;
	cu[zhi] = '=';
	zhi++;
	cu[zhi] = '\0';

	outtextxy(400, 90, cu);


	//��ʾҳ��
	char p[3];
	if(page < 10){
		p[0] = page + 48;
		p[1] = '\0';
	}else{
		p[0] = page/10 + 48;
		p[1] = page%10 + 48;
		p[2] = '\0';
	}

	//����
	rectangle(30, 180, 150, 300);
	line(70, 180, 70, 340);
	line(110, 180, 110, 300);
	line(30, 220, 150, 220);
	line(30, 260, 150, 260);
	rectangle(30, 300, 150, 340);
	outtextxy(30 + 16, 180 + 10, "1");
	outtextxy(70 + 16, 180 + 10, "2");
	outtextxy(110 + 16, 180 + 10, "3");
	outtextxy(30 + 16, 220 + 10, "4");
	outtextxy(70 + 16, 220 + 10, "5");
	outtextxy(110 + 16, 220 + 10, "6");
	outtextxy(30 + 16, 260 + 10, "7");
	outtextxy(70 + 16, 260 + 10, "8");
	outtextxy(110 + 16, 260 + 10, "9");
	outtextxy(30 + 16, 300 + 10, "0");
	line(80, 320, 140, 320);
	line(80, 320, 90, 310);
	line(80, 320, 90, 330);
	outtextxy(40, 30, "��");
	outtextxy(68, 30, p);
	char mp[3];
	if(max_page < 10){
		mp[0] = max_page + 48;
		mp[1] = '\0';
	}else{
		mp[0] = max_page/10 + 48;
		mp[1] = max_page%10 + 48;
		mp[2] = '\0';
	}
	outtextxy(90, 30, "�� ����");
	outtextxy(160, 30, mp);
	outtextxy(200, 30, "�⣩");
	line(470, 105, 500, 105);//

	//�л�ǰ����
	rectangle(360, 280, 420, 320);
	outtextxy(360+10, 280+15, "��һ��");
	rectangle(420, 280, 480, 320);
	outtextxy(420+10, 280+15, "��һ��");
	rectangle(480, 280, 540, 320);
	outtextxy(480+15, 280+15, "�ύ");

	//ʵ�ָ�������ť����
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 360 && m.x <= 420 && m.y >= 280 && m.y <= 320){
		if(page > 1){
			page--; 
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 420 && m.x <= 480 && m.y >= 280 && m.y <= 320){
		if(page < max_page){
			page++; 
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 30 && m.x <= 70 && m.y >= 180 && m.y <= 220){
		if(san[page-1].size()<2){
			outtextxy(470 + san[page-1].size()*10, 90, "1");
			san[page-1].push_back(1);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 70 && m.x <= 110 && m.y >= 180 && m.y <= 220){
		if(san[page-1].size()<2){
			outtextxy(470 + san[page-1].size()*10, 90, "2");
			san[page-1].push_back(2);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 110 && m.x <= 150 && m.y >= 180 && m.y <= 220){
		if(san[page-1].size()<2){
			outtextxy(470 + san[page-1].size()*10, 90, "3");
			san[page-1].push_back(3);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 30 && m.x <= 70 && m.y >= 220 && m.y <= 260){
		if(san[page-1].size()<2){
			outtextxy(470 + san[page-1].size()*10, 90, "4");
			san[page-1].push_back(4);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 70 && m.x <= 110 && m.y >= 220 && m.y <= 260){
		if(san[page-1].size() < 2){
			outtextxy(470 + san[page-1].size()*10, 90, "5");
			san[page-1].push_back(5);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 110 && m.x <= 150 && m.y >= 220 && m.y <= 260){
		if(san[page-1].size() < 2){
			outtextxy(470 + san[page-1].size()*10, 90, "6");
			san[page-1].push_back(6);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 30 && m.x <= 70 && m.y >= 260 && m.y <= 300){
		if(san[page-1].size() < 2){
			outtextxy(470 + san[page-1].size()*10, 90, "7");
			san[page-1].push_back(7);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 70 && m.x <= 110 && m.y >= 260 && m.y <= 300){
		if(san[page-1].size() < 2){
			outtextxy(470 + san[page-1].size()*10, 90, "8");
			san[page-1].push_back(8);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 110 && m.x <= 150 && m.y >= 260 && m.y <= 300){
		if(san[page-1].size() < 2){
			outtextxy(470 + san[page-1].size()*10, 90, "9");
			san[page-1].push_back(9);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 30 && m.x <= 70 && m.y >= 300 && m.y <= 340){
		if(san[page-1].size() < 2){
			outtextxy(470 + san[page-1].size()*10, 90, "0");
			san[page-1].push_back(0);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 70 && m.x <= 150 && m.y >= 300 && m.y <= 340){
		if(!san[page-1].empty()){
			san[page-1].pop_back();
			setfillcolor(BLACK);
			solidrectangle(460 + san.size()*10, 90, 460 + san[page-1].size()*10 + 10, 90+25);
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 480 && m.x <= 540 && m.y >= 280 && m.y <= 320){
		listen_answer = 1;
		page = 1;
		gl = 1;
	}
}

//����ѡ����
void answer_cs(vector<int> ti){
	//��ʾ��Ŀ
	char cu[12];
	int zhi = 0;
	if(ti[0] < 10){
		cu[zhi] = ti[0] + 48;
		zhi++;
	}else{
		cu[zhi] = ti[0]/10 + 48;
		zhi++;
		cu[zhi] = ti[0]%10 + 48;
		zhi++;
	}
	cu[zhi] = ' ';
	zhi++;
	if(ti[2] == 0){
		cu[zhi] = '+';
		zhi++;
	}else{
		cu[zhi] = '-';
		zhi++;
	}
	if(ti[1] < 10){
		cu[zhi] = ti[1] + 48;
		zhi++;
	}else{
		cu[zhi] = ti[1]/10 + 48;
		zhi++;
		cu[zhi] = ti[1]%10 + 48;
		zhi++;
	}
	cu[zhi] = ' ';
	zhi++;

	cu[zhi] = ' ';
	zhi++;
	cu[zhi] = '=';
	zhi++;
	cu[zhi] = '\0';

	outtextxy(230, 105, cu);

	//��ʾ��ȷ��
	int ass;
	if(ti[2] == 0){
		ass = ti[0] + ti[1];
	}else{
		ass = ti[0] - ti[1];
	}
	char cr[5];
	int zi = 0;
	if(ass < 10){
		cr[zi] = ass + 48;
		zi++;
	}else{
		cr[zi] = ass/10 + 48;
		zi++;
		cr[zi] = ass%10 + 48;
		zi++;
	}
	cr[zi] = '\0';
	outtextxy(60+35+120*ti[6], 200+15, cr);
	vector<int> ne;
	ne.push_back(ti[3]);
	ne.push_back(ti[4]);
	ne.push_back(ti[5]);

	//��ʾ����ѡ��
	if(ti[6] != 0){
		int ass1 = ne.back();
		ne.pop_back();
		char cr1[5];
		int zi1 = 0;
		if(ass1 < 10){
			cr1[zi1] = ass1 + 48;
			zi1++;
		}else{
			cr1[zi1] = ass1/10 + 48;
			zi1++;
			cr1[zi1] = ass1%10 + 48;
			zi1++;
		}
		cr1[zi1] = '\0';
		outtextxy(60+35, 200+15, cr1);
	}
	if(ti[6] != 1){
		int ass2 = ne.back();
		ne.pop_back();
		char cr2[5];
		int zi2 = 0;
		if(ass2 < 10){
			cr2[zi2] = ass2 + 48;
			zi2++;
		}else{
			cr2[zi2] = ass2/10 + 48;
			zi2++;
			cr2[zi2] = ass2%10 + 48;
			zi2++;
		}
		cr2[zi2] = '\0';
		outtextxy(180+35, 200+15, cr2);
	}
	if(ti[6] != 2){
		int ass3 = ne.back();
		ne.pop_back();
		char cr3[5];
		int zi3 = 0;
		if(ass3 < 10){
			cr3[zi3] = ass3 + 48;
			zi3++;
		}else{
			cr3[zi3] = ass3/10 + 48;
			zi3++;
			cr3[zi3] = ass3%10 + 48;
			zi3++;
		}
		cr3[zi3] = '\0';
		outtextxy(300+35, 200+15, cr3);
	}
	if(ti[6] != 3){
		int ass4 = ne.back();
		ne.pop_back();
		char cr4[5];
		int zi4 = 0;
		if(ass4 < 10){
			cr4[zi4] = ass4 + 48;
			zi4++;
		}else{
			cr4[zi4] = ass4/10 + 48;
			zi4++;
			cr4[zi4] = ass4%10 + 48;
			zi4++;
		}
		cr4[zi4] = '\0';
		outtextxy(420+35, 200+15, cr4);
	}


	//��ʾҳ��
	char p[3];
	if(page < 10){
		p[0] = page + 48;
		p[1] = '\0';
	}else{
		p[0] = page/10 + 48;
		p[1] = page%10 + 48;
		p[2] = '\0';
	}
	outtextxy(40, 30, "��");
	outtextxy(68, 30, p);
	char mp[3];
	if(max_page < 10){
		mp[0] = max_page + 48;
		mp[1] = '\0';
	}else{
		mp[0] = max_page/10 + 48;
		mp[1] = max_page%10 + 48;
		mp[2] = '\0';
	}
	outtextxy(90, 30, "�� ����");
	outtextxy(160, 30, mp);
	outtextxy(200, 30, "�⣩");
	line(300, 120, 330, 120);//
	//��ʾABCD
	rectangle(60, 200, 120, 240);
	outtextxy(60+15, 200+15, "A");
	rectangle(180, 200, 240, 240);
	outtextxy(180+15, 200+15, "B");
	rectangle(300, 200, 360, 240);
	outtextxy(300+15, 200+15, "C");
	rectangle(420, 200, 480, 240);
	outtextxy(420+15, 200+15, "D");
	rectangle(360, 280, 420, 320);

	//��ʾ�л���Ŀ
	outtextxy(360+10, 280+15, "��һ��");
	rectangle(420, 280, 480, 320);
	outtextxy(420+10, 280+15, "��һ��");
	rectangle(480, 280, 540, 320);
	outtextxy(480+15, 280+15, "�ύ");

	//ʵ�ָ�����������
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 60 && m.x <= 120 && m.y >= 200 && m.y <= 240){
		if(!saw[page-1].empty()){
			saw[page-1].push_back('A');
		}else{
			saw[page-1].pop_back();
			saw[page-1].push_back('A');
			setfillcolor(BLACK);
			solidrectangle(310, 100, 310 + 10, 100+25);
		}
		outtextxy(310, 100, "A");
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 180 && m.x <= 240 && m.y >= 200 && m.y <= 240){
		if(!saw[page-1].empty()){
			saw[page-1].push_back('B');
		}else{
			saw[page-1].pop_back();
			saw[page-1].push_back('B');
			setfillcolor(BLACK);
			solidrectangle(310, 100, 310 + 10, 100+25);
		}
		outtextxy(310, 100, "B");
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 300 && m.x <= 360 && m.y >= 200 && m.y <= 240){
		if(!saw[page-1].empty()){
			saw[page-1].push_back('C');
		}else{
			saw[page-1].pop_back();
			saw[page-1].push_back('C');
			setfillcolor(BLACK);
			solidrectangle(310, 100, 310 + 10, 100+25);
		}
		outtextxy(310, 100, "C");
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 420 && m.x <= 480 && m.y >= 200 && m.y <= 240){
		if(!saw[page-1].empty()){
			saw[page-1].push_back('D');
		}else{
			saw[page-1].pop_back();
			saw[page-1].push_back('D');
			setfillcolor(BLACK);
			solidrectangle(310, 100, 310 + 10, 100+25);
		}
		outtextxy(310, 100, "D");
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 360 && m.x <= 420 && m.y >= 280 && m.y <= 320){
		if(page > 1){
			page--; 
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 420 && m.x <= 480 && m.y >= 280 && m.y <= 320){
		if(page < max_page){
			page++; 
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 480 && m.x <= 540 && m.y >= 280 && m.y <= 320){
		listen_answer = 1;
		page = 1;
		gl = 1;
	}
}

//������������
void answer_tt(vector<int> ti){
	//��������һ�£������޸Ĵ�ֻ�ܷ�ҳ����ʾ�����������ȷ���
	char cu[12];
	int zhi = 0;
	if(ti[0] < 10){
		cu[zhi] = ti[0] + 48;
		zhi++;
	}else{
		cu[zhi] = ti[0]/10 + 48;
		zhi++;
		cu[zhi] = ti[0]%10 + 48;
		zhi++;
	}
	cu[zhi] = ' ';
	zhi++;
	if(ti[2] == 0){
		cu[zhi] = '+';
		zhi++;
	}else{
		cu[zhi] = '-';
		zhi++;
	}
	if(ti[1] < 10){
		cu[zhi] = ti[1] + 48;
		zhi++;
	}else{
		cu[zhi] = ti[1]/10 + 48;
		zhi++;
		cu[zhi] = ti[1]%10 + 48;
		zhi++;
	}
	cu[zhi] = ' ';
	zhi++;

	cu[zhi] = ' ';
	zhi++;
	cu[zhi] = '=';
	zhi++;
	cu[zhi] = '\0';

	outtextxy(400, 90, cu);

	int ass;
	if(ti[2] == 0){
		ass = ti[0] + ti[1];
	}else{
		ass = ti[0] - ti[1];
	}
	char cr[5];
	int zi = 0;
	if(ass < 10){
		cr[zi] = ass + 48;
		zi++;
	}else{
		cr[zi] = ass/10 + 48;
		zi++;
		cr[zi] = ass%10 + 48;
		zi++;
	}
	cr[zi] = '\0';

	int jud = ti.back();
	if(jud){
		outtextxy(250, 140, "����ȷ");
	}else{
		outtextxy(180, 140, "�𰸴��� ��ȷ��Ϊ��");
		outtextxy(360, 140, cr);
	}

	char p[3];
	if(page < 10){
		p[0] = page + 48;
		p[1] = '\0';
	}else{
		p[0] = 1 + 48;
		p[1] = 48;
		p[2] = '\0';
	}
	outtextxy(110, 90, "��");
	outtextxy(128, 90, p);
	outtextxy(145, 90, "�� ����10�⣩");
	line(470, 105, 500, 105);//
	rectangle(360, 280, 420, 320);
	outtextxy(360+10, 280+15, "��һ��");
	rectangle(420, 280, 480, 320);
	outtextxy(420+10, 280+15, "��һ��");
	rectangle(480, 280, 540, 320);
	outtextxy(480+15, 280+15, "����");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 360 && m.x <= 420 && m.y >= 280 && m.y <= 320){
		if(page > 1){
			page--; 
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 420 && m.x <= 480 && m.y >= 280 && m.y <= 320){
		if(page < 10){
			page++; 
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 480 && m.x <= 540 && m.y >= 280 && m.y <= 320){
		listen_answer = 3;
	}
}

//�������ѡ����
void answer_cc(vector<int> ti){
	//��������һ�£������޸Ĵ�ֻ�ܷ�ҳ����ʾ�����������ȷ���
	char cu[12];
	int zhi = 0;
	if(ti[0] < 10){
		cu[zhi] = ti[0] + 48;
		zhi++;
	}else{
		cu[zhi] = ti[0]/10 + 48;
		zhi++;
		cu[zhi] = ti[0]%10 + 48;
		zhi++;
	}
	cu[zhi] = ' ';
	zhi++;
	if(ti[2] == 0){
		cu[zhi] = '+';
		zhi++;
	}else{
		cu[zhi] = '-';
		zhi++;
	}
	if(ti[1] < 10){
		cu[zhi] = ti[1] + 48;
		zhi++;
	}else{
		cu[zhi] = ti[1]/10 + 48;
		zhi++;
		cu[zhi] = ti[1]%10 + 48;
		zhi++;
	}
	cu[zhi] = ' ';
	zhi++;

	cu[zhi] = ' ';
	zhi++;
	cu[zhi] = '=';
	zhi++;
	cu[zhi] = '\0';

	outtextxy(230, 105, cu);

	int ass;
	if(ti[2] == 0){
		ass = ti[0] + ti[1];
	}else{
		ass = ti[0] - ti[1];
	}
	char cr[5];
	int zi = 0;
	if(ass < 10){
		cr[zi] = ass + 48;
		zi++;
	}else{
		cr[zi] = ass/10 + 48;
		zi++;
		cr[zi] = ass%10 + 48;
		zi++;
	}
	cr[zi] = '\0';
	outtextxy(60+35+120*ti[6], 200+15, cr);

	int jud = ti.back();
	if(jud){
		outtextxy(250, 140, "����ȷ");
	}else{
		outtextxy(180, 140, "�𰸴��� ��ȷ��Ϊ��");
		if(ti[6] == 0){ outtextxy(360, 140, "A"); }
		if(ti[6] == 1){ outtextxy(360, 140, "B"); }
		if(ti[6] == 2){ outtextxy(360, 140, "C"); }
		if(ti[6] == 3){ outtextxy(360, 140, "D"); }
	}

	vector<int> ne;
	ne.push_back(ti[3]);
	ne.push_back(ti[4]);
	ne.push_back(ti[5]);

	if(ti[6] != 0){
		int ass1 = ne.back();
		ne.pop_back();
		char cr1[5];
		int zi1 = 0;
		if(ass1 < 10){
			cr1[zi1] = ass1 + 48;
			zi1++;
		}else{
			cr1[zi1] = ass1/10 + 48;
			zi1++;
			cr1[zi1] = ass1%10 + 48;
			zi1++;
		}
		cr1[zi1] = '\0';
		outtextxy(60+35, 200+15, cr1);
	}
	if(ti[6] != 1){
		int ass2 = ne.back();
		ne.pop_back();
		char cr2[5];
		int zi2 = 0;
		if(ass2 < 10){
			cr2[zi2] = ass2 + 48;
			zi2++;
		}else{
			cr2[zi2] = ass2/10 + 48;
			zi2++;
			cr2[zi2] = ass2%10 + 48;
			zi2++;
		}
		cr2[zi2] = '\0';
		outtextxy(180+35, 200+15, cr2);
	}
	if(ti[6] != 2){
		int ass3 = ne.back();
		ne.pop_back();
		char cr3[5];
		int zi3 = 0;
		if(ass3 < 10){
			cr3[zi3] = ass3 + 48;
			zi3++;
		}else{
			cr3[zi3] = ass3/10 + 48;
			zi3++;
			cr3[zi3] = ass3%10 + 48;
			zi3++;
		}
		cr3[zi3] = '\0';
		outtextxy(300+35, 200+15, cr3);
	}
	if(ti[6] != 3){
		int ass4 = ne.back();
		ne.pop_back();
		char cr4[5];
		int zi4 = 0;
		if(ass4 < 10){
			cr4[zi4] = ass4 + 48;
			zi4++;
		}else{
			cr4[zi4] = ass4/10 + 48;
			zi4++;
			cr4[zi4] = ass4%10 + 48;
			zi4++;
		}
		cr4[zi4] = '\0';
		outtextxy(420+35, 200+15, cr4);
	}

	char p[3];
	if(page < 10){
		p[0] = page + 48;
		p[1] = '\0';
	}else{
		p[0] = 1 + 48;
		p[1] = 48;
		p[2] = '\0';
	}
	outtextxy(40, 30, "��");
	outtextxy(68, 30, p);
	outtextxy(90, 30, "�� ����10�⣩");
	line(300, 120, 330, 120);//
	rectangle(60, 200, 120, 240);
	outtextxy(60+15, 200+15, "A");
	rectangle(180, 200, 240, 240);
	outtextxy(180+15, 200+15, "B");
	rectangle(300, 200, 360, 240);
	outtextxy(300+15, 200+15, "C");
	rectangle(420, 200, 480, 240);
	outtextxy(420+15, 200+15, "D");
	rectangle(360, 280, 420, 320);
	outtextxy(360+10, 280+15, "��һ��");
	rectangle(420, 280, 480, 320);
	outtextxy(420+10, 280+15, "��һ��");
	rectangle(480, 280, 540, 320);
	outtextxy(480+15, 280+15, "����");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 360 && m.x <= 420 && m.y >= 280 && m.y <= 320){
		if(page > 1){
			page--; 
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 420 && m.x <= 480 && m.y >= 280 && m.y <= 320){
		if(page < 10){
			page++; 
		}
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 480 && m.x <= 540 && m.y >= 280 && m.y <= 320){
		listen_answer = 3;
	}
}

//�������
void answerr(vector<vector<int>> tiLL){
	//����ҳ���л���Ŀ
	switch(page){
	case 1:
		if(!aw[page-1].empty() && record == 1){
			char aww[2];
			aww[0] = aw[page-1][0];
			aww[1] = '\0';
			outtextxy(310, 100, aww);
			record = 0;
		}
		answer_cc(tiLL[page-1]);
		if(page != 1){
			cleardevice();
			record = 1;
		}
		break;
	case 2:
		if(!aw[page-1].empty() && record == 1){
			char aww[2];
			aww[0] = aw[page-1][0];
			aww[1] = '\0';
			outtextxy(310, 100, aww);
			record = 0;
		}
		answer_cc(tiLL[page-1]);
		if(page != 2){
			cleardevice();
			record = 1;
		}
		break;
	case 3:
		if(!aw[page-1].empty() && record == 1){
			char aww[2];
			aww[0] = aw[page-1][0];
			aww[1] = '\0';
			outtextxy(310, 100, aww);
			record = 0;
		}
		answer_cc(tiLL[page-1]);
		if(page != 3){
			cleardevice();
			record = 1;
		}
		break;
	case 4:
		if(!aw[page-1].empty() && record == 1){
			char aww[2];
			aww[0] = aw[page-1][0];
			aww[1] = '\0';
			outtextxy(310, 100, aww);
			record = 0;
		}
		answer_cc(tiLL[page-1]);
		if(page != 4){
			cleardevice();
			record = 1;
		}
		break;
	case 5:
		if(!aw[page-1].empty() && record == 1){
			char aww[2];
			aww[0] = aw[page-1][0];
			aww[1] = '\0';
			outtextxy(310, 100, aww);
			record = 0;
		}
		answer_cc(tiLL[page-1]);
		if(page != 5){
			cleardevice();
			record = 1;
		}
		break;
	case 6:
		if(!an[page-1].empty() && record == 1){
			char anw[3];
			anw[0] = an[page-1][0] + 48;
			anw[1] = an[page-1][1] + 48;
			anw[2] = '\0';
			outtextxy(470, 90, anw);
			record = 0;
		}
		answer_tt(tiLL[page-1]);
		if(page != 6){
			cleardevice();
			record = 1;
		}
		break;
	case 7:
		if(!an[page-1].empty() && record == 1){
			char anw[3];
			anw[0] = an[page-1][0] + 48;
			anw[1] = an[page-1][1] + 48;
			anw[2] = '\0';
			outtextxy(470, 90, anw);
			record = 0;
		}
		answer_tt(tiLL[page-1]);
		if(page != 7){
			cleardevice();
			record = 1;
		}
		break;
	case 8:
		if(!an[page-1].empty() && record == 1){
			char anw[3];
			anw[0] = an[page-1][0] + 48;
			anw[1] = an[page-1][1] + 48;
			anw[2] = '\0';
			outtextxy(470, 90, anw);
			record = 0;
		}
		answer_tt(tiLL[page-1]);
		if(page != 8){
			cleardevice();
			record = 1;
		}
		break;
	case 9:
		if(!an[page-1].empty() && record == 1){
			char anw[3];
			anw[0] = an[page-1][0] + 48;
			anw[1] = an[page-1][1] + 48;
			anw[2] = '\0';
			outtextxy(470, 90, anw);
			record = 0;
		}
		answer_tt(tiLL[page-1]);
		if(page != 9){
			cleardevice();
			record = 1;
		}
		break;
	case 10:
		if(!an[page-1].empty() && record == 1){
			char anw[3];
			anw[0] = an[page-1][0] + 48;
			anw[1] = an[page-1][1] + 48;
			anw[2] = '\0';
			outtextxy(470, 90, anw);
			record = 0;
		}
		answer_tt(tiLL[page-1]);
		if(page != 10){
			cleardevice();
			record = 1;
		}
		break;
	}

}

//�������ͳ��
void daans(){
	//�ж���Ŀ����ͳ��

	if(limt == 0){
		thro.clear();
		count_c = 0;
		for(int j=0;j<tiS.size();j++){
			if(tiS[j].size()>5){
				if(!saw[j].empty()){
					if((saw[j].back() == 'A' && tiS[j][6] == 0) || (saw[j].back() == 'B' && tiS[j][6] == 1) || (saw[j].back() == 'C' && tiS[j][6] == 2) || (saw[j].back() == 'D' && tiS[j][6] == 3)){
						//thro.push_back(tiS[j]);
						count_c++;
					}else{
						thro.push_back(tiS[j]);
					}
				}else{
					thro.push_back(tiS[j]);
				}
			}else{
				if(!san[j].empty()){
					if(((san[j].back() == (tiS[j][0] + tiS[j][1])) && tiS[j][2] == 0) || ((san[j].back() == (tiS[j][0] - tiS[j][1])) && tiS[j][2] == 1)){
						//thro.push_back(tiS[j]);
						count_c++;
						//cout<<"ccc"<<endl;
					}else{
					thro.push_back(tiS[j]);}
				}else{
					thro.push_back(tiS[j]);
				}
			}
		}
		cout<<count_c<<endl;
		limt = 1;
		//cout<<"ccc"<<endl;
	}

	tiS = thro;

	char count_cc[3];
	if(count_c < 10){
		count_cc[0] = count_c + 48;
		count_cc[1] = '\0';
	}else{
		count_cc[0] = count_c/10 + 48;
		count_cc[1] = count_c%10 + 48;
		count_cc[2] = '\0';
	}
	outtextxy(250, 120, count_cc);

	outtextxy(150, 120, "���������");
	rectangle(360, 280, 420, 320);
	outtextxy(360+10, 280+15, "����");
	//rectangle(420, 280, 540, 320);
	//outtextxy(420+10, 280+15, "�鿴�������");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 360 && m.x <= 420 && m.y >= 280 && m.y <= 320){
		gl = 3;
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 420 && m.x <= 540 && m.y >= 280 && m.y <= 320){
		//gl = 2;
	}
}

//����ͳ��
void daan(){
	//�ж���Ŀ����ͳ��
	if(limt == 0){
		for(int i=0;i<5;i++){
			if(!aw[i].empty()){
				char awch = aw[i].back();
				int awin = tiL[i][6];
				if((awch == 'A' && awin == 0) || (awch == 'B' && awin == 1) || (awch == 'C' && awin == 2) || (awch == 'D' && awin == 3)){
					count_c++;
					tiL[i].push_back(1);
				}else{
					tiS.push_back(tiL[i]);
					tiL[i].push_back(0);
					//cout<<"cc"<<endl;
				}
			}else{
				tiS.push_back(tiL[i]);
				tiL[i].push_back(0);
				//cout<<"cc"<<endl;
			}
		}
		for(int i=5;i<10;i++){
			int zz = -1;
			if(tiL[i][2] == 0){
				zz = tiL[i][0] + tiL[i][1];
			}else{
				zz = tiL[i][0] - tiL[i][1];
			}
			int zi = -2;
			if(!an[i].empty()){
				if(an[i].size() == 1){
					zi = an[i].back();
				}else{
					zi = an[i].back();
					an[i].pop_back();
					int zhuan = zi;
					zi = zi + an[i].back()*10;
					an[i].push_back(zhuan);
				}
			}else{
				tiS.push_back(tiL[i]);
				tiL[i].push_back(0);
			}
			if(zz == zi && !an[i].empty()){
				count_c++;
				tiL[i].push_back(1);
			}
			if(zz != zi && !an[i].empty()){
				tiS.push_back(tiL[i]);
				tiL[i].push_back(0);
			}
		}

		limt = 1;
	}

	char count_cc[3];
	if(count_c < 10){
		count_cc[0] = count_c + 48;
		count_cc[1] = '\0';
	}else{
		count_cc[0] = '1';
		count_cc[1] = '0';
		count_cc[2] = '\0';
	}
	outtextxy(250, 120, count_cc);

	outtextxy(150, 80, "������ʱ��");
	char tie_char[1000];
	int tie_z = 0, tie_j = 0, tie_y = tie;
	while(tie_y != 0){
		tie_j = tie_y - (tie_y/10)*10;
		tie_char[tie_z] = tie_j + 48;
		tie_z++;
		tie_y = tie_y/10;
	}
	char tie_ch[1000];
	for(int i=0;i<tie_z;i++){
		tie_ch[i] = tie_char[tie_z-i-1];
	}
	tie_ch[tie_z] = '\0';
	outtextxy(250, 80, tie_ch);
	outtextxy(280, 80, "��");
	outtextxy(150, 120, "���������");
	rectangle(360, 280, 420, 320);
	outtextxy(360+10, 280+15, "����");
	rectangle(420, 280, 540, 320);
	outtextxy(420+10, 280+15, "�鿴�������");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 360 && m.x <= 420 && m.y >= 280 && m.y <= 320){
		listen_answer = 3;
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 420 && m.x <= 540 && m.y >= 280 && m.y <= 320){
		listen_answer = 2;
	}
}

//���˵�
int menu()
{
	//�������˵�����
	outtextxy(240+15, 20, "���˵�");//������Ϊ(255, 20)�ĵط����"���˵�"
	rectangle(240, 100, 360, 140);//��ʼ���ⰴť���������Σ���������Ϊ��240�� 100������������Ϊ��360�� 140��
	outtextxy(240+15, 100+15, "��ʼ����");//���"��ʼ����"
	rectangle(240, 160, 360, 200);//��ʼ������ϰ��ť
	outtextxy(240+15, 160+15, "������ϰ");//���"������ϰ"
	rectangle(240, 220, 460, 260);//������Ŀ���ı��ĵ���ť
	outtextxy(240+15, 220+15, "������Ŀ���ı��ĵ�");//���"������Ŀ���ı��ĵ�"
	rectangle(240, 280, 360, 320);//�˳���¼��ť
	outtextxy(240+15, 280+15, "�˳���¼");//���"�˳���¼"
	//ʵ�ְ�ť����
	MOUSEMSG m;
	m = GetMouseMsg();//����������
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 360 && m.y >= 100 && m.y <= 140)        //������ڿ�ʼ����������ҵ�����������·���1
	{   
		return 1;
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 360 && m.y >= 160 && m.y <= 200)
	{
		return 2;
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 460 && m.y >= 220 && m.y <= 260)
	{
		return 3;
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 360 && m.y >= 280 && m.y <= 320)
	{
		return 4;
	}
	return 0;
}

//��ʼ����
int first(){
	//��ʾ���沢ʵ�ְ�ť����
	outtextxy(200+15, 15, "һ�����ڼӼ�����ϰ");
	rectangle(240, 100, 300, 140);
	outtextxy(240+15, 100+15, "��¼");
	rectangle(240, 160, 300, 200);
	outtextxy(240+15, 160+15, "ע��");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 300 && m.y >= 100 && m.y <= 140)
	{
		return 1;
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 300 && m.y >= 160 && m.y <= 200)
	{
		return 2;
	}
	return 0;
}

//��¼����
int log(){
	outtextxy(100+15, 260+15, "�������û����������ǵûس�Ŷ��");
	outtextxy(300, 10, "�û���½");
	outtextxy(100, 80, "�û���");
	rectangle(160, 80, 400, 100);
	outtextxy(100, 120, "����");
	rectangle(160, 120, 400, 140);
	rectangle(240, 160, 300, 200);
	outtextxy(240+15, 160+15, "��¼");
	if(count1 == 1){
		char key = 33;
		monitor();
		if(mon != 33 && mon != 127 && mon != 13){
			//cout<<"!!!"<<endl;
			key = mon;
		}
		if(mon == 127){
			key = 127;
		}
		if(mon == 13){
			key = 13;
		}
		if((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z') || (key >= '0' && key <= '9')){
			userName.push_back(key);
			outtextxy(i1, 80, key);
			i1 += 10;
		}else if(key == 13){
			count1 = 2;
		}else if(key == 127){
			if(!userName.empty()) userName.pop_back();
			if(i1 > 160+10){ i1 -= 10; }
			setfillcolor(BLACK);
			solidrectangle(i1, 80, i1+10, 80+25);
		}
		mon = 33;
	}
	if(count1 == 2){
		char key = 33;
		monitor();
		if(mon != 33 && mon != 127 && mon != 13){
			//cout<<"!!!"<<endl;
			key = mon;
		}
		if(mon == 127){
			key = 127;
		}
		if(mon == 13){
			key = 13;
		}
		if((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z') || (key >= '0' && key <= '9')){
			passWord.push_back(key);
			outtextxy(i2, 125, "*");
			i2 += 10;
		}else if(key == 13){
			count1 = 3;
		}else if(key == 127){
			if(!passWord.empty()) passWord.pop_back();
			if(i2 > 160+10){ i2-= 10; }
			setfillcolor(BLACK);
			solidrectangle(i2, 120, i2+10, 120+25);
		}
		mon = 33;
	}
	if(count1 == 3){
		string userName_str(userName.begin(), userName.end());
		string passWord_str(passWord.begin(), passWord.end());
		MOUSEMSG m;
		//monitor();
		m = GetMouseMsg();
		if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 300 && m.y >= 160 && m.y <= 200){
			ifstream ifs;
			ifs.open("./uesrs.txt", ios::in);
			if (!ifs.is_open()) {
				cout << "�ļ���ʧ��" << endl;
			}
			string buf;
			int mark = 0;
			while(ifs>>buf){
				if(buf == userName_str){
					ifs>>buf;
					if(buf == passWord_str){
						mark = 1;
						lg = 1;
						judd = 1;
					}
					ifs>>buf;
				}
			}
			if(mark == 0){
				lg = 2;
				judd = 1;
			}

			ifs.close();
		}
	}
	return 1;
}

//��¼�ɹ�����
int log_s(){
	tiS.clear();
	//if(tiS.size() == 0){cout<<"success"<<endl;}

	outtextxy(240, 80, "��¼�ɹ���");
	rectangle(240, 160, 300, 200);
	outtextxy(240+15, 160+15, "ȷ��");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 300 && m.y >= 160 && m.y <= 200)
	{
		return 1;
	}
	return 0;
}

//û�д������
int cou_s(){
	outtextxy(240, 80, "û�д��⣡");
	rectangle(240, 160, 300, 200);
	outtextxy(240+15, 160+15, "ȷ��");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 300 && m.y >= 160 && m.y <= 200)
	{
		return 1;
	}
	return 0;
}

//��¼ʧ�ܽ���
int log_f(){
	outtextxy(240, 80, "��¼ʧ�ܣ�");
	rectangle(240, 160, 300, 200);
	outtextxy(240+15, 160+15, "����");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 300 && m.y >= 160 && m.y <= 200)
	{
		return 1;
	}
	return 0;
}

//ע��
void re(){
	outtextxy(100+15, 260+15, "�������û����������ǵûس�Ŷ��");
	outtextxy(300, 10, "ע��");
	outtextxy(100, 80, "�û���");
	rectangle(160, 80, 400, 100);
	outtextxy(100, 120, "����");
	rectangle(160, 120, 400, 140);
	rectangle(240, 160, 300, 200);
	outtextxy(240+15, 160+15, "ע��");
	if(count2 == 1){
		char key = 33;
		monitor();
		if(mon != 33 && mon != 127 && mon != 13){
			//cout<<"!!!"<<endl;
			key = mon;
		}
		if(mon == 127){
			key = 127;
		}
		if(mon == 13){
			key = 13;
		}
		if((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z') || (key >= '0' && key <= '9')){
			reuserName.push_back(key);
			outtextxy(i, 80, key);
			i += 10;
		}else if(key == 13){
			count2 = 2;
		}else if(key == 127){
			if(!reuserName.empty()) reuserName.pop_back();
			if(i > 160+10){ i -= 10; }
			setfillcolor(BLACK);
			solidrectangle(i, 80, i+10, 80+25);
		}
		mon = 33;
	}
	if(count2 == 2){
		char key = 33;
		monitor();
		if(mon != 33 && mon != 127 && mon != 13){
			//cout<<"!!!"<<endl;
			key = mon;
		}
		if(mon == 127){
			key = 127;
		}
		if(mon == 13){
			key = 13;
		}
		if((key >= 'a' && key <= 'z') || (key >= 'A' && key <= 'Z') || (key >= '0' && key <= '9')){
			repassWord.push_back(key);
			outtextxy(is, 125, "*");
			is += 10;
		}else if(key == 13){
			count2 = 3;
		}else if(key == 127){
			if(!repassWord.empty()) repassWord.pop_back();
			if(is > 160+10){ is -= 10; }
			setfillcolor(BLACK);
			solidrectangle(is, 120, is+10, 120+25);
		}
		mon = 33;
	}
	if(count2 == 3){
		string reuserName_str(reuserName.begin(), reuserName.end());
		string repassWord_str(repassWord.begin(), repassWord.end());
		MOUSEMSG m;
		m = GetMouseMsg();
		if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 300 && m.y >= 160 && m.y <= 200){
			ofstream ofs;
			ofs.open("./uesrs.txt", ios::app);
			if (!ofs.is_open()) {
				cout << "�ļ���ʧ��" << endl;
			}
			ofs<<reuserName_str<<endl;
			ofs<<repassWord_str<<endl;
			ofs.close();
			ree = 1;
			judd = 1;
		}
	}
}
//ע��ɹ�����
int re_s(){
	outtextxy(240, 80, "ע��ɹ���");
	rectangle(240, 160, 300, 200);
	outtextxy(240+15, 160+15, "ȷ��");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 300 && m.y >= 160 && m.y <= 200)
	{
		return 1;
	}
	return 0;
}

//�����ı�
int test(){
	pe();//������Ŀ
	string str, annm;//���ڴ洢��Ŀ���ַ���
	//������⣬������Ŀ����
	char tii[3];
	for(int i=0;i<10;i++){
		if(i < 9){
			tii[0] = i + 49;
			tii[1] = '\0';
		}else{
			tii[0] = '1';
			tii[1] = '0';
			tii[2] = '\0';
		}
		string tlii(tii);
		str += "��";
		str += tlii;
		str += "�� ";
		annm = "��" + tlii + "��";
		char cu[50];//�洢��Ŀ���ַ�����
		int zhi = 0;//��ʼָ��Ϊ��
		//����һ����ת��Ϊ�ַ���������
		//��С������ֱ��ת��
		if(tiL[i][0] < 10){
			cu[zhi] = tiL[i][0] + 48;
			zhi++;
		}else{
			//Ϊ��λ������������ת��������
			cu[zhi] = tiL[i][0]/10 + 48;
			zhi++;
			cu[zhi] = tiL[i][0]%10 + 48;
			zhi++;
		}
		cu[zhi] = ' '; //����ո�
		zhi++;
		//�ж���������������
		if(tiL[i][2] == 0){
			cu[zhi] = '+';
			zhi++;
		}else{
			cu[zhi] = '-';
			zhi++;
		}

		//���ڶ�����ת��Ϊ�ַ�����
		if(tiL[i][1] < 10){
			cu[zhi] = tiL[i][1] + 48;
			zhi++;
		}else{
			cu[zhi] = tiL[i][1]/10 + 48;
			zhi++;
			cu[zhi] = tiL[i][1]%10 + 48;
			zhi++;
		}
		//����ո��Լ��Ⱥ�
		cu[zhi] = ' ';
		zhi++;

		cu[zhi] = ' ';
		zhi++;
		cu[zhi] = '=';
		zhi++;
		cu[zhi] = ' ';
		zhi++;
		cu[zhi] = '\0';//β��׷�ӡ�\0����β��Ϊ�ַ���

		//ת����ȷ��Ϊ�ַ���
		int ass;
		if(tiL[i][2] == 0){
			ass = tiL[i][0] + tiL[i][1];
		}else{
			ass = tiL[i][0] - tiL[i][1];
		}
		char cr[5];
		int zi = 0;
		if(ass < 10){
			cr[zi] = ass + 48;
			zi++;
		}else{
			cr[zi] = ass/10 + 48;
			zi++;
			cr[zi] = ass%10 + 48;
			zi++;
		}
		cr[zi] = '\0';
		cout<<cu;//�����Ŀ
		string scu(cu);//char*תstring���ͱ���ƴ��
		str += scu;//ƴ��
		//�����ֱ������ʺźʹ𰸣���ƴ����Ӧ�ַ���
		if(i >= 5){
			cout<<"? ��ȷ��Ϊ��";
			str += "?";
			cout<<cr<<endl;
			string scr(cr);
			annm += "��ȷ��Ϊ��" + scr;
		}else{//ѡ��������Ҫ����ѡ��
			//������ѡ�����������
			vector<int> as;
			as.push_back(tiL[i][3]);
			as.push_back(tiL[i][4]);
			as.push_back(tiL[i][5]);
			//׷���ʺ�
			cout<<"? ";
			str += "? ";
			//Aѡ��
			cout<<"  A ";
			str += "  A ";
			//����ȷѡ��λ�÷�A�򽫸���ѡ����벢�Ѵ˸���ѡ��Ӹ���ѡ���������߳�
			if(tiL[i][6] != 0){
				int asss = as.back();
				as.pop_back();
				char crr[5];
				zi = 0;
				if(asss < 10){
					crr[zi] = asss + 48;
					zi++;
				}else{
					crr[zi] = asss/10 + 48;
					zi++;
					crr[zi] = asss%10 + 48;
					zi++;
				}
				crr[zi] = '\0';
				cout<<crr;
				string scrr(crr);
				str += scrr;
			}else{//����ȷѡ��ΪA��ֱ����A�������ȷѡ�� ����BCDѡ����ͬAѡ��
				cout<<cr;
				string scr(cr);
				str += scr;
			}
			cout<<"  B ";
			str += "  B ";
			if(tiL[i][6] != 1){
				int asss = as.back();
				as.pop_back();
				char crr[5];
				zi = 0;
				if(asss < 10){
					crr[zi] = asss + 48;
					zi++;
				}else{
					crr[zi] = asss/10 + 48;
					zi++;
					crr[zi] = asss%10 + 48;
					zi++;
				}
				crr[zi] = '\0';
				cout<<crr;
				string scrr(crr);
				str += scrr;
			}else{
				cout<<cr;
				string scr(cr);
				str += scr;
			}
			cout<<"  C ";
			str += "  C ";
			if(tiL[i][6] != 2){
				int asss = as.back();
				as.pop_back();
				char crr[5];
				zi = 0;
				if(asss < 10){
					crr[zi] = asss + 48;
					zi++;
				}else{
					crr[zi] = asss/10 + 48;
					zi++;
					crr[zi] = asss%10 + 48;
					zi++;
				}
				crr[zi] = '\0';
				cout<<crr;
				string scrr(crr);
				str += scrr;
			}else{
				cout<<cr;
				string scr(cr);
				str += scr;
			}
			cout<<"  D ";
			str += "  D ";
			if(tiL[i][6] != 3){
				int asss = as.back();
				as.pop_back();
				char crr[5];
				zi = 0;
				if(asss < 10){
					crr[zi] = asss + 48;
					zi++;
				}else{
					crr[zi] = asss/10 + 48;
					zi++;
					crr[zi] = asss%10 + 48;
					zi++;
				}
				crr[zi] = '\0';
				cout<<crr;
				string scrr(crr);
				str += scrr;
			}else{
				cout<<cr;
				string scr(cr);
				str += scr;
			}
			//׷����ȷ���ַ�����ָ����ȷѡ����ʲô
			cout<<" ��ȷ��Ϊ��";
			annm += " ��ȷ��Ϊ��";
			if(tiL[i][6] == 0){ cout<<"A"<<endl; annm += "A";}
			if(tiL[i][6] == 1){ cout<<"B"<<endl; annm += "B";}
			if(tiL[i][6] == 2){ cout<<"C"<<endl; annm += "C";}
			if(tiL[i][6] == 3){ cout<<"D"<<endl; annm += "D";}
		}
		//���ļ�����ǰ��ƴ�Ӻõ��ַ���д���ļ����ٹر��ļ�
		ofstream ofs;
		ofs.open("./project.txt", ios::app);
		if (!ofs.is_open()) {
				cout << "�ļ���ʧ��" << endl;
		}
		ofs<<str<<endl;
		ofs.close();
		ofs.open("./answer.txt", ios::app);
		if (!ofs.is_open()) {
				cout << "�ļ���ʧ��" << endl;
		}
		ofs<<annm<<endl;
		ofs.close();
		str = "";
		annm = "";
	}
	return 1;
}

//����ɹ�����
int test_s(){
	outtextxy(240, 80, "����ɹ���");
	rectangle(240, 160, 300, 200);
	outtextxy(240+15, 160+15, "ȷ��");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 300 && m.y >= 160 && m.y <= 200)
	{
		return 1;
	}
	return 0;
}

LRESULT CALLBACK LowLevelKeyboardProc(
	_In_ int nCode,		// �涨������δ�����Ϣ��С�� 0 ��ֱ�� CallNextHookEx
	_In_ WPARAM wParam,	// ��Ϣ����
	_In_ LPARAM lParam	// ָ��ĳ���ṹ���ָ�룬������ KBDLLHOOKSTRUCT(�ͼ����������¼�)
	){
    KBDLLHOOKSTRUCT *ks = (KBDLLHOOKSTRUCT*)lParam;		// �����ͼ����������¼���Ϣ
	/*
	typedef struct tagKBDLLHOOKSTRUCT {
		DWORD     vkCode;		// ��������
		DWORD     scanCode;		// Ӳ��ɨ����ţ�ͬ vkCode Ҳ������Ϊ�����Ĵ��š�
		DWORD     flags;		// �¼����ͣ�һ�㰴������Ϊ 0 ̧��Ϊ 128��
		DWORD     time;			// ��Ϣʱ���
		ULONG_PTR dwExtraInfo;	// ��Ϣ������Ϣ��һ��Ϊ 0��
	}KBDLLHOOKSTRUCT,*LPKBDLLHOOKSTRUCT,*PKBDLLHOOKSTRUCT;
	*/
    if(ks->flags == 128 || ks->flags == 129)
    {
		// ��ؼ���
		switch(ks->vkCode){
		case 0x30: case 0x60:
			//cout << "��⵽������" << "0" << endl;
			mon = '0';
			break;
		case 0x31: case 0x61:
			//cout << "��⵽������" << "1" << endl;
			mon = '1';
			break;
		case 0x32: case 0x62:
			//cout << "��⵽������" << "2" << endl;
			mon = '2';
			break;
		case 0x33: case 0x63:
			//cout << "��⵽������" << "3" << endl;
			mon = '3';
			break;
		case 0x34: case 0x64:
			//cout << "��⵽������" << "4" << endl;
			mon = '4';
			break;
		case 0x35: case 0x65:
			//cout << "��⵽������" << "5" << endl;
			mon = '5';
			break;
		case 0x36: case 0x66:
			//cout << "��⵽������" << "6" << endl;
			mon = '6';
			break;
		case 0x37: case 0x67:
			//cout << "��⵽������" << "7" << endl;
			mon = '7';
			break;
		case 0x38: case 0x68:
			//cout << "��⵽������" << "8" << endl;
			mon = '8';
			break;
		case 0x39: case 0x69:
			//cout << "��⵽������" << "9" << endl;
			mon = '9';
			break;
		case 0x41:
			//cout << "��⵽������" << "A" << endl;
			mon = 'a';
			break;
		case 0x42:
			//cout << "��⵽������" << "B" << endl;
			mon = 'b';
			break;
		case 0x43:
			//cout << "��⵽������" << "C" << endl;
			mon = 'c';
			break;
		case 0x44:
			//cout << "��⵽������" << "D" << endl;
			mon = 'd';
			break;
		case 0x45:
			//cout << "��⵽������" << "E" << endl;
			mon = 'e';
			break;
		case 0x46:
			//cout << "��⵽������" << "F" << endl;
			mon = 'f';
			break;
		case 0x47:
			//cout << "��⵽������" << "G" << endl;
			mon = 'g';
			break;
		case 0x48:
			//cout << "��⵽������" << "H" << endl;
			mon = 'h';
			break;
		case 0x49:
			//cout << "��⵽������" << "I" << endl;
			mon = 'i';
			break;
		case 0x4A:
			//cout << "��⵽������" << "J" << endl;
			mon = 'j';
			break;
		case 0x4B:
			//cout << "��⵽������" << "K" << endl;
			mon = 'k';
			break;
		case 0x4C:
			//cout << "��⵽������" << "L" << endl;
			mon = 'l';
			break;
		case 0x4D:
			//cout << "��⵽������" << "M" << endl;
			mon = 'm';
			break;
		case 0x4E:
			//cout << "��⵽������" << "N" << endl;
			mon = 'n';
			break;
		case 0x4F:
			//cout << "��⵽������" << "O" << endl;
			mon = 'o';
			break;
		case 0x50:
			//cout << "��⵽������" << "P" << endl;
			mon = 'p';
			break;
		case 0x51:
			//cout << "��⵽������" << "Q" << endl;
			mon = 'q';
			break;
		case 0x52:
			//cout << "��⵽������" << "R" << endl;
			mon = 'r';
			break;
		case 0x53:
			//cout << "��⵽������" << "S" << endl;
			mon = 's';
			break;
		case 0x54:
			//cout << "��⵽������" << "T" << endl;
			mon = 't';
			break;
		case 0x55:
			//cout << "��⵽������" << "U" << endl;
			mon = 'u';
			break;
		case 0x56:
			//cout << "��⵽������" << "V" << endl;
			mon = 'v';
			break;
		case 0x57:
			//cout << "��⵽������" << "W" << endl;
			mon = 'w';
			break;
		case 0x58:
			//cout << "��⵽������" << "X" << endl;
			mon = 'x';
			break;
		case 0x59:
			//cout << "��⵽������" << "Y" << endl;
			mon = 't';
			break;
		case 0x5A:
			//cout << "��⵽������" << "Z" << endl;
			mon = 'z';
			break;
		case 0x6A:
			//cout << "��⵽������" << "*" << endl;
			mon = '*';
			break;
		case 0x6B:
			//cout << "��⵽������" << "+" << endl;
			mon = '+';
			break;
		case 0x6D:
			//cout << "��⵽������" << "-" << endl;
			mon = '-';
			break;
		case 0x6E:
			//cout << "��⵽������" << "." << endl;
			mon = '0';
			break;
		case 0x6F:
			//cout << "��⵽������" << "/" << endl;
			mon = '.';
			break;
		case 0x0D:
			//cout << "��⵽������" << "Enter" << endl;
			mon = 13;
			break;
		case 0xA0: case 0xA1:
			//cout << "��⵽������" << "Shift" << endl;
			mon = 33;
			break;
		case 0x08:
			//cout << "��⵽������" << "Backspace" << endl;
			mon = 127;
			break;
		case 0x20:
			//cout << "��⵽������" << "Space" << endl;
			mon = ' ';
			break;
		}
		
        //return 1;		// ʹ����ʧЧ
    }
 
	// ����Ϣ���ݸ��������е���һ������
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void monitor(){
	if (PeekMessageA(
		&msg,		// MSG ���������Ϣ
		NULL,		// �����Ϣ�Ĵ��ھ����NULL��������ǰ�߳����д�����Ϣ
		NULL,		// �����Ϣ��Χ�е�һ����Ϣ��ֵ��NULL�����������Ϣ(����������ͬʱΪNULL)
		NULL,		// �����Ϣ��Χ�����һ����Ϣ��ֵ��NULL�����������Ϣ(����������ͬʱΪNULL)
		PM_REMOVE	// ������Ϣ�ķ�ʽ��PM_REMOVE���������Ϣ�Ӷ�����ɾ��
		)){
			// �Ѱ�����Ϣ���ݸ��ַ���Ϣ
			TranslateMessage(&msg);

			// ����Ϣ���ɸ����ڳ���
			DispatchMessageW(&msg);
	}
	else
		Sleep(0);    //����CPUȫ��������

}

void libtxt(){
	ofstream ofs;
	ofs.open("./cuoti.txt", ios::app);
	string userName_str(userName.begin(), userName.end());
	ofs<<"###";
	ofs<<userName_str<<endl;
	for(int j=0;j<tiS.size();j++){
		string str = "";
		for(int k=0;k<tiS[j].size();k++){
			str += " ";
			int ass = tiS[j][k];
			char cr[5];
			int zi = 0;
			if(ass < 10){
				cr[zi] = ass + 48;
				zi++;
			}else{
				cr[zi] = ass/10 + 48;
				zi++;
				cr[zi] = ass%10 + 48;
				zi++;
			}
			cr[zi] = '\0';
			string asss(cr);
		str += asss;
		}
		str += " @";
		ofs<<str<<endl;
	}
	ofs.close();
}

int _tmain(int argc, _TCHAR* argv[]){

	// ��װ����
	keyboardHook = SetWindowsHookEx(
		WH_KEYBOARD_LL,			// �������ͣ�WH_KEYBOARD_LL Ϊ���̹���
		LowLevelKeyboardProc,	// ָ���Ӻ�����ָ��
		GetModuleHandleA(NULL),	// Dll ���
		NULL					
		);
    if (keyboardHook == 0){cout << "�ҹ�����ʧ��" << endl; return -1;}
 
    //����©����Ϣ������Ȼ����Ῠ��
   
	//������Ŀ

	//������Ŀ
	pe();
	int judge = 0;//���ƽ���
	initgraph(640, 360);//��ʼ������
	clock_t start,end;//����ʱ�����
	//ͨ���ı�judge��ֵʵ�ֽ���֮����໥�л����л���ͨ����������ʾ�ķ�ʽʵ��
	while(true){
		if(judge == 0){
			int temp = first();
			if(temp == 1){
				cleardevice();
				judge = 1;
			}
			if(temp == 2){
				cleardevice();
				judge = 2;
			}
		}
		if(judge == 1){
			if(judd == 1){
				//�е���¼����ʱ����û��������룬�Լ����������йص�¼�������
				userName.clear();
				passWord.clear();
				count1 = 1;
				i1 = 170; 
				i2 = 170;
				judd = 0;
			}
			log();
			if(lg == 1){
				cleardevice();
				lg = 0;
				judge = 3;
			}
			if(lg == 2){
				cleardevice();
				lg = 0;
				judge = 4;
			}
		}
		if(judge == 2){
			if(judd == 1){
				//�е�ע�����ʱ����û��������룬�Լ����������й�ע��������
				reuserName.clear();
				repassWord.clear();
				count2 = 1;
				i = 170;
				is = 170;
				judd = 0;
			}
			re();
			if(ree == 1){
				cleardevice();
				ree = 0;
				judge = 5;
			}
		}
		if(judge == 3){
			int temp = log_s();
			if(temp == 1){

				string userName_str(userName.begin(), userName.end());
				int jilu = 0;

				ifstream ifs;
				ifs.open("./cuoti.txt", ios::in);
				if (!ifs.is_open()) {
				cout << "�ļ���ʧ��" << endl;
				}
				string buf;
				int mark = 0;
				string name = "###" + userName_str;
				while(ifs>>buf){
					mark++;
					if(buf == name){
						jilu = mark;
					}
				}
				ifs.close();

				int num;
				ifs.open("./cuoti.txt", ios::in);
				for(int j=0;j<jilu;j++){ ifs>>buf; }
				string str = "15131365";
				vector<int> dcc;
				while(ifs>>buf){
					
					if(buf.size() > 3){
						break;
					}
					if(buf != "@"){
						//cout<<buf<<endl;
						if(buf.size()<2){
						num = buf[0] - 48;
						}else{
							num = (buf[0] - 48)*10 + (buf[1] - 48);
							//cout<<"qiguai"<<num<<endl;
						}
						dcc.push_back(num);
					}else{
						tiS.push_back(dcc);
						dcc.clear();
					}
				}
				ifs.close();

				cleardevice();
				judge = 6;
			}
		}
		if(judge == 4){
			int temp = log_f();
			if(temp == 1){
				cleardevice();
				judge = 0;
			}
		}
		if(judge == 5){
			int temp = re_s();
			if(temp == 1){
				cleardevice();
				listen_answer = 0;
				judge = 0;
			}
		}
		if(judge == 6){
			int temp = menu();
			if(temp == 1){
				listen_answer = 0;
				//������������ٴ�ˢ�����
				mei++;
				cleardevice();
				judge = 7;
				tiL.clear();
				ti1.clear();
				ti2.clear();
				ti3.clear();
				ti4.clear();
				ti5.clear();
				ti6.clear();
				ti7.clear();
				ti8.clear();
				ti9.clear();
				ti10.clear();
				//aw.clear();
				aw1.clear();
				aw2.clear();
				aw3.clear();
				aw4.clear();
				aw5.clear();
				//an.clear();
				an6.clear();
				an7.clear();
				an8.clear();
				an9.clear();
				an10.clear();
				start = clock();
				pe();
			}
			if(temp == 2){
				gl = 0;
				listen_answer = 0;
				count_c = 0;
				saw.clear();
				san.clear();
				limt = 0;
				for(int j=0;j<tiS.size();j++){
					vector<char> lsa;
					vector<int> lsw;
					saw.push_back(lsa);
					san.push_back(lsw);
				}
				cleardevice();
				if(tiS.size() == 0){
					judge = 10;
				}else{
					judge = 8;
				}
			}
			if(temp == 3){
				cleardevice();
				judge = 9;
			}
			if(temp == 4){
				cleardevice();
				libtxt();
				tiS.clear();
				tiL.clear();
				judge = 0;
			}
		}
		if(judge == 7){
			if(listen_answer == 0){
				if(cc == 0){
					start = clock();
					cc = 1;
				}
				answer(tiL);
				if(listen_answer == 1){
					cleardevice();
					end = clock();
					tie = (end-start)/CLK_TCK;
					limt = 0;
				}
			}
			if(listen_answer == 1){
				daan();
				if(listen_answer == 2){
					cleardevice();
				}
				if(listen_answer == 3){
					cleardevice();
					record = 1;
					page = 1;
				}
			}
			if(listen_answer == 2){
				record = 1;
				answerr(tiL);
				if(listen_answer == 3){
					cleardevice();
					record = 1;
					page = 1;
				}
			}
			if(listen_answer == 3){
				listen_answer = 0;
				judge = 6;
			}
		}
		if(judge == 8){
			if(gl == 0){
				answers(tiS);
				if(gl == 1){
					cleardevice();
				}
			}
			if(gl == 1){
				daans();
				if(gl == 3){
					cleardevice();
					judge = 6;
					gl = 0;
					limt = 0;
				}
				if(gl == 2){
					cleardevice();
				}
			}
			if(gl == 2){
				judge = 6;
			}
		}
		if(judge == 9){
			if(tee == 0){
				test();
				tee = 1;
			}
			int temp = test_s();
			if(temp == 1){
				cleardevice();
				tee = 0;
				judge = 6;
				temp = 0;
				//tiS.clear();
			}
		}
		if(judge == 10){
			int temp = cou_s();
			if(temp == 1){
				cleardevice();
				listen_answer = 0;
				judge = 6;
			}
		}
	}
	UnhookWindowsHookEx(keyboardHook);
	return 0;
}		