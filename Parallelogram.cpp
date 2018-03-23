#include<iostream>
#include<math.h>

using namespace std;
class Parallelogram {
	public:
		void input(){
			cout<<"输入两边的长和一个角度(°)："<<endl;
 			cin>>l1>>l2>>angle;
 			if (angle == 90) {
 				s = 1;
				c = 0;	//bug?
			}
			else{
				angle = angle / 180 * M_PI ;
				s = sin(angle);
				c = cos(angle);	
			}
		}
		void show(){
			int l = l1 > l2 ? l1 : l2;
			int w = l1 < l2 ? l1 : l2;

			for (int i = 0; i < l; i++) cout<< ". ";
			cout<< endl;
			for (int i = 0; i < w * s; i++) {
				for (int j = 0; j < i * c / s; j++) {
					cout<< "  ";
				}
				cout<< ". ";
				for (int j = 0; j < l - 2; j++) {
					cout<< "  ";
				}
				cout<< ". "<< endl;
			}
			for (int i = 0; i < w * c; i++) cout<< "  ";
			for (int i = 0; i < l; i++) cout<< ". ";
			cout<< endl;
		    
		}
		void area(){
			cout<< l1 * l2 * s<< endl;
		}
		void height(){
			cout<<( (l1 * s) < (l2 * s) ? l1 * s : l2 * s)<<endl;
		}
		void length(){
			cout<< 2 * (l1 + l2)<<endl;
		}
	private:
		double l1, l2;	//两边 
		double angle;	//角度 
		double s, c;
};
int main() {
  Parallelogram pg;
  pg.input();
  pg.show();
  pg.area();
  pg.height();
  pg.length();
  return 0;
}
