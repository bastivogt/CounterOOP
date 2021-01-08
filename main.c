#include <stdio.h>
#include <stdlib.h>
#include "counter.h"


void onStart(Counter *sender) {
    printf("ON_START count: %d\n", Counter_getCount(sender));
}

void onChange(Counter *sender) {
    printf("ON_CHANGE count: %d\n", Counter_getCount(sender));
}

void onFinish(Counter *sender) {
    printf("ON_FINISH count: %d\n", Counter_getCount(sender));
}


int main()
{
    Counter counter_1;
    Counter_init(&counter_1, 0, 10, 1);
    Counter_setStartHandler(&counter_1, onStart);
    Counter_setChangeHandler(&counter_1, onChange);
    Counter_setFinishHandler(&counter_1, onFinish);
    Counter_run(&counter_1);
    Counter_print(&counter_1);

    printf("----------------------------------------------------------------------\n");

    Counter *counter_2 = Counter_new(0, 20, 2);
    Counter_setStartHandler(counter_2, onStart);
    Counter_setChangeHandler(counter_2, onChange);
    Counter_setFinishHandler(counter_2, onFinish);
    Counter_run(counter_2);
    Counter_print(counter_2);

    Counter_destroy(counter_2);
    return 0;
}





