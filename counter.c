#include <stdio.h>
#include <stdlib.h>
#include "counter.h"

void Counter_init(Counter *self, int start, int end, int step) {
    self->start = start;
    self->end = end;
    self->step = step;
    self->count = 0;

    self->startHandler = NULL;
    self->changeHandler = NULL;
    self->finishHandler = NULL;
}

Counter* Counter_new(int start, int end, int step) {
    Counter *result = (Counter*)malloc(sizeof(Counter));
    //Counter *result = (Counter*)malloc(sizeof(*result));
    //printf("COUNTER SIZE: %lu RESULT SIZE: %lu\n", sizeof (Counter), sizeof (*result));
    if(result != NULL) {
        Counter_init(result, start, end, step);
    }
    return result;
}

void Counter_destroy(Counter *self) {
    if(self != NULL) {
        free(self);
    }
}

// start Event
void Counter_setStartHandler(Counter *self, void (*handler)(Counter *sender)) {
    self->startHandler = handler;
}

void Counter_removeStartHandler(Counter *self) {
    self->startHandler = NULL;
}

void Counter_fireStartEvent(Counter *self) {
    if(self->startHandler != NULL) {
        self->startHandler(self);
    }
}

// change Event
void Counter_setChangeHandler(Counter *self, void (*handler)(Counter *sender)) {
    self->changeHandler = handler;
}

void Counter_removeChangeHandler(Counter *self) {
    self->changeHandler = NULL;
}

void Counter_fireChangeEvent(Counter *self) {
    if(self->changeHandler != NULL) {
        self->changeHandler(self);
    }
}

// finish Event
void Counter_setFinishHandler(Counter *self, void (*handler)(Counter *sender)) {
    self->finishHandler = handler;
}

void Counter_removeFinishHandler(Counter *self) {
    self->finishHandler = NULL;
}

void Counter_fireFinishEvent(Counter *self) {
    if(self->finishHandler != NULL) {
        self->finishHandler(self);
    }
}

// getCount
int Counter_getCount(Counter *self) {
    return self->count;
}


// run
void Counter_run(Counter *self) {
    self->count = self->start;
    Counter_fireStartEvent(self);
    for(; self->count < self->end; self->count += self->step) {
        Counter_fireChangeEvent(self);
    }
    Counter_fireFinishEvent(self);
}


// print
void Counter_print(Counter *self) {
    printf("start: %d\n", self->start);
    printf("end: %d\n", self->end);
    printf("step: %d\n", self->step);
    printf("count: %d\n", self->count);
}
