//
// Created by Dan Elias on 19/07/2025.
//

#include "logger.h"
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>

static int msgId; // so ID is constant
pthread_mutex_t mutex;

void logger_start() {
    msgId = 0;
    pthread_mutex_init(&mutex, NULL);
 }

void logger_stop() {
    pthread_mutex_destroy(&mutex);
}

void logger_log(char const* msg) {
  struct timeval currentTime;
  pthread_mutex_lock(&mutex);
  gettimeofday(&currentTime, NULL);
  time_t timeval = (time_t)currentTime.tv_sec;
  struct tm* timeInfo = localtime(&timeval);
  char timeString[20];
  strftime(timeString, 20, "%H:%M:%S", timeInfo);
  fprintf(stdout, "%d : [%s] : %s\n", msgId, timeString, msg);
  msgId++;
  pthread_mutex_unlock(&mutex);
}