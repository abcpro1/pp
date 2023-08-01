/* f-P2toRFC.c: P2 -> 822  filter */

# ifndef lint
static char Rcsid[] = "@(#)$Header: /xtel/pp/pp-beta/Format/rfc1148/RCS/f-P2toRFC.c,v 6.0 1991/12/18 20:20:34 jpo Rel $";
# endif

/*
 * $Header: /xtel/pp/pp-beta/Format/rfc1148/RCS/f-P2toRFC.c,v 6.0 1991/12/18 20:20:34 jpo Rel $
 *
 * $Log: f-P2toRFC.c,v $
 * Revision 6.0  1991/12/18  20:20:34  jpo
 * Release 6.0
 *
 */



#include "head.h"
#include "q.h"

extern void	sys_init(), or_myinit();



/* ARGSUSED */
main(argc, argv)
char    **argv;
int     argc;
{
	sys_init(argv[0]);
	or_myinit ();

	if (P2toRFC (NULLCP, NULLCP, (Q_struct *) 0, NULLCP, NULLCP, 0) != OK)
	{
		fprintf (stderr, "P2 to RFC mapping failed\n");
		exit (-1);
	}

}



void    advise (what, fmt, a, b, c, d, e, f, g, h, i, j)
char   *what,
       *fmt,
       *a,
       *b,
       *c,
       *d,
       *e,
       *f,
       *g,
       *h,
       *i,
       *j;
{
    (void) fflush (stdout);

    fprintf (stderr, "RFCtoP2 test");
    fprintf (stderr, fmt, a, b, c, d, e, f, g, h, i, j);
    if (what)
	(void) fputc (' ', stderr), perror (what);
    else
	(void) fputc ('\n', stderr);

    (void) fflush (stderr);
}


/* VARARGS 2 */
void    adios (what, fmt, a, b, c, d, e, f, g, h, i, j)
char   *what,
       *fmt,
       *a,
       *b,
       *c,
       *d,
       *e,
       *f,
       *g,
       *h,
       *i,
       *j;
{
    advise (what, fmt, a, b, c, d, e, f, g, h, i, j);
    _exit (1);
}
