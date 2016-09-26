#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int deionb(char *restrict d, size_t n, const char *restrict fs, ...)
{
	va_list ap;
	int l;

	va_start(ap, fs);
	l = vsnprintf(d, n, fs, ap);
	va_end(ap);

	if (l < 0) {
		return l;
	}

	if ((unsigned)l > n) {
		d[n - 1] = '.';
		d[n - 2] = '.';
		d[n - 3] = '.';
	};

	return l;
}

