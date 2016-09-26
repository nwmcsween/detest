#include "detest.h"

int main(void)
{
	struct demeta d = { 0 };
	char r;

	detest("should fail given untrue expression", r = (1 == 2), "%d", r, &d, 0);
	detest("should succeed given a true expression", r = (1 == 1), "%d", r, &d, 0);
	detest("should not output colors", r = (2 == 2), "%d", r, &d, DE_NOCOLOR);

	return dereport(&d);
}

