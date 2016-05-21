/**********************************************************
 *	Author: Bombbeard
 * 	Filename: topicStructure.h
 *	Date:	5/21/16
 *	Purpose: commandline interface for timing topic discussions
 *********************************************************/

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>

#define MAX_TOPIC_LENGTH 50
#define MAX_TOPICS 10

/*	Defining the data structure to group associated
	data together	*/
struct Topic{
	char topicName[MAX_TOPIC_LENGTH];
	/*	deltaTime refers to the time elapsed from start
		to end	*/
	time_t startTime_t, endTime_t, deltaTime_t;
	char startTime_s[20], endTime_s[20], deltaTime_s[20];
};
/*	typedef allows us to refer to a given data structure
	with a more meaningful name. Without this typedef, we 
	would be forced to type: struct Topic <varName>	*/
typedef struct Topic Topic;

/*	Initialize the various values to meaningful values;
	helps avoid unexpected behavior	*/
void InitTopic(Topic topic[]){
	int i=0;
	while(i < MAX_TOPICS){
		strcpy(topic[i].topicName, "000");
		topic[i].startTime_t = (time_t)0.0; 
		topic[i].endTime_t = (time_t)0.0;
		topic[i].deltaTime_t = (time_t)0.0;
		strcpy(topic[i].startTime_s, "99:99:99");
		strcpy(topic[i].endTime_s, "99:99:99");
		strcpy(topic[i].deltaTime_s, "99:99:99");
		i++;
	}
}

/*	Error checking against newline as a name and so 
	we don't exceed the array's limit	*/
int AddTopic( Topic topics[], char *topicName, int numTopics){
	if( numTopics < MAX_TOPICS  &&  (strcmp(topicName, "\n") != 0)  ){
		sprintf(topics[numTopics].topicName, "%s" , topicName);
		return 0;
	}else{ return -1;}
}

/*	Prints out all the topics and their timestamps	*/
void PrintTopics( Topic topics[], int numTopics, int numToPrint){
	int i=0;
	if( numToPrint == 0){numToPrint = numTopics;}
	printf("\n%-30s%-12s%-12s%-12s\n","TopicName", "Start",
			"End", "Delta");
	printf(
	"------------------------------------------------------------------\n");
	while( (i < numTopics) && (i < numToPrint) ){
		printf("%-30s%-12s%-12s%-12s\n",
				topics[i].topicName, 
				topics[i].startTime_s, 
				topics[i].endTime_s,
				topics[i].deltaTime_s);
		i++;
	}
	printf("\n");
}

void PrintTopicNames( Topic topic[], int numTopics ){
	if( numTopics != 0 ){
		int i = 0;
		while(i < numTopics){
			printf("Topic #%i:\t%s\n", i, topic[i++].topicName);
		}
		printf("\n");
	}
}

/*	Given the starting time of the application(baseTime),
	and the current time(curTime): 
	(flg == 0 or 1) assign to startTime_* or endTime_* the 
	relative time elapsed from the beginning of the program
	to the current time.
	(flg == 2 ) assign to deltaTime_* the relative time elapsed from the
	startTime_t to the endTime_t	*/
void SetTime( Topic topic[], int i, time_t baseTime, 
				time_t curTime, int flg){
	struct tm *timeInfo;
	char buf[20];
	
	/*	switch | case statement:
		switch(<Integer>): switch tells the program to check
		the value or expression <Intger>.
		case <OtherInteger>: if <Integer> == <OtherInteger>
		then execute the given code. If 'break;' is not 
		specified, execution will continue into following
		lines of code. 'return x;' also works, though exits
		the function, and is inappropriate in a void 
		function.	*/
	switch(flg){
		case 0:
			curTime = difftime(curTime, baseTime);
			topic[i].startTime_t = curTime;
			timeInfo = gmtime( &curTime );
			strftime(buf, 20, "%H:%M:%S", timeInfo);
			strcpy( topic[i].startTime_s, buf );
			break;
		case 1:
			curTime = difftime(curTime, baseTime);
			topic[i].endTime_t = curTime;
			timeInfo = gmtime( &curTime );
			strftime(buf, 20, "%H:%M:%S", timeInfo);
			strcpy( topic[i].endTime_s, buf );
			break;
		case 2:
			curTime = difftime(	topic[i].endTime_t, 
								topic[i].startTime_t );
			topic[i].deltaTime_t = curTime;
			timeInfo = gmtime( &curTime );
			strftime(buf, 20, "%H:%M:%S", timeInfo);
			strcpy( topic[i].deltaTime_s, buf );
			break;
		default: printf("SetTime(): Error during time assignment.\n");
	}
}