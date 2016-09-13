#include <stdio.h>		/* for puts,  */
#include <stdlib.h> 		/* for malloc */
#include <assert.h>		/* for assert */
#include "llist.h"		

int llDoCheck = 1;		/* set true for paranoid consistency checking */

#define doCheck(_lp) (llDoCheck && llCheck(_lp))

/* create a new list */
LList *llAlloc()
{
  LList *lp = (LList *)malloc(sizeof(LList));
  lp->first = lp->last = 0;
  doCheck(lp);
  return lp;
}

/* recycle a list, discarding all items it contains */
void llFree(LList *lp)
{
  doCheck(lp);
  llMakeEmpty(lp);
  free(lp);
}

/* Delete all elements off of the list */
void llMakeEmpty(LList *lp)
{
  LLItem *current = lp->first, *next;
  doCheck(lp);
  while (current) {
    next = current->next;
    free(current->str);
    free(current);
    current = next;
  }
  lp->first = lp->last = 0;	/* list is empty */
  doCheck(lp);
}
  
/* append a copy of str to end of list */
void llPut(LList *lp, char *s)
{
  int len;
  char *scopy;
  LLItem *i;

  doCheck(lp);
  /* w = freshly allocated copy of putWord */
  for (len = 0; s[len]; len++) /* compute length */
    ;
  scopy = (char *)malloc(len+1);
  for (len = 0; s[len]; len++) /* copy chars */
    scopy[len] = s[len];
  scopy[len] = 0;			/* terminate copy */


  /* i = new item containing s */
  i = (LLItem *)malloc(sizeof(LLItem));
  i->str = scopy;
  i->next = 0;

  /* append to end of list */
  if (lp->last) {			/* list not empty */
    lp->last->next = i;
  } else {			/* list empty */
    lp->first = i;
  }

  /* new item is last on list */
  lp->last = i;
  doCheck(lp);
}

/* print list membership.  Prints default mesage if message is NULL */
void llPrint(LList *lp, char *msg)
{
  LLItem *ip;
  int count = 1;
  doCheck(lp);
  puts(msg ? msg :" List contents:");
  for (ip = lp->first; ip; ip = ip->next) {
    printf("  %d: <%s>\n", count, ip->str);
    count++;
  }
}

/* check llist consistency */
int llCheck(LList *lp)
{
  LLItem *ip;
  ip = lp->first;
  if (!ip) 
    assert(lp->last == 0);
  else {
    for (; ip->next; ip = ip->next);
    assert(ip == lp->last);
  }
  return 0;
}
