#ifndef __apresentacao_h
#define __apresentacao_h

#include <stdio.h>
#include <time.h>
#include "querie.h"

void printQ1(clock_t start_t, clock_t end_t);
void printQ2(Q2* querie2, char letter);
void printQ3(Q3* querie3, char* prodID, int month);
void printQ4(Q4* querie4);
void printQ5(Q5* querie5);
void printQ6(Q6* querie6, clock_t start_t, clock_t end_t);
void printQ7(Q7* querie7, clock_t start_t, clock_t end_t);
void printQ8(Q8* querie8, clock_t start_t, clock_t end_t);
void printQ9(Q9* querie9, int filial, clock_t start_t, clock_t end_t);
void printQ10(Q10* querie10);
void printQ13(Q13* querie13);

#endif
