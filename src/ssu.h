#ifndef STRIDE_SSU_H
#define STRIDE_SSU_H

void st_ssu_out_singleton(unsigned char value);

void st_ssu_out(const void *buffer, unsigned int length);

unsigned char st_ssu_in_singleton(void);

#endif
