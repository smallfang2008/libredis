#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "Redis.h"

int main() {
	REDIS redis = NULL;

	redis = credis_connect("192.168.7.224",6379,1000);
	if (redis == NULL)
	{
		printf("credis_connect fail\n");
		exit(-1);
	}

	char *val = NULL;
	int ret = credis_rpop(redis,"CNumCall",&val);
	if (ret >= 0)
		printf("key:ANumCall,value:%s\n",val);

	credis_close(redis);
	
	return 1;
}
