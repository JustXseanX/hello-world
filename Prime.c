/*����������������Ȼ����Ϊ��������:��������,��������֮��,��������֮���Լ��������ֵ�ƽ���Ͷ�������.����113����һ����������.��[100,9999]֮��:(1)���������ĸ���.(2)���г�������֮��.(3)���ĳ�������.*/
#include<stdio.h>

int sum_bit(int num) {
	int sum = 0;
	while(1){
		sum += num % 10;
		num = num / 10;
		if (num == 0) break;
	}
	return sum;
}

int multi_bit(int num) {
	int multi = 1;
	while(1){
		multi *= num % 10;
		num = num / 10;
		if (num == 0) break;
	}
	return multi;
}

int square_sum_bit(int num) {
	int sqsum = 0;
	while(1){
		sqsum += pow(num % 10, 2);
		num = num / 10;
		if (num == 0) break;
	}
	return sqsum;
}

int isprime(int num) {
	for(int i = 2; i <= sqrt(num); i++){
		if (num % i == 0) return 0;
	}
	return 1;
}

int main() {
	if(isprime(113) && isprime(sum_bit(113)) && isprime(multi_bit(113)) && isprime(square_sum_bit(113)))
		printf("%d is superprime", 113);
	else
		printf("%d is not superprime", 113);
    //to do sth
}
