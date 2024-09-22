/*
 * Usage
 * ----------------------------------------------------------------------------
 * Ignore error          | try maybe_throw();
 * ----------------------------------------------------------------------------
 * Specific error        | try maybe_throw();
 *                       | catch (ERR_LIKE_THIS) puts("aaa");
 *                       | catch (ERR_LIKE_THAT) puts("bbb");
 *                       | catchor (ERR1 | ERR2) puts("ccc");
 * ----------------------------------------------------------------------------
 * All error             | try maybe_throw();
 *                       | catchany err_handler();
 * ----------------------------------------------------------------------------
 * Propagate error       | maybe_throw();
 * ----------------------------------------------------------------------------
 * Multiple statements   | try {
 *                       |   maybe_throw();
 *                       |   probably_throw();
 *                       |   throw_by_any_chance();
 *                       | } catchany {
 *                       |   puts("Something went wrong");
 *                       |   exit(1);
 *                       | }
 * ----------------------------------------------------------------------------
 * Get error code        | try maybe_throw();
 *                       | catchany
 *                       |   printf("This is error code: %d\n", errcode);
 * ----------------------------------------------------------------------------
 * Thrower               | throw(ERR_CODE_OF_TYPE_INT);
 * ----------------------------------------------------------------------------
 *
 * Reserved word
 * - `errcode`
 * - `EXCEPTION_H_*`
 */

#include "try-catch.h"

jmp_buf EXCEPTION_H_jb[MAX_NEST_DEPTH];
int errcode;
int EXCEPTION_H_nest;

void EXCEPTION_H_cl(int **g) { (**g)--; }
