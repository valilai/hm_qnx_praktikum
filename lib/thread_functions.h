/*
 * thread_functions.h
 *
 * this is the header file for all functions that are used by the threads
 *
 * Created on: Nov 25, 2023
 * Author: 	Valentin Lairich
 * Author:	-
 * Version:	1.0
 * Updated:	Nov 25, 2023
 */

#ifndef THREAD_FUNCTIONS_H_
#define THREAD_FUNCTIONS_H_

#include <sim_main.h>
//#include <thread_functions.c>
#include <task3_waste_time.h>

void *person_thread(void* arg);
void *room_monitor_thread(void* arg);
void *person_thread_aw(void* arg);


#endif /* THREAD_FUNCTIONS_H_ */
