/**********************************************************
 *	Author: Bombbeard
 * 	Filename: topicTimer_cmd.c
 *	Date:	5/21/16
 *	Purpose: commandline interface for timing topic 
			 discussions.
 *********************************************************/
  
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "topicStructure.h"
#define MAX_FILENAME_LENGTH 35

/*	Function Declarations */
int WriteTopicTime( char toWrite[], char FileName[]);
void UpdateScreen(Topic topic[], int cnt, time_t baseTime, int numTopics);
void Help();

/*	Begin Main	*/
int main(int argc, char *argv[]){
	FILE *fp;	/*	file pointer; for file IO	*/
	time_t baseTime = (time_t)0.0, pauseDeltaTime = (time_t)0.0; 
	time_t startTime = (time_t)0.0, endTime = (time_t)0.0;
	struct tm *timeInfo;/*	required for formatted string output	*/
	int cnt = 0, numTopics = 0;
	char buf1[20], buf2[20];
	char bufOut[100];
	/*	used to open a file in append mode	*/
	char openOption[2] = "a";
	/*	stores user input	*/
	char input[MAX_TOPIC_LENGTH];
	char fileName[MAX_FILENAME_LENGTH];
	/*	store topics and their associated timestamps	*/
	Topic topics[MAX_TOPICS];
	InitTopic( topics );
	if( argc != 2 ){/*	default fileName	*/
		time( &pauseDeltaTime );
		timeInfo = gmtime( &pauseDeltaTime );
		strftime(fileName, 35, "%m-%d-%y__%H-%M-%S.txt", timeInfo);
	}else{/*	specified filename	*/
		sprintf(fileName, "%s.txt", argv[1]); 
	}/*	end filename handling	*/
	
	/*	Begin user input	*/
	printf("Please enter topic names\n");
	printf("TopicTimer> ");
	scanf( "%s", input);
	while( cnt < MAX_TOPICS){/*	taking input of topics	*/
		if( input == NULL || ((strcmp(input, "\n") == 0) && numTopics == 0 )){
			printf("Please enter first topic\n");
			printf("TopicTimer> ");
			scanf( "%s", input);
		}else if( strcmp(input, "done") == 0 ){
			break;
		}else{
			AddTopic( topics, input, numTopics);
			numTopics++;
			cnt++;
			printf("TopicTimer> ");
			scanf( "%s", input);
		}
	}
	cnt = 0;
	fflush(stdin);	/*	clean, unfettered stdin	*/
	printf("Press Return to begin '%s'\n", topics[0].topicName);
	while( cnt < numTopics ){/*	keeping track of inputs during discussion */
		printf("TopicTimer> ");
		fgets( input, 10, stdin);
		if( strcmp(input, "\n") == 0 ){
			if(cnt == 0 && (strcmp( topics[cnt].startTime_s,"99:99:99") == 0 )){
				// printf("\n%-30s%-12s%-12s%-12s\n","TopicName", "Start",
						// "End", "Delta");
				// printf(
				// "------------------------------------------------------------------\n");
				/*	beginning the timer	*/
				time(&baseTime);
				time( &startTime );
				SetTime( topics, cnt, baseTime, baseTime, 0);
				
				/*	temp times for end and delta	*/
				UpdateScreen(topics, cnt, baseTime, numTopics);
			}else if(cnt == numTopics-1 /*"last topic"*/){
				/*	ending the timer	*/
				time(&endTime);
				SetTime( topics, cnt, baseTime, endTime, 1);
				SetTime( topics, cnt, baseTime, endTime, 2);
				/*	buffer output for write operation to fileName.txt	*/
				sprintf(bufOut, "%-30s%-12s%-12s%-12s\n",
						topics[cnt].topicName, 
						topics[cnt].startTime_s, 
						topics[cnt].endTime_s,
						topics[cnt].deltaTime_s);
				/*	write topic to file with timestamps	*/
				WriteTopicTime(bufOut, fileName);
				PrintTopics(topics, numTopics, 0);
				//printf( "%s", bufOut );
				cnt++;
				/*	exit loop	*/
			}else{/*	default case	*/
				time(&endTime);
				SetTime( topics, cnt, baseTime, endTime, 1);
				SetTime( topics, cnt, baseTime, endTime, 2);
				/*	print Topic and times	*/
				sprintf(bufOut, "%-30s%-12s%-12s%-12s\n",
						topics[cnt].topicName, 
						topics[cnt].startTime_s, 
						topics[cnt].endTime_s,
						topics[cnt].deltaTime_s);
				if( !WriteTopicTime(bufOut, fileName)){
					printf("%s",bufOut);
				}else{
					printf("Write error on %ith Topic\n", cnt);
				}
				cnt++;
				/*	set begin time of next topic 	*/
				time(&startTime);
				SetTime( topics, cnt, baseTime, startTime, 0);
				UpdateScreen(topics, cnt, baseTime, numTopics);
			}
		/*	more to add for interactivity	*/
		}else if((strcmp(input, "pause\n")==0) || (strcmp(input, "p\n")==0)){
			printf("pausing\n");
		}else if((strcmp(input, "resume\n")==0) || (strcmp(input, "r\n")==0)){
			printf("resuming\n");
		}else if((strcmp(input, "list\n")==0) || (strcmp(input, "l\n")==0)){
			printf("********************************************************************\n");
			printf("\n\nList of topic names & current status of working topic\n\n");
			PrintTopicNames( topics, numTopics);
			UpdateScreen(topics, cnt, baseTime, numTopics);
			printf("********************************************************************\n");
		}else if((strcmp(input, "help\n")==0) || (strcmp(input, "h\n")==0)){
			Help();
		}else if((strcmp(input, "update\n")==0) || (strcmp(input, "u\n")==0)){
			printf("\n\n");
			UpdateScreen(topics, cnt, baseTime, numTopics);
			printf("\n\n");
		}else{
			printf("How did you get here?....\n");
		}/*	end input handling	*/
	}/*	end active timing	*/
	printf("TopicTimer finished.\nPress enter to exit.");
	fgets(input, 20, stdin);
	/*	end user input	*/
	return 0;
}/*	end main	*/

