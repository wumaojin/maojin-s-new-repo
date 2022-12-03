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

vector<char> reuserName;//注册用户名
vector<char> repassWord;//注册密码
vector<char> userName;//登录用户名
vector<char> passWord;//登录密码
//答案
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
//题目
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
//监控各个界面的变量
int ree = 0, lg = 0, count1 = 1, count2 = 1, i1 = 170, i2 = 170, i = 170, is = 170, page = 1, listen_answer = 0, record = 0, cc = 0, tie = 0, limt = 0, count_c = 0, gl = 0;
int tee = 0, judd = 0, mei = 0;
int max_page = 0;
MSG msg;
char mon = 33;

void answer_c(vector<int>);//答题的选择题
void answer_t(vector<int>);//答题的填空题
void answer_cs(vector<int>);//错题的选择题
void answer_ts(vector<int>);//错题的填空题
void answer_cc(vector<int>);//答题结束的选择题总结
void answer_tt(vector<int>);//答题结束的填空题总结
void answer(vector<vector<int>>);//答题选择和填空的整合
int menu();//答题、错题界面
int first();//初始界面
int log();//登录界面
int log_s();//登录成功界面
int log_f();//登录失败界面
void re();//注册
int re_s();//注册成功界面
void pe();//生成题目原始数据
void daan();//答题情况界面
int cou_s();//没有错题界面
int test();//导入文本
int test_s();//导入成功界面
void monitor();
LRESULT CALLBACK LowLevelKeyboardProc(
	_In_ int nCode,		// 规定钩子如何处理消息，小于 0 则直接 CallNextHookEx
	_In_ WPARAM wParam,	// 消息类型
	_In_ LPARAM lParam	// 指向某个结构体的指针，这里是 KBDLLHOOKSTRUCT(低级键盘输入事件)
	);
HHOOK keyboardHook = 0;		// 钩子句柄

