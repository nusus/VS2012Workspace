#pragma once 
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int ReplaceBlankImpl(char* new_str, int count, const char* str="%20"){
	int str_count = strlen(str);
	for (int i=0;i<str_count;++i)
	{
		new_str[--count] = str[str_count-1-i];
	}
	return count;
}

void ReplaceBlank(const char* src, int count){
	int space_count = 0;
	for(int i=0;i<count;++i){
		if(src[i] == ' ') ++space_count;
	}
	int new_str_count =count + 2 * space_count;
	char* new_str = (char*)malloc(sizeof(char) * ( new_str_count +1));
	new_str[new_str_count] = '\0';
	while(count>0){
		if(src[--count] == ' '){
			new_str_count = ReplaceBlankImpl(new_str, new_str_count);
			--space_count;
		}else
		{
			new_str[--new_str_count] = src[count];
		}
	}
	getchar();
}