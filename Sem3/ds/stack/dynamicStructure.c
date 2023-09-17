#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct Event {
  int day;
  char *month;
  char *activity;
};

struct Event *schedule;

void initilizeSchedule() {
  schedule = (struct Event *)malloc(30 * sizeof(struct Event));
  if (schedule == NULL) {
    printf("Allocation Filed");
    exit(1);
  }
}

void addEvent(int day, char *activity, char *month) {
  if (day >= 1 && day <= 30) {
    schedule[day - 1].activity = (char *)malloc(strlen(activity) + 1);
    strcpy(schedule[day - 1].activity, activity);
    schedule[day - 1].month = (char *)malloc(strlen(month) + 1);
    strcpy(schedule[day - 1].month, month);
    schedule[day - 1].day = day;
  } else {
    printf("Invalid Day. Day must be between 1 and 30");
  }
}

void modifyEvent(int day, char *newActivity) {
  if (day >= 1 && day <= 30) {
    if (schedule[day - 1].activity) {
      free(schedule[day - 1].activity);
    }
    schedule[day - 1].activity = (char *)malloc(strlen(newActivity) + 1);
    strcpy(schedule[day - 1].activity, newActivity);
  } else {
    printf("Invalid Day");
  }
}

void displaySchedule() {
  printf("Day Month Event\n");
  for (int i = 0; i < 30; i++) {
    if (schedule[i].activity) {
      printf("%d %s %s\n", schedule[i].day, schedule[i].month,
             schedule[i].activity);
    }
  }
}

int main(int argc, char *argv[]) {
  initilizeSchedule();

  for (int i = 0; i < 30; i++) {
    schedule[i].activity = NULL;
    schedule[i].month = NULL;
  }

  addEvent(14, "Metting", "May");
  displaySchedule();
  modifyEvent(14, "Bday");
  displaySchedule();

  return 0;
}
