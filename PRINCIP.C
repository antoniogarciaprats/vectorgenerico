//  ------------------------------------------------------------------
//		             PROGRAMA PRINCIPAL
//  ------------------------------------------------------------------

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include "arrdina.h"

//  ------------------------------------------------------------------

int cmp_char (const void *a, const void *b)   {
	return (strcmp ((char *) a, (char *) b));
    }

//  ------------------------------------------------------------------

void mostrar_linea (ardi_char array)     {
	struct ardi_char_typo e;
	int i = 0;

	while (i < ardi_char_tamlog (array))     {
	       ardi_char_obti (array, i, &e);
	       i++;
	       printf ("%c", e.x);
	   }
   }

//  ------------------------------------------------------------------

void buscar_palabra (ardi_char array, char *argv [], int linea)     {
	struct ardi_char_typo e;
	int num = 0, i = 0, j = 0;
	char cadena [20], fin;

	while (i < ardi_char_tamlog (array))     {
	       ardi_char_obti (array, i, &e);
	       i++;
	       if ((e.x != ' ') && (e.x != '\n') && (e.x != '.') &&
		   (e.x != ',') && (e.x != ':') && (e.x != ';'))    {
		      cadena [j] = e.x;
		      j++;
		  }
	       else   {
		      cadena [j] = '\0';
		      j = 0;
		      if (cmp_char (cadena, argv [2]) == 0)   num++;
		 }
	  }
	if (num)    {
		printf ("\t La palabra '%s' aparece %d veces en la linea %d, igual a:\n", argv [2], num, linea);
		mostrar_linea (array);
		printf ("\nPulse una tecla para continuar: ");
		fin = getch ();
		clrscr ();
	   }
   }

//  ------------------------------------------------------------------

void fichero_array (char *argv [])   {
	FILE *fp;
	ardi_char array;
	struct ardi_char_typo e;
	int linea = 1;
	char c;

	if ((fp = fopen (argv [1], "rt")) == NULL)    {
		fprintf (stderr, "Fichero_array: El fichero %s no existe.\n", argv [1]);
		exit (1);
	   }

	array = ardi_char_nuev ();

	while ((c = fgetc (fp)) != EOF)  {
		e.x = c;
		ardi_char_aumd (array, e);
		if (c == '\n')    {
			buscar_palabra (array, argv, linea);
			linea++;
			ardi_char_dest (&array);

			array = ardi_char_nuev ();
		   }
	   }

	ardi_char_dest (&array);
	fclose (fp);
   }

//  -------------------------------------------------------------------------

void main (int argc, char *argv [])     {
	char fin;

	if (argc != 3)	{
		fprintf (stderr, "Error: N£mero de par metros incorrecto.\n");
		fprintf (stderr, "Uso: programa <fichero> <palabra a buscar>\n");
		exit (1);
	   }

	fichero_array (argv);

	printf ("\nLa b£squeda ha finalizado.");
	printf (" Pulse una tecla para finalizar.");
	fin = getch ();
	clrscr ();
   }

//  -------------------------------------------------------------------------