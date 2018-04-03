#include "HelloWorld.h"
#include <iostream>

void HelloWorld::hello() {
  std::cout << "Hello World!" << std::endl;
}

int main(){
	HelloWorld hw;
	hw.hello();
	return 0;
}
