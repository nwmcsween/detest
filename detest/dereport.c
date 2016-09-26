#include "detest.h"

int dereport(struct demeta *dm)
{
	deiop("Results:\n\tSucceeded: %u\n\tFailed: %u\n", dm->succeeded, dm->failed);

	return dm->failed ? dm->failed : 0;
}

