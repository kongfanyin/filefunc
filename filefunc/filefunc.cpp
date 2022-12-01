#define _CRT_SECURE_NO_WARNINGS 1
//����ͨ������ͬһ��������������д���ļ�����ʾ����Ļ����˵����
//����Ҫ���û�������Զ��Ŀ�����ﾵ�Ľ��࣬Ȼ�����ÿ��Ŀ���ķŴ������Ŵ��������ﾵ�Ľ������Ŀ���Ľ���
//�ó���ʹ����һЩ��ʽ���ķ�������Щ��������cout��ofstream����(�����������Ϊfout)ʱ������ͬ

#include<iostream>
#include<cstdio>
#include<fstream>


using namespace std;
const int LIMIT = 5;
void file_it(ostream &os,double fo,const double fe[],int n);
int main()
{
	ofstream fout;
	const char* fn = "ep-data.txt";
	fout.open(fn);
	if (!fout.is_open())
	{
		cout << "cant open" << fn << ".bye.\n";
		exit(EXIT_FAILURE);
	}
	double objective;
	cout << "enter the focal lenth of your telescope objective in mm\n";
	cin >> objective;
	double eps[LIMIT];
	cout << "enter the focal lengths, in mm, of" << LIMIT << "eyepieces; \n";
	for (int i = 0; i < LIMIT; i++)
	{
		cout << "eyepeice #" << i + 1<<": ";
		cin >> eps[i];
	}
	file_it(fout,objective,eps,LIMIT);
	file_it(cout,objective,eps, LIMIT);
	cout << "done\n";

	return 0;
}
void file_it(ostream &os, double fo, const double fe[], int n)
{
	ios_base::fmtflags initial;
	initial = os.setf(ios_base::fixed);//save  initail formatting state
	os.precision(0);
	os << "focal lenth of objective:" << fo << "mm.\n";
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(12);
	os << "f.l eyepieces";
	os.width(15);
	os << "magnification" << endl;
	for (int i = 0; i < n; i++)
	{
		os.width(12);
		os << fe[i];
		os.width(15);
		os << int(fo / fe[i] + 0.5) << endl;
	}
	os.setf(initial);//restore initial formatting state;

}