//  ---------------------------------------------------------------------
//        MODULO EN C PARA USO DE OBJETOS EN UNA ESTRUCTURA DE
//                   ARRAY'S DINµMICOS DE UNA DIMENSI‡N
//  ---------------------------------------------------------------------
//                INSTRUCCIONES PARA LA COMPILACION;
//		1.- Sustituya [tip] por una palabra significativa.
//  ---------------------------------------------------------------------
//	AUTOR: M¶ Jose Perez Romero - M¶ Angeles Morillo Jimenez
//	FECHA REALIZACION: 10/1/2000
//  ---------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <mem.h>
#include <math.h>
#include "arrdina.h"

struct ardi_char_rep   {
	int tamfis;
	int tamlog;
	struct ardi_char_typo *arr;
   };

//  ---------------------------------------------------------------------
//               	FUNCIONES PRIVADAS
//  ---------------------------------------------------------------------

void ardi_char_error (int error, char prim [20])     {

	switch (error)    {
		case 1: fprintf (stderr, "\n\t%s: Error, no hay memoria suficiente.\n", prim);
			break;
		case 2: fprintf (stderr, "\n\t%s: Error, el array no existe.\n", prim);
			break;
		case 3:	fprintf (stderr, "\n\t%s: Error, el array esta vacio.\n", prim);
			break;
		case 4:	fprintf (stderr, "\n\t%s: Error, tama§o < 1.\n", prim);
			break;
		case 5:	fprintf (stderr, "\n\t%s: Error, prim < 0.\n", prim);
			break;
		case 6:	fprintf (stderr, "\n\t%s: Error, count > elementos del array.\n", prim);
			break;
		case 7:	fprintf (stderr, "\n\t%s: Error, fuera de rango del array.\n", prim);
			break;
	  }
    }

//  ---------------------------------------------------------------------

struct ardi_char_typo *ardi_char_aloarr (int tamano)   {
	struct ardi_char_typo *arr;

	if (tamano == 0) return (NULL);
	else   {
		arr = (struct ardi_char_typo *) malloc (sizeof (struct ardi_char_typo) * tamano);
		if (arr == NULL)   {
		     ardi_char_error (1, "ardi_char_aloarr");
		     exit (1);
		   }
		return (arr);
	  }
   }

//   -------------------------------------------------------------------

ardi_char ardi_char_alo (int tamano)    {
	ardi_char p;

	p = (ardi_char) malloc (sizeof (struct ardi_char_rep));
	if (p == NULL)   {
	     ardi_char_error (1, "ardi_char_alo");
	     exit (1);
	   }

	p -> arr = ardi_char_aloarr (tamano);
	p -> tamfis = tamano;
	p -> tamlog = 0;
	return (p);
   }

//   -------------------------------------------------------------------

void ardi_char_daloarr (struct ardi_char_typo *arr)   {

	if (arr)   free (arr);
   }

//   -------------------------------------------------------------------

void ardi_char_dalo (ardi_char *p)    {

	if (*p != NULL)   {
	      ardi_char_daloarr ((*p) -> arr);
	      free (*p);
	      *p = NULL;
	 }
   }

//  ---------------------------------------------------------------------
//  		               	FUNCIONES PUBLICAS
//  ---------------------------------------------------------------------

ardi_char ardi_char_nuev ()  {
	ardi_char x;

	x = ardi_char_alo (1);
	return (x);
  }

//  ---------------------------------------------------------------------

ardi_char ardi_char_const (int tamano, struct ardi_char_typo valorinicial)   {
	ardi_char x;
	int i = 0, tamfis;

	if (tamano < 1)   {
		ardi_char_error (4, "ardi_char_const");
		exit (1);
	    }

	tamfis = (int) pow (2, ceil (log (tamano) / log (2)));
	x = ardi_char_alo (tamfis);
	while (i < tamano)     *(x -> arr+i++) = valorinicial;
	x -> tamlog = tamano;

	return (x);
  }

//  ---------------------------------------------------------------------

ardi_char ardi_char_copy (ardi_char a, int prim, int count)  {
	ardi_char x;
	int tamfis;

	if (!a)   {
		ardi_char_error (2, "ardi_char_copy");
		exit (1);
	   }
	if ((prim < 0) || (prim > a -> tamlog - 1))   {
		ardi_char_error (5, "ardi_char_copy");
		exit (1);
	   }
	if (count + prim - 1 > a -> tamlog - 1)   {
		ardi_char_error (6, "ardi_char_copy");
		exit (1);
	   }

	tamfis = (int) pow (2, ceil (log (count) / log (2)));
	x = ardi_char_alo (tamfis);
	memcpy (x -> arr, a -> arr + prim, count * sizeof (struct ardi_char_typo));
	x -> tamlog = count;

	return (x);
  }

//  ---------------------------------------------------------------------

int ardi_char_tamfis (ardi_char a)  {

	if (!a)   {
		ardi_char_error (2, "ardi_char_tamfis");
		exit (1);
	   }
	return (a -> tamfis);
   }

//  ---------------------------------------------------------------------

int ardi_char_tamlog (ardi_char a)  {

	if (!a)   {
		ardi_char_error (2, "ardi_char_tamlog");
		exit (1);
	   }
	return (a -> tamlog);
   }

//  ---------------------------------------------------------------------

int ardi_char_infe (ardi_char a)   {

	if (!a)   {
		ardi_char_error (2, "ardi_char_infe");
		exit (1);
	   }
	return (0);
   }

//  ---------------------------------------------------------------------

int ardi_char_supe (ardi_char a)   {

	if (!a)   {
		ardi_char_error (2, "ardi_char_supe");
		exit (1);
	   }
	return (a -> tamlog - 1);
   }