//生成题目
void pe(){
	//随机数种子
	srand((unsigned)time(NULL));

	//将题目插入题库
	tiL.push_back(ti1);//第一题
	tiL.push_back(ti2);//第二题 依此类推
	tiL.push_back(ti3);
	tiL.push_back(ti4);
	tiL.push_back(ti5);
	tiL.push_back(ti6);
	tiL.push_back(ti7);
	tiL.push_back(ti8);
	tiL.push_back(ti9);
	tiL.push_back(ti10);

	//生成符合条件的题目
	for(int i=0;i<tiL.size();i++)
	{
		//先生成五条选择题
		if(i < 5)
		{
			while(tiL[i].empty())
			{
				int t1 = rand()%100;//第一个运算数
				int t2 = rand()%100;//第二个运算数
				int t3 = rand()%2;//判别加减
				int t4 = rand()%100;//干扰选项
				int t5 = rand()%100;//干扰选项
				int t6 = rand()%100;//干扰选项
				int t7 = rand()%4;//正确选项位置
				//条件判断 答案在一百以内且大于零、干扰选项不与正确相同
				if((t3 == 0 && t1 + t2 < 100 && t4 != t1 - t2 && t5 != t1 - t2 && t6 != t1 - t2 )|| (t3 == 1 && t1 >= t2 && t1 - t2 < 100 && t4 != t1 - t2 && t5 != t1 - t2 && t6 != t1 - t2))
				{
					//干扰选项也要互不相同
					if(t4 != t6 && t4 != t5 && t5 != t6)
					{
						//将生成符合条件的七个数据插入题目
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
		}else//生成余下的五条填空题
		{
			while(tiL[i].empty())
			{
				int t1 = rand()%100;//第一个运算数
				int t2 = rand()%100;//第二个运算数
				int t3 = rand()%2;//判别加减
				//条件判断 答案大于零小于一百
				if((t3 == 0 && t1 + t2 <= 100)|| (t3 == 1 && t1 >= t2 && t1 - t2 <= 100))
				{
					tiL[i].push_back(t1);
					tiL[i].push_back(t2);
					tiL[i].push_back(t3);
				}
			}
		}
	}
	//下面是检验题目是否重复
	//计重复题目
	int cf = 0;

	while(1)
	{
		cf = 0;//重置cf值
		for(int j=0;j<tiL.size()-1;j++)
		{
			for(int k=j+1;k<tiL.size();k++)
			{
				//逐条对比各题目前三个数字，相同则cf加一
				if(tiL[j][0] == tiL[k][0] && tiL[j][1] == tiL[k][1] && tiL[j][2] == tiL[k][2])
				{
					cf++;
				}
			}
		}
		//题目均不同则停止循环生成题目完毕
		if(cf == 0){
			break;
		}
		//否则继续生成题目，不断循环直至生成无重复的题目
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

	//将答案插入答案库
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

//填空题界面
void answer_t(vector<int> ti){
	//显示题目
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


	//显示页码
	char p[3];
	if(page < 10){
		p[0] = page + 48;
		p[1] = '\0';
	}else{
		p[0] = page/10 + 48;
		p[1] = page%10 + 48;
		p[2] = '\0';
	}

	//键盘
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
	outtextxy(40, 30, "第");
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
	outtextxy(90, 30, "题 （共");
	outtextxy(160, 30, mp);
	outtextxy(200, 30, "题）");
	line(470, 105, 500, 105);//

	//切换前后题
	rectangle(360, 280, 420, 320);
	outtextxy(360+10, 280+15, "上一题");
	rectangle(420, 280, 480, 320);
	outtextxy(420+10, 280+15, "下一题");
	rectangle(480, 280, 540, 320);
	outtextxy(480+15, 280+15, "提交");

	//实现个各个按钮功能
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

//选择界面
void answer_c(vector<int> ti){
	//显示题目
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

	//显示正确答案
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

	//显示错误选项
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


	//显示页码
	char p[3];
	if(page < 10){
		p[0] = page + 48;
		p[1] = '\0';
	}else{
		p[0] = page/10 + 48;
		p[1] = page%10 + 48;
		p[2] = '\0';
	}
	outtextxy(40, 30, "第");
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
	outtextxy(90, 30, "题 （共");
	outtextxy(160, 30, mp);
	outtextxy(200, 30, "题）");
	line(300, 120, 330, 120);//
	//显示ABCD
	rectangle(60, 200, 120, 240);
	outtextxy(60+15, 200+15, "A");
	rectangle(180, 200, 240, 240);
	outtextxy(180+15, 200+15, "B");
	rectangle(300, 200, 360, 240);
	outtextxy(300+15, 200+15, "C");
	rectangle(420, 200, 480, 240);
	outtextxy(420+15, 200+15, "D");
	rectangle(360, 280, 420, 320);

	//显示切换题目
	outtextxy(360+10, 280+15, "上一题");
	rectangle(420, 280, 480, 320);
	outtextxy(420+10, 280+15, "下一题");
	rectangle(480, 280, 540, 320);
	outtextxy(480+15, 280+15, "提交");

	//实现各个按键功能
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

//答题
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

//错题答题
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

//错题填空题
void answer_ts(vector<int> ti){
	//显示题目
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


	//显示页码
	char p[3];
	if(page < 10){
		p[0] = page + 48;
		p[1] = '\0';
	}else{
		p[0] = page/10 + 48;
		p[1] = page%10 + 48;
		p[2] = '\0';
	}

	//键盘
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
	outtextxy(40, 30, "第");
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
	outtextxy(90, 30, "题 （共");
	outtextxy(160, 30, mp);
	outtextxy(200, 30, "题）");
	line(470, 105, 500, 105);//

	//切换前后题
	rectangle(360, 280, 420, 320);
	outtextxy(360+10, 280+15, "上一题");
	rectangle(420, 280, 480, 320);
	outtextxy(420+10, 280+15, "下一题");
	rectangle(480, 280, 540, 320);
	outtextxy(480+15, 280+15, "提交");

	//实现个各个按钮功能
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

//错题选择题
void answer_cs(vector<int> ti){
	//显示题目
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

	//显示正确答案
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

	//显示错误选项
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


	//显示页码
	char p[3];
	if(page < 10){
		p[0] = page + 48;
		p[1] = '\0';
	}else{
		p[0] = page/10 + 48;
		p[1] = page%10 + 48;
		p[2] = '\0';
	}
	outtextxy(40, 30, "第");
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
	outtextxy(90, 30, "题 （共");
	outtextxy(160, 30, mp);
	outtextxy(200, 30, "题）");
	line(300, 120, 330, 120);//
	//显示ABCD
	rectangle(60, 200, 120, 240);
	outtextxy(60+15, 200+15, "A");
	rectangle(180, 200, 240, 240);
	outtextxy(180+15, 200+15, "B");
	rectangle(300, 200, 360, 240);
	outtextxy(300+15, 200+15, "C");
	rectangle(420, 200, 480, 240);
	outtextxy(420+15, 200+15, "D");
	rectangle(360, 280, 420, 320);

	//显示切换题目
	outtextxy(360+10, 280+15, "上一题");
	rectangle(420, 280, 480, 320);
	outtextxy(420+10, 280+15, "下一题");
	rectangle(480, 280, 540, 320);
	outtextxy(480+15, 280+15, "提交");

	//实现各个按键功能
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

//答题情况填空题
void answer_tt(vector<int> ti){
	//与答题界面一致，不能修改答案只能翻页，显示答题正误和正确结果
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
		outtextxy(250, 140, "答案正确");
	}else{
		outtextxy(180, 140, "答案错误 正确答案为：");
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
	outtextxy(110, 90, "第");
	outtextxy(128, 90, p);
	outtextxy(145, 90, "题 （共10题）");
	line(470, 105, 500, 105);//
	rectangle(360, 280, 420, 320);
	outtextxy(360+10, 280+15, "上一题");
	rectangle(420, 280, 480, 320);
	outtextxy(420+10, 280+15, "下一题");
	rectangle(480, 280, 540, 320);
	outtextxy(480+15, 280+15, "返回");
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

//答题情况选择题
void answer_cc(vector<int> ti){
	//与答题界面一致，不能修改答案只能翻页，显示答题正误和正确结果
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
		outtextxy(250, 140, "答案正确");
	}else{
		outtextxy(180, 140, "答案错误 正确答案为：");
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
	outtextxy(40, 30, "第");
	outtextxy(68, 30, p);
	outtextxy(90, 30, "题 （共10题）");
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
	outtextxy(360+10, 280+15, "上一题");
	rectangle(420, 280, 480, 320);
	outtextxy(420+10, 280+15, "下一题");
	rectangle(480, 280, 540, 320);
	outtextxy(480+15, 280+15, "返回");
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

//答题情况
void answerr(vector<vector<int>> tiLL){
	//根据页码切换题目
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

//错题答题统计
void daans(){
	//判断题目正误并统计

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

	outtextxy(150, 120, "答对题数：");
	rectangle(360, 280, 420, 320);
	outtextxy(360+10, 280+15, "返回");
	//rectangle(420, 280, 540, 320);
	//outtextxy(420+10, 280+15, "查看答题情况");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 360 && m.x <= 420 && m.y >= 280 && m.y <= 320){
		gl = 3;
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 420 && m.x <= 540 && m.y >= 280 && m.y <= 320){
		//gl = 2;
	}
}

//答题统计
void daan(){
	//判断题目正误并统计
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

	outtextxy(150, 80, "共计用时：");
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
	outtextxy(280, 80, "秒");
	outtextxy(150, 120, "答对题数：");
	rectangle(360, 280, 420, 320);
	outtextxy(360+10, 280+15, "返回");
	rectangle(420, 280, 540, 320);
	outtextxy(420+10, 280+15, "查看答题情况");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 360 && m.x <= 420 && m.y >= 280 && m.y <= 320){
		listen_answer = 3;
	}
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 420 && m.x <= 540 && m.y >= 280 && m.y <= 320){
		listen_answer = 2;
	}
}

//主菜单
int menu()
{
	//构造主菜单界面
	outtextxy(240+15, 20, "主菜单");//在坐标为(255, 20)的地方输出"主菜单"
	rectangle(240, 100, 360, 140);//开始答题按钮，画出矩形，左上坐标为（240， 100），右下坐标为（360， 140）
	outtextxy(240+15, 100+15, "开始答题");//输出"开始答题"
	rectangle(240, 160, 360, 200);//开始错题练习按钮
	outtextxy(240+15, 160+15, "错题练习");//输出"错题练习"
	rectangle(240, 220, 460, 260);//生成题目至文本文档按钮
	outtextxy(240+15, 220+15, "生成题目至文本文档");//输出"生成题目至文本文档"
	rectangle(240, 280, 360, 320);//退出登录按钮
	outtextxy(240+15, 280+15, "退出登录");//输出"退出登录"
	//实现按钮功能
	MOUSEMSG m;
	m = GetMouseMsg();//创建鼠标对象
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 360 && m.y >= 100 && m.y <= 140)        //当鼠标在开始答题矩形内且点击左键的情况下返回1
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

//初始界面
int first(){
	//显示界面并实现按钮功能
	outtextxy(200+15, 15, "一百以内加减法练习");
	rectangle(240, 100, 300, 140);
	outtextxy(240+15, 100+15, "登录");
	rectangle(240, 160, 300, 200);
	outtextxy(240+15, 160+15, "注册");
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

//登录界面
int log(){
	outtextxy(100+15, 260+15, "输入完用户名或密码后记得回车哦！");
	outtextxy(300, 10, "用户登陆");
	outtextxy(100, 80, "用户名");
	rectangle(160, 80, 400, 100);
	outtextxy(100, 120, "密码");
	rectangle(160, 120, 400, 140);
	rectangle(240, 160, 300, 200);
	outtextxy(240+15, 160+15, "登录");
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
				cout << "文件打开失败" << endl;
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

//登录成功界面
int log_s(){
	tiS.clear();
	//if(tiS.size() == 0){cout<<"success"<<endl;}

	outtextxy(240, 80, "登录成功！");
	rectangle(240, 160, 300, 200);
	outtextxy(240+15, 160+15, "确定");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 300 && m.y >= 160 && m.y <= 200)
	{
		return 1;
	}
	return 0;
}

//没有错题界面
int cou_s(){
	outtextxy(240, 80, "没有错题！");
	rectangle(240, 160, 300, 200);
	outtextxy(240+15, 160+15, "确定");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 300 && m.y >= 160 && m.y <= 200)
	{
		return 1;
	}
	return 0;
}

//登录失败界面
int log_f(){
	outtextxy(240, 80, "登录失败！");
	rectangle(240, 160, 300, 200);
	outtextxy(240+15, 160+15, "返回");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 300 && m.y >= 160 && m.y <= 200)
	{
		return 1;
	}
	return 0;
}

//注册
void re(){
	outtextxy(100+15, 260+15, "输入完用户名或密码后记得回车哦！");
	outtextxy(300, 10, "注册");
	outtextxy(100, 80, "用户名");
	rectangle(160, 80, 400, 100);
	outtextxy(100, 120, "密码");
	rectangle(160, 120, 400, 140);
	rectangle(240, 160, 300, 200);
	outtextxy(240+15, 160+15, "注册");
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
				cout << "文件打开失败" << endl;
			}
			ofs<<reuserName_str<<endl;
			ofs<<repassWord_str<<endl;
			ofs.close();
			ree = 1;
			judd = 1;
		}
	}
}
//注册成功界面
int re_s(){
	outtextxy(240, 80, "注册成功！");
	rectangle(240, 160, 300, 200);
	outtextxy(240+15, 160+15, "确定");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 300 && m.y >= 160 && m.y <= 200)
	{
		return 1;
	}
	return 0;
}

//导入文本
int test(){
	pe();//生成题目
	string str, annm;//用于存储题目的字符串
	//遍历题库，将各题目导入
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
		str += "第";
		str += tlii;
		str += "题 ";
		annm = "第" + tlii + "题";
		char cu[50];//存储题目的字符数组
		int zhi = 0;//初始指针为零
		//将第一个数转化为字符导入数组
		//若小于零则直接转化
		if(tiL[i][0] < 10){
			cu[zhi] = tiL[i][0] + 48;
			zhi++;
		}else{
			//为两位数这个逐个数字转化并插入
			cu[zhi] = tiL[i][0]/10 + 48;
			zhi++;
			cu[zhi] = tiL[i][0]%10 + 48;
			zhi++;
		}
		cu[zhi] = ' '; //加入空格
		zhi++;
		//判断正负并加入数组
		if(tiL[i][2] == 0){
			cu[zhi] = '+';
			zhi++;
		}else{
			cu[zhi] = '-';
			zhi++;
		}

		//将第二个数转化为字符插入
		if(tiL[i][1] < 10){
			cu[zhi] = tiL[i][1] + 48;
			zhi++;
		}else{
			cu[zhi] = tiL[i][1]/10 + 48;
			zhi++;
			cu[zhi] = tiL[i][1]%10 + 48;
			zhi++;
		}
		//加入空格以及等号
		cu[zhi] = ' ';
		zhi++;

		cu[zhi] = ' ';
		zhi++;
		cu[zhi] = '=';
		zhi++;
		cu[zhi] = ' ';
		zhi++;
		cu[zhi] = '\0';//尾部追加‘\0’结尾，为字符串

		//转化正确答案为字符串
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
		cout<<cu;//输出题目
		string scu(cu);//char*转string类型便于拼接
		str += scu;//拼接
		//填空题直接输出问号和答案，并拼接相应字符串
		if(i >= 5){
			cout<<"? 正确答案为：";
			str += "?";
			cout<<cr<<endl;
			string scr(cr);
			annm += "正确答案为：" + scr;
		}else{//选择题则需要安排选项
			//将干扰选项存入新数字
			vector<int> as;
			as.push_back(tiL[i][3]);
			as.push_back(tiL[i][4]);
			as.push_back(tiL[i][5]);
			//追加问号
			cout<<"? ";
			str += "? ";
			//A选项
			cout<<"  A ";
			str += "  A ";
			//若正确选项位置非A则将干扰选项插入并把此干扰选项从干扰选项数组中踢出
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
			}else{//若正确选项为A则直接在A处输出正确选择 后面BCD选项雷同A选项
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
			//追加正确答案字符，并指出正确选项是什么
			cout<<" 正确答案为：";
			annm += " 正确答案为：";
			if(tiL[i][6] == 0){ cout<<"A"<<endl; annm += "A";}
			if(tiL[i][6] == 1){ cout<<"B"<<endl; annm += "B";}
			if(tiL[i][6] == 2){ cout<<"C"<<endl; annm += "C";}
			if(tiL[i][6] == 3){ cout<<"D"<<endl; annm += "D";}
		}
		//打开文件将此前面拼接好的字符串写入文件，再关闭文件
		ofstream ofs;
		ofs.open("./project.txt", ios::app);
		if (!ofs.is_open()) {
				cout << "文件打开失败" << endl;
		}
		ofs<<str<<endl;
		ofs.close();
		ofs.open("./answer.txt", ios::app);
		if (!ofs.is_open()) {
				cout << "文件打开失败" << endl;
		}
		ofs<<annm<<endl;
		ofs.close();
		str = "";
		annm = "";
	}
	return 1;
}

//导入成功界面
int test_s(){
	outtextxy(240, 80, "导入成功！");
	rectangle(240, 160, 300, 200);
	outtextxy(240+15, 160+15, "确定");
	MOUSEMSG m;
	m = GetMouseMsg();
	if(m.uMsg == WM_LBUTTONDOWN && m.x >= 240 && m.x <= 300 && m.y >= 160 && m.y <= 200)
	{
		return 1;
	}
	return 0;
}

LRESULT CALLBACK LowLevelKeyboardProc(
	_In_ int nCode,		// 规定钩子如何处理消息，小于 0 则直接 CallNextHookEx
	_In_ WPARAM wParam,	// 消息类型
	_In_ LPARAM lParam	// 指向某个结构体的指针，这里是 KBDLLHOOKSTRUCT(低级键盘输入事件)
	){
    KBDLLHOOKSTRUCT *ks = (KBDLLHOOKSTRUCT*)lParam;		// 包含低级键盘输入事件信息
	/*
	typedef struct tagKBDLLHOOKSTRUCT {
		DWORD     vkCode;		// 按键代号
		DWORD     scanCode;		// 硬件扫描代号，同 vkCode 也可以作为按键的代号。
		DWORD     flags;		// 事件类型，一般按键按下为 0 抬起为 128。
		DWORD     time;			// 消息时间戳
		ULONG_PTR dwExtraInfo;	// 消息附加信息，一般为 0。
	}KBDLLHOOKSTRUCT,*LPKBDLLHOOKSTRUCT,*PKBDLLHOOKSTRUCT;
	*/
    if(ks->flags == 128 || ks->flags == 129)
    {
		// 监控键盘
		switch(ks->vkCode){
		case 0x30: case 0x60:
			//cout << "检测到按键：" << "0" << endl;
			mon = '0';
			break;
		case 0x31: case 0x61:
			//cout << "检测到按键：" << "1" << endl;
			mon = '1';
			break;
		case 0x32: case 0x62:
			//cout << "检测到按键：" << "2" << endl;
			mon = '2';
			break;
		case 0x33: case 0x63:
			//cout << "检测到按键：" << "3" << endl;
			mon = '3';
			break;
		case 0x34: case 0x64:
			//cout << "检测到按键：" << "4" << endl;
			mon = '4';
			break;
		case 0x35: case 0x65:
			//cout << "检测到按键：" << "5" << endl;
			mon = '5';
			break;
		case 0x36: case 0x66:
			//cout << "检测到按键：" << "6" << endl;
			mon = '6';
			break;
		case 0x37: case 0x67:
			//cout << "检测到按键：" << "7" << endl;
			mon = '7';
			break;
		case 0x38: case 0x68:
			//cout << "检测到按键：" << "8" << endl;
			mon = '8';
			break;
		case 0x39: case 0x69:
			//cout << "检测到按键：" << "9" << endl;
			mon = '9';
			break;
		case 0x41:
			//cout << "检测到按键：" << "A" << endl;
			mon = 'a';
			break;
		case 0x42:
			//cout << "检测到按键：" << "B" << endl;
			mon = 'b';
			break;
		case 0x43:
			//cout << "检测到按键：" << "C" << endl;
			mon = 'c';
			break;
		case 0x44:
			//cout << "检测到按键：" << "D" << endl;
			mon = 'd';
			break;
		case 0x45:
			//cout << "检测到按键：" << "E" << endl;
			mon = 'e';
			break;
		case 0x46:
			//cout << "检测到按键：" << "F" << endl;
			mon = 'f';
			break;
		case 0x47:
			//cout << "检测到按键：" << "G" << endl;
			mon = 'g';
			break;
		case 0x48:
			//cout << "检测到按键：" << "H" << endl;
			mon = 'h';
			break;
		case 0x49:
			//cout << "检测到按键：" << "I" << endl;
			mon = 'i';
			break;
		case 0x4A:
			//cout << "检测到按键：" << "J" << endl;
			mon = 'j';
			break;
		case 0x4B:
			//cout << "检测到按键：" << "K" << endl;
			mon = 'k';
			break;
		case 0x4C:
			//cout << "检测到按键：" << "L" << endl;
			mon = 'l';
			break;
		case 0x4D:
			//cout << "检测到按键：" << "M" << endl;
			mon = 'm';
			break;
		case 0x4E:
			//cout << "检测到按键：" << "N" << endl;
			mon = 'n';
			break;
		case 0x4F:
			//cout << "检测到按键：" << "O" << endl;
			mon = 'o';
			break;
		case 0x50:
			//cout << "检测到按键：" << "P" << endl;
			mon = 'p';
			break;
		case 0x51:
			//cout << "检测到按键：" << "Q" << endl;
			mon = 'q';
			break;
		case 0x52:
			//cout << "检测到按键：" << "R" << endl;
			mon = 'r';
			break;
		case 0x53:
			//cout << "检测到按键：" << "S" << endl;
			mon = 's';
			break;
		case 0x54:
			//cout << "检测到按键：" << "T" << endl;
			mon = 't';
			break;
		case 0x55:
			//cout << "检测到按键：" << "U" << endl;
			mon = 'u';
			break;
		case 0x56:
			//cout << "检测到按键：" << "V" << endl;
			mon = 'v';
			break;
		case 0x57:
			//cout << "检测到按键：" << "W" << endl;
			mon = 'w';
			break;
		case 0x58:
			//cout << "检测到按键：" << "X" << endl;
			mon = 'x';
			break;
		case 0x59:
			//cout << "检测到按键：" << "Y" << endl;
			mon = 't';
			break;
		case 0x5A:
			//cout << "检测到按键：" << "Z" << endl;
			mon = 'z';
			break;
		case 0x6A:
			//cout << "检测到按键：" << "*" << endl;
			mon = '*';
			break;
		case 0x6B:
			//cout << "检测到按键：" << "+" << endl;
			mon = '+';
			break;
		case 0x6D:
			//cout << "检测到按键：" << "-" << endl;
			mon = '-';
			break;
		case 0x6E:
			//cout << "检测到按键：" << "." << endl;
			mon = '0';
			break;
		case 0x6F:
			//cout << "检测到按键：" << "/" << endl;
			mon = '.';
			break;
		case 0x0D:
			//cout << "检测到按键：" << "Enter" << endl;
			mon = 13;
			break;
		case 0xA0: case 0xA1:
			//cout << "检测到按键：" << "Shift" << endl;
			mon = 33;
			break;
		case 0x08:
			//cout << "检测到按键：" << "Backspace" << endl;
			mon = 127;
			break;
		case 0x20:
			//cout << "检测到按键：" << "Space" << endl;
			mon = ' ';
			break;
		}
		
        //return 1;		// 使按键失效
    }
 
	// 将消息传递给钩子链中的下一个钩子
    return CallNextHookEx(NULL, nCode, wParam, lParam);
}

void monitor(){
	if (PeekMessageA(
		&msg,		// MSG 接收这个消息
		NULL,		// 检测消息的窗口句柄，NULL：检索当前线程所有窗口消息
		NULL,		// 检查消息范围中第一个消息的值，NULL：检查所有消息(必须和下面的同时为NULL)
		NULL,		// 检查消息范围中最后一个消息的值，NULL：检查所有消息(必须和上面的同时为NULL)
		PM_REMOVE	// 处理消息的方式，PM_REMOVE：处理后将消息从队列中删除
		)){
			// 把按键消息传递给字符消息
			TranslateMessage(&msg);

			// 将消息分派给窗口程序
			DispatchMessageW(&msg);
	}
	else
		Sleep(0);    //避免CPU全负载运行

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

	// 安装钩子
	keyboardHook = SetWindowsHookEx(
		WH_KEYBOARD_LL,			// 钩子类型，WH_KEYBOARD_LL 为键盘钩子
		LowLevelKeyboardProc,	// 指向钩子函数的指针
		GetModuleHandleA(NULL),	// Dll 句柄
		NULL					
		);
    if (keyboardHook == 0){cout << "挂钩键盘失败" << endl; return -1;}
 
    //不可漏掉消息处理，不然程序会卡死
   
	//生成题目

	//生成题目
	pe();
	int judge = 0;//控制界面
	initgraph(640, 360);//初始化窗口
	clock_t start,end;//生成时间变量
	//通过改变judge的值实现界面之间的相互切换，切换是通过清屏再显示的方式实现
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
				//切到登录界面时清空用户名和密码，以及重置其他有关登录界面变量
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
				//切到注册界面时清空用户名和密码，以及重置其他有关注册界面变量
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
				cout << "文件打开失败" << endl;
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
				//进入答题界面就再次刷新题库
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