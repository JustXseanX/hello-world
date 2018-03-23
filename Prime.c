/*满足下列条件的自然数称为超级素数:该数本身,所有数字之和,所有数字之积以及所有数字的平方和都是素数.例如113就是一个超级素数.求[100,9999]之内:(1)超级素数的个数.(2)所有超级素数之和.(3)最大的超级素数.*/
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
