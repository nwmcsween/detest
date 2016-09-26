#include <stdatomic.h>
#include <stdlib.h>

#include "detest.h"

#define UCHECK "\u2714"
#define UCROSS "\u2716"

#define AFRED "\x1b[31m"
#define AFGREEN "\x1b[32m"
#define AFYELLOW "\x1b[33m"
#define ARESET "\x1b[0m"

#define DE_NOCOLOR (1 << 3)

void deresult(const char *s, const char *ex, const char *fl, unsigned ln, struct demeta *dm, int f)
{
	const char *check = f & DE_NOCOLOR ? UCHECK : AFGREEN UCHECK ARESET,
		*cross = f & DE_NOCOLOR ? UCROSS : AFRED UCROSS ARESET,
		*result = dm->result ? dm->result : "Undefined";

	f & DE_FAIL ? atomic_fetch_add(&dm->failed, 1) : atomic_fetch_add(&dm->succeeded, 1);
	deiop("%s\t%s\n\t\tExpression: %s\n\t\tResult: %s\n\t\tAt: %s:%d\n",\
	      f & DE_FAIL ? cross : check, s, ex, result, fl, ln);

	if (f & DE_FAIL && f & DE_HARDFAIL) {
		abort();
	}
}

