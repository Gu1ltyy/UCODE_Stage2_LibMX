#include "libmx.h"

char *mx_file_to_str(const char *file) {
	int our_file = open(file, O_RDONLY);
	char buf;
	int length = 0;

	if (our_file < 0)
		return NULL;

	while (read(our_file, &buf, 1))
		length++;

	if (close(our_file) < 0)
		return NULL;

	if (length < 1)
		return NULL;

	our_file = open(file, O_RDONLY);
	char *arr = mx_strnew(length);
	if (our_file < 0)
		return NULL;

	read(our_file, arr, length);
	if (close(our_file) < 0)
		return NULL;

	return arr;
}

