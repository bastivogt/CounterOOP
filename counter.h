#include <stdio.h>
#include <stdlib.h>

#ifndef COUNTER_H
#define COUNTER_H
struct CounterStruct {
    int start;
    int end;
    int step;
    int count;

    void (*startHandler)(struct CounterStruct *sender);
    void (*changeHandler)(struct CounterStruct *sender);
    void (*finishHandler)(struct CounterStruct *sender);
};

typedef struct CounterStruct Counter;


void Counter_init(Counter *self, int start, int end, int step);
Counter* Counter_new(int start, int end, int step);
void Counter_destroy(Counter *self);

void Counter_setStartHandler(Counter *self, void (*handler)(Counter *sender));
void Counter_removeStartHandler(Counter *self);
void Counter_fireStartEvent(Counter *self);

void Counter_setChangeHandler(Counter *self, void (*handler)(Counter *sender));
void Counter_removeChangeHandler(Counter *self);
void Counter_fireChangeEvent(Counter *self);

void Counter_setFinishHandler(Counter *self, void (*handler)(Counter *sender));
void Counter_removeFinishHandler(Counter *self);
void Counter_fireFinishEvent(Counter *self);

int Counter_getCount(Counter *self);
void Counter_run(Counter *self);
void Counter_print(Counter *self);
#endif // COUNTER_H
