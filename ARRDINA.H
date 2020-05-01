//  ---------------------------------------------------------------------
//        MODULO DE CABECERAS PARA USO DE OBJETOS EN UNA ESTRUCTURA DE
//                   ARRAY'S DINµMICOS DE UNA DIMENSI‡N
//  ---------------------------------------------------------------------
//                INSTRUCCIONES PARA LA COMPILACION;
//		1.- Defina una estructura ardi_[tip]_typo.
//		2.- Sustituya [tip] por una palabra significativa.
//  ---------------------------------------------------------------------
//	AUTOR: M¶ Jose Perez Romero - M¶ Angeles Morillo Jimenez
//	FECHA REALIZACION: 10/1/2000
//  ---------------------------------------------------------------------

#ifndef ARDI_CHAR_TYPO

#define ARDI_CHAR_TYPO

struct ardi_char_typo  {
	char x;
   };

typedef struct ardi_char_rep *ardi_char;

//  ---------------------------------------------------------------------

ardi_char ardi_char_nuev (void);

ardi_char ardi_char_const (int tamano, struct ardi_char_typo valorinicial);

ardi_char ardi_char_copy (ardi_char a, int prim, int count);

int ardi_char_tamfis (ardi_char a);

int ardi_char_tamlog (ardi_char a);

int ardi_char_infe (ardi_char a);

int ardi_char_supe (ardi_char a);

void ardi_char_obti (ardi_char a, int i, struct ardi_char_typo *e);

void ardi_char_asig (ardi_char a, int i, struct ardi_char_typo e);

void ardi_char_aumd (ardi_char a, struct ardi_char_typo e);

void ardi_char_disd (ardi_char a, struct ardi_char_typo *e);

void ardi_char_dest (ardi_char *a);

void ardi_char_swap (ardi_char a, int l, int r);

int ardi_char_bbin (ardi_char a, struct ardi_char_typo e,
	int (*cmp_char) (const void *, const void *));

int ardi_char_bsecd (ardi_char a, struct ardi_char_typo e,
	int (*cmp_char) (const void *, const void *));

int ardi_char_bseci (ardi_char a, struct ardi_char_typo e,
	int (*cmp_char) (const void *, const void *));

void ardi_char_qsort (ardi_char a, int (*cmp_char) (const void *, const void *));

#endif

//  -------------------------------------------------------------------------



