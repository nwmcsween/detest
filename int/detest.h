#ifndef DETEST_H
#define DETEST_H
#include <stdatomic.h>
#include <stddef.h>


#define DE_FAIL (1 << 0)
#define DE_HARDFAIL (1 << 1)
#define DE_NOCOLOR (1 << 3)

struct demeta {
	_Atomic unsigned succeeded;
	_Atomic unsigned failed;
	char result[64];
};

int deionb(char *restrict, size_t, const char *restrict, ...) __attribute__((format (printf, 3, 4)));
int deiop(const char *restrict, ...) __attribute__((format (printf, 1, 2)));
void deresult(const char *, const char *, const char *, unsigned, struct demeta *, int);
int dereport(struct demeta *);

#define detest(s, ex, fs, r, dm, f) do {\
char e = (ex);\
(void)deionb((dm)->result, 64, fs, r);\
(void)deresult(#s, #ex, __FILE__, __LINE__, dm, e ? f : f | DE_FAIL);\
} while (0)

#endif

