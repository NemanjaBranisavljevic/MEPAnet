#ifndef __MEpanet__
#define __MEpanet__

#ifndef __epanet2__
#include "epanet2.h"
#endif

// Definicije varijabli za kompilacije raznih funkcija
// iz jednog MEpanet.c file-a

// #define SILENT	  FALSE	// Print input parameters
// #define SILENT	  TRUE	// Print input parameters

#define FunENopen True
#define FunENclose FALSE
#define FunENgetnodeindex FALSE
#define FunENgetnodeid FALSE
#define FunENgetnodetype FALSE
#define FunENgetnodevalue FALSE
#define FunENgetlinkindex FALSE
#define FunENgetlinkid FALSE
#define FunENgetlinktype FALSE
#define FunENgetlinknodes FALSE
#define FunENgetlinkvalue FALSE
#define FunENsetnodevalue FALSE
#define FunENsetlinkvalue FALSE
#define FunENsolveH FALSE
#define FunENopenH FALSE
#define FunENinitH FALSE
#define FunENrunH FALSE
#define FunENnextH FALSE
#define FunENcloseH FALSE
#define FunENgetcount FALSE
#define FunENgetflowunits FALSE

#endif