void Help(){
	printf(
	" ***********************************************************\n");
	printf(" *\tTopic Timer\n");
	printf(" *\tAuthor: BombBeard\n");
	printf(" *\tUsage: topicTimer.exe <outputFileName>\n");
	printf(" *\tNotes:\n");
	printf(" *\tDuring execution you may enter commands;\n");
	printf(" *\t'list' or 'l': \n");
	printf(" *\t\tUpdate current topic's end and delta.\n");
	printf(" *\t<return>: \n");
	printf(" *\t\tFinalize end and delta times for current \n");
	printf(" *\t'help' or 'h': \n");
	printf(" *\t\tBrings up this message.\n");
	printf(" *\t\ttopic, and set current topic to next topic.\n");
	printf(" *\tIf no OutputFileName is given, the default file \n");
	printf(" *\tname is 'date_time.txt'\n");
	printf(
	" ***********************************************************\n");
}

void UpdateScreen(Topic topic[], int cnt, time_t baseTime, int numTopics){
	/*	Update the values of the currently timed topic.
		This isn't meant to be the final value, but an 
		in-progress value assignment.	*/
	time_t curTime;
	time( &curTime );
	SetTime(topic, cnt, baseTime, curTime, 1);
	SetTime(topic, cnt, baseTime, curTime, 2);
	printf("\n\nCurrent topic:\t%s\n",topic[cnt].topicName);
	PrintTopics( topic, numTopics, cnt+1);
}

int WriteTopicTime( char toWrite[], char FileName[]){
	/******************************************************
	 *	Wrapper for fopen(), fputs(), and fclose()
	 *	Opens FileName in append mode, writes string to 
	 *	File and closes it.
	 *****************************************************/
	FILE *fp;
	char openOption[2] = "a";
	/*	Open file	*/
	if((fp = fopen( FileName, openOption ))==NULL){
		printf("Error opening %s\n", FileName);
		return 1;
	}
	/*	Write to file	*/
	fputs(toWrite, fp);
	/*	Close file	*/
	fclose(fp);
	return 0;
}