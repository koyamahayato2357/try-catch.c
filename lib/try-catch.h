#pragma once
#include <setjmp.h>

#define MAX_NEST_DEPTH 8

extern jmp_buf EXCEPTION_H_jb[MAX_NEST_DEPTH];
extern int errcode;
extern int EXCEPTION_H_nest;

#define EXCEPTION_H_CAT(x, y) x##y
#define EXCEPTION_H_GENUNIQTOK(x) EXCEPTION_H_CAT(EXCEPTION_H_, x)

void EXCEPTION_H_cl(int **g);

#define EXCEPTION_H_TRY(cnt)                                                   \
  for (int EXCEPTION_H_GENUNIQTOK(cnt) = 1; EXCEPTION_H_GENUNIQTOK(cnt);)      \
    for (int *EXCEPTION_H_CAT(EXCEPIOTN_H_g_, cnt)                             \
             __attribute__((cleanup(EXCEPTION_H_cl))) = &EXCEPTION_H_nest;     \
         EXCEPTION_H_GENUNIQTOK(cnt); EXCEPTION_H_GENUNIQTOK(cnt) = 0)         \
      if ((errcode = setjmp(EXCEPTION_H_jb[EXCEPTION_H_nest++])) == 0 ||       \
          errcode == ERR_RETRY)

#define try EXCEPTION_H_TRY(__COUNTER__)
#define catch(e) else if (errcode == (e))
#define catchor(e) else if (errcode & (e))
#define catchany else
#define retry throw(ERR_RETRY)
#define throw(e) longjmp(EXCEPTION_H_jb[EXCEPTION_H_nest - 1], e)
