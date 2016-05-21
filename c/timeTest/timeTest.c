#include <stdio.h>
#include <time.h>
#include <signal.h>

int main(int argc, char *argv[]){
	time_t startTime, time1, time2;
	struct tm *timeInfo;
	double diff_t;
	char buf1[20], buf2[20];
	int sleepTime;
	time(&startTime);
	time1 = 0.0;
	//if(argc != 2){printf("usage: <timeToWait>"); return(1);}
	sleepTime = 5;
	sleep(sleepTime);
	time(&time2);
	time2 = difftime(time2,startTime);
	timeInfo = gmtime( &time1 );
	strftime(buf1, 20, "%H:%M:%S", timeInfo);
	timeInfo = gmtime( &time2 );
	strftime(buf2, 20, "%H:%M:%S", timeInfo);
	
	printf("Start time:  %s\tEnd time:  %s\n",buf1,buf2);
	
	return 0;
}