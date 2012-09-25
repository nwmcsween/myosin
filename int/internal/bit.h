/*@doc
 * @desc: bit related macros / functions.
 */
#ifndef BIT_H
#define BIT_H

#include <limits.h>
#include <stdlib.h>

/* Todo: Document */
#define WORD_ONES_LOW	((size_t)-1 / UCHAR_MAX)
#define WORD_ONES_HIGH	(((size_t)-1 / UCHAR_MAX) << (CHAR_BIT - 1))

/*@doc
 * @desc: see if an arch word has a zero
 * @param: w - string aligned to word size
 */
static inline char word_has_zero(const size_t w)
{
	return !!((w - WORD_ONES_LOW) & ~w & WORD_ONES_HIGH);
}

/*@doc
 * @desc: find char within a word
 * @param: w - string aligned to word size, c - character to search for
 */
static inline char word_has_char(const size_t w, const char c)
{
	return !!((w - WORD_ONES_LOW) & ~w & WORD_ONES_HIGH ^ (~(size_t)0 / UCHAR_MAX * c));
}

static inline int signedness(int i)
{
	return ((i > 0) - (i < 0));
}

#endif /* BIT_H */