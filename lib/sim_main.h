/*
 * sim_main.h
 *
 * Created on: Nov 25, 2023
 * Author: Valentin Lairich
 * Author: Sami
 */

#ifndef SIM_MAIN_H_
#define SIM_MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> /* pthread */
#include <unistd.h>
#include <string.h> /* strerror */
#include <errno.h>  /* errno */

#include <thread_functions.h>

//pthread_mutex_t room_lock = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t	room = PTHREAD_COND_INITIALIZER;

pthread_mutex_t condvar_lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condvar = PTHREAD_COND_INITIALIZER;

// Struct to represent a person
typedef struct {
	pthread_mutex_t person_lock;
	int id;
	int is_in_room;
	int (*work_func)(void *);
}Person;

// Struct to represent a room
typedef struct {
	pthread_mutex_t room_lock;
	pthread_cond_t	room;
	int id;
	int person_cnt;
}Room;

#define CHECK_SUCCESS(call) \
do { int ret = call;\
	if ( ret != 0 ){\
		fprintf(stderr, "%s:%d %s failed: %s\n", __FILE__, __LINE__, #call, strerror(ret));\
		exit(1);\
	}} while(0);


#endif /* SIM_MAIN_H_ */
