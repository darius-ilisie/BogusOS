#include "hal.h"
#include "idt.h"

#include <include/stdio.h>


void initHAL() {
    initIDT();
    initIO();
}