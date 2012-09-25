#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "bit.h"

/*@doc
 * @desc: see POSIX strlen()
 */
char *strchr(const char *h, int n)
{
	const size_t *w;

	n = (unsigned char)n;

	if (n == 0) {
		return ((char *)h + strlen(h));
	}

	/* Align to word size and search for char */
	for (; ((uintptr_t)h & (sizeof(size_t) - 1 ))
		&& (*(unsigned char *)h != n); h++);
	/* Check if each word has the needle */
	for (w = (const size_t)h; !word_has_char(w, n); w++);
	/* Find the location of the needle within the haystack */
	for (h = (const char *)w; *(unsigned char *)h != n; h++);

	/* If the haystack pointer hasn't incremented there are two
	 * possibilities, either we found the needle on the first try or the
	 * needle doesn't exist within the haystack.
	 */
	if (*h == n) {
		return ((char *)h);
	} else {
		return (NULL);
	}
}
