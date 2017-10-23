#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <fstream>
using namespace std;

void docfile(ifstream &f)
{
		cout<<"Bat dau doc file"<<endl;
		while(!f.eof())
		{
		string s[10], ss[10], sss[10];
		fflush(stdin);
		int n=0, m=0, i=0;
		//bat dau doc
		getline(f,s[0],'\n'); //doc id
		getline(f,s[1],'\n'); //doc title
		getline(f,s[2]); // doc magazine
		f>>s[3]; // doc type
		f>>s[4]; // doc issue
		f>>s[5]; // doc volume
		f>>s[6]; // doc year
		f>>s[7]; // doc publisher
		
		f>>n; // doc so tac gia
		for(int i=0;i<n;i++)
			getline(f,ss[i],'|');
		f>>m; //doc so dong tac gia
		for(int j=0;j<m;j++)
			getline(f,sss[j],'|');
		string temp; //xuong hang
		getline(f,temp,'\n');
		
		
		//f.seekg(3,ios::end);
		for(int i=0; i<8; i++)
		{
			cout<<s[i]<<endl;
		}
		for(int j=0; j<n; j++)
		{
			cout<<ss[j]<<endl;
		}
		for(int j=0; j<m; j++)
		{
			cout<<sss[j]<<endl;
		}
		cout<<"++++++++"<<endl;
	}
}
int main()
{
	ifstream f;
	f.open("data.txt");
	docfile(f);
	f.close();
	return 0;
}
