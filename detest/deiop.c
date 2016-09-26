#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int deiop(const char *restrict fs, ...)
{
	va_list ap;
	int n;
	char b[512];

	va_start(ap, fs);
	n = vsnprintf(b, sizeof(b), fs, ap);
	va_end(ap);

	if (n >= (int)sizeof(b)) {
		n = sizeof(b);
		b[n - 1] = '\n';
		b[n - 2] = '.';
		b[n - 3] = '.';
		b[n - 4] = '.';
	} else if (n < 0) {
		n = 0;
	}

	return (int)write(1, b, (size_t)n);
}

