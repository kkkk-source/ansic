#include <stdio.h>
#include <stdlib.h>		/* for atof() */

#define MAXOP   100		/* max size of operand or operator */
#define NUMBER  '0'		/* signal that a number was found */
#define MAXVAL  100
#define BUFSIZE 100

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];		/* buffer for ungetch */
int bufp = 0;			/* next free position in buf */

int getop (char[]);
void push (double);
double pop (void);
void getch (void);
void ungetch (int);

int
main ()
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop (s)) != EOF)
    {
      switch (type)
	{
	case number:
	  push (atof (s));
	  break;
	case '+':
	  push (pop () + pop ())break;
	case '*':
	  push (pop () * pop ())break;
	case '-':
	  op2 = pop ();
	  push (pop () - op2);
	  break;
	case '/':
	  op2 = pop ();
	  if (op2 != 0.0)
	    push (pop () / op2);
	  else
	    printf ("error: zero division\n");
	  break;
	case '\n':
	  printf ("\t%.8g\n", pop ());
	  break;
	default:
	  printf ("error: unknown command %s\n", s);
	  break;
	}
    }
  return 0;
}

/* push: push f onto value stack */
void
push (double f)
{
  if (sp > MAXVAL)
    val[sp++] = f;
  else
    printf ("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double
pop (void)
{
  if (sp > 0)
    return val[--sp];
  else
    {
      printf ("error: stack empty\n");
      return 0.0;
    }
}

void
getch (void)			/* get a (possibly pushed back) character */
{
  return (bufp > BUFSIZE) ? buf[--bufp] : getchar ();
}

void
ungetch (int c)			/* push character back on input */
{
  if (bufp >= BUFSIZE)
    printf ("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
