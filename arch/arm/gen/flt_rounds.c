/*	$OpenBSD: flt_rounds.c,v 1.4 2015/10/18 19:30:39 guenther Exp $	*/
/*	$NetBSD: flt_rounds.c,v 1.1 2000/12/29 20:13:48 bjh21 Exp $	*/

/*
 * Copyright (c) 1996 Mark Brinicombe
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by Mark Brinicombe
 *	for the NetBSD Project.
 * 4. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/types.h>
#include <ieeefp.h>
#include <float.h>

static const int map[] = {
	1,	/* round to nearest */
	2,	/* round to positive infinity */
	3,	/* round to negative infinity */
	0	/* round to zero */
};

/*
 * Return the current FP rounding mode
 *
 * Returns:
 *	0 - round to zero
 *	1 - round to nearest
 *	2 - round to postive infinity
 *	3 - round to negative infinity
 *
 * ok all we need to do is get the current FP rounding mode
 * index our map table and return the appropriate value.
 *
 * HOWEVER:
 * The ARM FPA codes the rounding mode into the actual FP instructions
 * so there is no such thing as a global rounding mode.
 * The default is round to nearest if rounding is not explicitly specified.
 * FP instructions generated by GCC will not explicitly specify a rounding
 * mode.
 *
 * So the best we can do it to return the rounding mode FP instructions
 * use if rounding is not specified which is round to nearest.
 *
 * This could change in the future with new floating point emulators or
 * soft float FP libraries.
 */

int
__flt_rounds()
{
	return(map[fpgetround()]);
}
DEF_STRONG(__flt_rounds);