//  ---------------------------------------------------------------------

void ardi_char_obti (ardi_char a, int i, struct ardi_char_typo *e)     {

	if (!a)   {
		ardi_char_error (2, "ardi_char_obti");
		exit (1);
	   }
	if ((i < 0) || (i > a -> tamlog - 1))   {
		ardi_char_error (7, "ardi_char_obti");
		exit (1);
	   }

	*e = a -> arr [i];
  }

//  ---------------------------------------------------------------------

void ardi_char_asig (ardi_char a, int i, struct ardi_char_typo e)    {

	if (!a)   {
		ardi_char_error (2, "ardi_char_asig");
		exit (1);
	   }
	if (i < 0 || i > a -> tamlog - 1)   {
		ardi_char_error (7, "ardi_char_asig");
		exit (1);
	   }

	a -> arr [i] = e;
   }

//  ---------------------------------------------------------------------

void ardi_char_aumd (ardi_char a, struct ardi_char_typo e)   {
	struct ardi_char_typo *b;

	if (!a)   {
		ardi_char_error (2, "ardi_char_aumd");
		exit (1);
	   }

	if (!a -> tamlog)    *(a -> arr) = e;
	else if ((a -> tamlog) < (a -> tamfis))    a -> arr [a -> tamlog] = e;
	else   {
		b = ardi_char_aloarr (a -> tamfis * 2);
		memcpy (b, a -> arr, a -> tamfis * sizeof (struct ardi_char_typo));
		b [a -> tamlog] = e;
		ardi_char_daloarr (a -> arr);
		a -> arr = b;
		a -> tamfis *= 2;
	  }
	a -> tamlog++;
   }

//  ---------------------------------------------------------------------

void ardi_char_disd (ardi_char a, struct ardi_char_typo *e)   {
	struct ardi_char_typo *b;

	if (!a)   {
		ardi_char_error (2, "ardi_char_disd");
		exit (1);
	   }
	if (!a -> tamlog)   {
		ardi_char_error (3, "ardi_char_disd");
		exit (1);
	   }

	*e = a -> arr [a -> tamlog - 1];
	a -> tamlog--;

	if (a -> tamlog < (a -> tamfis / 2))   {
		b = ardi_char_aloarr (a -> tamfis / 2);
		memcpy (b, a -> arr, (a -> tamfis / 2) * sizeof (struct ardi_char_typo));
		ardi_char_daloarr (a -> arr);
		a -> arr = b;
		a -> tamfis /= 2;
	   }
   }

//  ---------------------------------------------------------------------

void ardi_char_dest (ardi_char *a)   {

	if (!*a)   {
		ardi_char_error (2, "ardi_char_dest");
		exit (1);
	   }
	ardi_char_dalo (a);
   }

//  --------------------------------------------------------------------

void ardi_char_swap (ardi_char a, int l, int r)   {
	struct ardi_char_typo aux;

	if (!a)   {
		ardi_char_error (2, "ardi_char_swap");
		exit (1);
	   }
	if (!a -> tamlog)   {
		ardi_char_error (3, "ardi_char_swap");
		exit (1);
	   }
	if (l < 0 || l > a -> tamlog - 1 || r < 0 || r > a -> tamlog - 1)   {
		ardi_char_error (7, "ardi_char_swap");
		exit (1);
	   }
	aux = a -> arr [l];
	a -> arr [l] = a -> arr [r];
	a -> arr [r] = aux;
   }

//  ---------------------------------------------------------------------

int ardi_char_bbin (ardi_char a, struct ardi_char_typo e,
			int (*cmp_char) (const void *, const void *))   {
	struct ardi_char_typo *t;

	if (!a)   {
		ardi_char_error (2, "ardi_char_bbin");
		exit (1);
	   }
	if (!a -> tamlog)   {
		ardi_char_error (3, "ardi_char_bbin");
		exit (1);
	   }

	t = (struct ardi_char_typo *) bsearch (&e, a -> arr, a -> tamlog,
		sizeof (struct ardi_char_typo), cmp_char);

	if (!t)   return (-1);
	else   return (t - a -> arr);
   }

//  ---------------------------------------------------------------------

int ardi_char_bsecd (ardi_char a, struct ardi_char_typo e,
			int (*cmp_char) (const void *, const void *))   {
	int i;

	if (!a)   {
		ardi_char_error (2, "ardi_char_bsecd");
		exit (1);
	   }

	if (a -> tamlog)
		for (i = a -> tamlog - 1; i >= 0; i--)
		      if (!cmp_char (&(a -> arr [i]), &e))    return (i);
	return (-1);
   }

//  ---------------------------------------------------------------------

int ardi_char_bseci (ardi_char a, struct ardi_char_typo e,
			int (*cmp_char) (const void *, const void *))    {
	int i;

	if (!a)   {
		ardi_char_error (2, "ardi_char_bseci");
		exit (1);
	   }

	if (a -> tamlog)
		for (i = 0; i <= a -> tamlog - 1; i++)
		      if (!cmp_char (&(a -> arr [i]), &e))    return (i);
	return (-1);
   }

//  ---------------------------------------------------------------------

void ardi_char_qsort (ardi_char a, int (*cmp_char) (const void *, const void *))   {

	if (!a)   {
		ardi_char_error (2, "ardi_char_qsort");
		exit (1);
	   }
	if (!a -> tamlog)   {
		ardi_char_error (3, "ardi_char_qsort");
		exit (1);
	   }

	qsort (a -> arr, a -> tamlog, sizeof (struct ardi_char_typo), cmp_char);
  }

//  ------------------------------------------------------------------

