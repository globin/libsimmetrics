/*
 * * Copyright (C) 2012 Johnathan Botha et al. All rights reserved.
 *
 * This file is part of libsimmetrics
 *
 * libsimmetrics is the C port of the Java project called Simmetrics,
 *
 * The Java code can be found here: https://github.com/Simmetrics/simmetrics
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * NOTE: The code in this file was found online and sported a GPLV3
 * 			compatible license.
 *
 * levenshtein.c
 *
 * I found this code online - If you wrote it - tell me who you are...
 *
 *  Created on: 20 Nov 2012
 *      Author: Unknown
 */

#include <string.h>
#include "levenshtein.h"

# ifdef LEV_CASE_INSENSITIVE
# include <ctype.h>
# define eq(x, y) (tolower(x) == tolower(y))
# else
# define eq(x, y) ((x) == (y))
# endif

# define min(x, y) ((x) < (y) ? (x) : (y))

size_t levenshtein(const char *str1, const char *str2) {
	size_t len1 = strlen(str1), len2 = strlen(str2);
	unsigned int *v = new unsigned int[len2 + 1];
	unsigned int i, j, current, next = 0, cost;

	/* strip common prefixes */
	while (len1 > 0 && len2 > 0 && eq(str1[0], str2[0]))
		str1++, str2++, len1--, len2--;

	/* handle degenerate cases */
	if (!len1) {
		delete[] v;
		return len2;
	}
	if (!len2) {
		delete[] v;
        return len1;
    }

	/* initialize the column vector */
	for (j = 0; j < len2 + 1; j++)
		v[j] = j;

	for (i = 0; i < len1; i++) {
		/* set the value of the first row */
		current = i + 1;
		/* for each row in the column, compute the cost */
		for (j = 0; j < len2; j++) {
			/*
			 * cost of replacement is 0 if the two chars are the same, or have
			 * been transposed with the chars immediately before. otherwise 1.
			 */
			cost = !(eq(str1[i], str2[j])
					|| (i && j && eq(str1[i-1], str2[j])
							&& eq(str1[i],str2[j-1])));
			/* find the least cost of insertion, deletion, or replacement */
			next = min(min( v[j+1] + 1,
							current + 1 ),
					v[j] + cost );
			/* stash the previous row's cost in the column vector */
			v[j] = current;
			/* make the cost of the next transition current */
			current = next;
		}
		/* keep the final cost at the bottom of the column */
		v[len2] = next;
	}

	delete[] v;

	return next;
}

double levenshtein_similarity(const char *str1, const char *str2) {

	size_t lev_dist = levenshtein(str1, str2);

	double max_len = (double) strlen(str1);
	double str2_len = (double) strlen(str2);

	if (max_len < str2_len)
		max_len = str2_len;

	if (max_len == 0)
		return 1;
	else
		return 1.0 - ((double) lev_dist / max_len);
}

