#include "search_tree.h"
#include <cstdlib>
#include <stdio.h>
#include <string>


int main(int argv, char* argc[]){
	std::string str("string");
	printf("string address: %x", &str);
	printf("c_str address: %x", &str[0]);
	system("pause");
	return 0;
}