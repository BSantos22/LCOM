#ifndef __TEST5_H
#define __TEST5_H

#include <minix/syslib.h>
#include <minix/drivers.h>
#include <machine/int86.h>
#include <minix/sysutil.h>
#include <minix/com.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "timer.h"
#include "kbd.h"
#include "vbe.h"
#include "sprite.h"
#include "vector.h"


void move_and_shoot();
void move();
void shoot();

#endif
