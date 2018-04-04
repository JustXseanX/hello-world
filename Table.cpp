#include <iostream>
#include <string.h>
using namespace std;

class Table{
	public:
		Table();
		Table(int, int);
		void show();
		void addRow();
		void addColumn();
		void set(int ,int ,int);
		void set(int ,int ,char s[20]);
		void delRow(int);
		void delColumn(int);
	private:
		char a[100][100][20];
		int row, col;
		
};

int main() {
  Table tb;
  tb.show();
  tb.addRow();
  tb.show();
  tb.addColumn();
  tb.show();
  Table tb1(5,5);
  tb1.show();
  tb1.set(1,1,30);
  tb1.set(2,2,"hello");
  tb1.show();
  tb1.delRow(1);
  tb1.show();
  tb1.delColumn(1);
  tb1.show();
  return 0;
}

Table::Table(){
	col = 1;
	row = 1;
	
	strcpy(a[0][0], "NULL");
} 

Table::Table(int coln, int rown){
	col = coln;
	row = rown;
	
	for(int i = 0; i < col; i++){
		for(int j = 0; j < row; j++){
			strcpy(a[i][j], "NULL");
		}
	}
}

void Table::show(){
	cout<<'-';
	for(int k = 0; k < row; k++){
		cout<<"--------";
	}
	cout<<endl;
	for(int i = 0; i < col; i++){
		cout<<'|';
		for(int j = 0; j < row; j++){
			cout<<a[i][j]<<"\t"<<'|';
		}
		cout<<endl;
		
		cout<<'-';
		for(int k = 0; k < row; k++){
		cout<<"--------";
		}
		cout<<endl;
	}
}

void Table::addRow(){
	row++;
	for(int i = 0; i < col; i++){
		strcpy(a[i][row - 1], "NULL");
	}
}
void Table::addColumn(){
	col++;
	for(int j = 0; j < row; j++){
		strcpy(a[col - 1][j], "NULL");
	}
}
void Table::set(int coln, int rown, int value){
	char *p = a[coln - 1][rown - 1];
	int count = 0;
	int t = value;
	if (value == 0){
		*p = '0';
		*(p + 1) = '\0';
	}
	else{
		while(t != 0){
			count++;
			t /= 10;
		}
	}
	*(p + count) = '\0';
	while(1){
		count--;
		*(p + count) = value % 10 +'0';
		value /= 10;
		if(count == 0) break;
	}
	
}
void Table::set(int coln, int rown, char s[20]){
	char *p = a[coln - 1][rown - 1];
	char *q = s;
	while(1){
		*p = *q;
		if (*q == '\0') break;
		p++;q++;
	}
}
void Table::delRow(int num){
	for(int i = 0; i < col; i++){
		for(int j = num - 1; j < row - 1; j++){
			strcpy(a[i][j], a[i][j + 1]);
		}
	}
	row--;
}
void Table::delColumn(int num){
	for(int i = num - 1; i < col - 1; i++){
		for(int j = 0; j < row; j++){
			strcpy(a[i][j], a[i + 1][j]);
		}
	}
	col--;
}
