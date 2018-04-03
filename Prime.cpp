#include <iostream>
using namespace std;

class Prime {
	public:
		Prime(int num):mNum(num){}
		//~Prime();
		bool isPrime();
		Prime sumBit();
		Prime multiBit();
		Prime sqaureSumBit();
		
	private:
		const int mNum;
};

int main() {
	Prime pm(113);
	Prime sb = pm.sumBit();
	Prime mb = pm.multiBit();
	Prime ssb = pm.sqaureSumBit();
	if(pm.isPrime() && sb.isPrime() && mb.isPrime() && ssb.isPrime())
		cout<<113<<" is superprime"<<endl;
	else
		cout<<113<<" is not superprime"<<endl;
	return 0;
}

bool Prime::isPrime(){
	for(int i = 2; i <= mNum / 2; i++){
		if (mNum % i == 0) return false;
	}
	return true;
}

Prime Prime::sumBit(){
	int num = mNum;
	int sum = 0;
	while(1){
		sum += num % 10;
		num = num / 10;
		if (num == 0) break;
	}
	return Prime(sum);
}
	
Prime Prime::multiBit(){
	int num = mNum;
	int multi = 1;
	while(1){
		multi *= num % 10;
		num = num / 10;
		if (num == 0) break;
	}
	return Prime(multi);
}

Prime Prime::sqaureSumBit(){
	int num = mNum;
	int sqsum = 0;
	while(1){
		sqsum += (num % 10) * (num % 10);
		num = num / 10;
		if (num == 0) break;
	}
	return Prime(sqsum);
}
	
	
	
	
	
	
	
	
	
	
