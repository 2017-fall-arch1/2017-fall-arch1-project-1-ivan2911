#ifndef llist_included		/* prevent multiple inclusion */
#define llist_included


/* a linked-list item */
typedef struct LLItem_s {
  struct LLItem_s *next; 
  char *str;
} LLItem;

/* a list of LLItems */
typedef struct {
  LLItem *first, *last;
} LList;

extern int llDoCheck;		/* set true for paranoid consistency checking */

/* create a new list */
LList *llAlloc();

/* free memory associated with a list, discarding all items it contains */
void llFree(LList *lp);

/* append a copy of str to end of list */
void llPut(LList *lp, char *s);

/* Delete all elements off of the list */
void llMakeEmpty(LList *lp);

/* print list membership.  Prints default mesage if message is NULL */
void llPrint(LList *lp, char *msg);

/* check llist consistency, always returns zero */
int llCheck(LList *lp);

#endif	/* included */
