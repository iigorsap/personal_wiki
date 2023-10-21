// Create by Igor Santiago Almeida Paixão - 19.1.4033 on 10/2021.

#ifndef SEQUENTIAL_ACESS_H
#define SEQUENTIAL_ACESS_H

#include "statistic.h"
#include "page_index.h"
#include "registry.h"

int searchASI(PageIndex *tab, int tam, Registry *regs, FILE *arq, int ordenacao, Statistic *est);

#endif 