/*
 * sim_main.c
 *
 *  Created on: Nov 25, 2023
 *      Author: devbox
 */

#include <sim_main.h>


int init_room(Room *room, int id = 0){

	// Initialize mutex and condition variable
	pthread_mutex_init(&room->lock, NULL);
	pthread_cond_init(&room->room_notifyer, NULL);

	// Initialize other members
	room->id = id;
	room->person_cnt = 0;

	return 0;
}

int destroy_room(Room *room){

    // Destroy mutex and condition variable
    pthread_mutex_destroy(&room->lock);
    pthread_cond_destroy(&room->room_notifyer);

	return 0;
}

int init_person(Person *person, int id = 0){

	// Initialize mutex and condition variable
	pthread_mutex_init(&person->lock, NULL);

	// Initialize other members
	person->id = id;

	return 0;
}

int destroy_person(Person *person){

    // Destroy mutex and condition variable
    pthread_mutex_destroy(&person->lock);

	return 0;
}
