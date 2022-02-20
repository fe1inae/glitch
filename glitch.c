#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main(int argc, char *argv[])
{
	/* init variables */
	char c;
	int chop;
	struct timespec nsec;

	/* init random with nanoseconds */
	clock_gettime(CLOCK_MONOTONIC, &nsec);
	srand(nsec.tv_nsec);

	/* set random chop thingy or default to 64 */
	if (argc > 1)
		chop = (int)strtol(argv[1], NULL, 10);
	else
		chop = 2048;

	/* loop over each character */
	while (1) {
		/* get character */
		c = fgetc(stdin);

		/* make sure has characters */
		if (feof(stdin))
			break;

		/* print */
		if (c == (rand() % chop))
			putc(c ^ 0xff, stdout);
		else
			putc(c, stdout);

	}

	return 0;
};