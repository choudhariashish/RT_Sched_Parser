/*
 * RT_Sched_Parser.cpp
 *
 *  Created on: Mar 16, 2013
 *      Author: ashish
 */
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>

#include "RT_Sched_Parser.h"

using namespace std;

PRINT_TASK::PRINT_TASK(char* _OFileName, int _nOfTasks)
{
	FILE* _OFile = fopen(_OFileName, "w");

	OFileName = _OFileName;
	OFile = _OFile;

	nOfTasks = _nOfTasks;

	initializeAllTasksToPrint();
}

PRINT_TASK::~PRINT_TASK()
{
	fclose(OFile);

	system("drawtiming --output out.gif otpt.txt");
}

void PRINT_TASK::initializeAllTasksToPrint()
{
	for(int i=1;i<=nOfTasks;i++)
	{
		fprintf (OFile, "TASK_%d=0, ",i);
	}
	fprintf (OFile, " Time=\"0\".");
}

void PRINT_TASK::printSchedTask(int _tid, int _t)
{
	fprintf(OFile, "\nTASK_%d=1.",_tid);
	for(int i=1;i<=nOfTasks;i++)
	{
		if(i!=_tid)
		{
			fprintf(OFile, "\nTASK_%d=0.", i);
		}
	}
	fprintf(OFile, "\nTASK_%d=0.",_tid);
	fprintf(OFile, "\nTime=\"%d\".", _t);
}

int main()
{
	char* fileName = "otpt.txt";

	PRINT_TASK PrintTask(fileName, 3);

	PrintTask.printSchedTask(1,1);
	PrintTask.printSchedTask(2,2);
	PrintTask.printSchedTask(3,3);
	PrintTask.printSchedTask(1,4);
	PrintTask.printSchedTask(2,5);

	PrintTask.printSchedTask(1,6);
	PrintTask.printSchedTask(2,7);
	PrintTask.printSchedTask(3,8);
	PrintTask.printSchedTask(1,9);
	PrintTask.printSchedTask(2,10);

	PrintTask.printSchedTask(1,11);
	PrintTask.printSchedTask(2,12);
	PrintTask.printSchedTask(3,13);
	PrintTask.printSchedTask(1,14);
	PrintTask.printSchedTask(2,15);

	PrintTask.printSchedTask(1,16);
	PrintTask.printSchedTask(2,17);
	PrintTask.printSchedTask(3,18);
	PrintTask.printSchedTask(1,19);
	PrintTask.printSchedTask(2,20);

	PrintTask.printSchedTask(1,21);
	PrintTask.printSchedTask(2,22);
	PrintTask.printSchedTask(3,23);
	PrintTask.printSchedTask(1,24);
	PrintTask.printSchedTask(2,25);

	return 0;
}

