/*
 * RT_Sched_Parser.h
 *
 *  Created on: Mar 16, 2013
 *      Author: ashish
 */

#ifndef RT_SCHED_PARSER_H_
#define RT_SCHED_PARSER_H_

#define active	1
#define idle	0

#include<fstream>
#include<stdio.h>

using namespace std;

class PRINT_TASK
{
private:
	int nOfTasks;
	char* OFileName;
	FILE* OFile;
	void initializeAllTasksToPrint(void);
public:
	PRINT_TASK(char* _OfileName, int _nOfTasks);
	~PRINT_TASK();
	void printSchedTask(int _tid, int _t);
};



#endif /* RT_SCHED_PARSER_H_ */
