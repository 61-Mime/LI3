#ifndef __runquerie_h
#define __runquerie_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "sgv.h"
#include "querie.h"
#include "apresentacao.h"

int temEspaco(char* s);
SGV runQuerie1e13(SGV sgv, char* buffer, char*aux, int load);
void runQuerie2(SGV sgv);
void runQuerie3(SGV sgv, char* buffer);
void runQuerie4(SGV sgv, char* buffer);
void runQuerie5(SGV sgv, int tam);
void runQuerie6(SGV sgv, int tam);
void runQuerie7(SGV sgv, char* buffer);
void runQuerie8(SGV sgv, char* buffer);
void runQuerie9(SGV sgv, char* buffer);
void runQuerie10(SGV sgv, char* buffer);
void runQuerie11(SGV sgv, char* buffer);
void runQuerie12(SGV sgv, char* buffer);
void runQuerie13(SGV sgv, char* buffer, int tam);

#endif
