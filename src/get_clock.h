#ifndef GET_CLOCK_H
#define GET_CLOCK_H

#if defined (__x86_64__) || defined(__i386__)
/* Note: only x86 CPUs which have rdtsc instruction are supported. */
typedef unsigned long long cycles_t;
static inline cycles_t get_cycles()
{
	unsigned low, high;
	unsigned long long val;
	asm volatile ("rdtsc" : "=a" (low), "=d" (high));
	val = high;
	val = (val << 32) | low;
	return val;
}
#elif defined(__PPC__) || defined(__PPC64__)
/* Note: only PPC CPUs which have mftb instruction are supported. */
/* PPC64 has mftb */
typedef unsigned long cycles_t;
static inline cycles_t get_cycles()
{
	cycles_t ret;

	__asm__ __volatile__ ("\n\t isync" "\n\t mftb %0" : "=r"(ret));
	return ret;
}
#elif defined(__ia64__)
/* Itanium2 and up has ar.itc (Itanium1 has errata) */
typedef unsigned long cycles_t;
static inline cycles_t get_cycles()
{
	cycles_t ret;

	asm volatile ("mov %0=ar.itc" : "=r" (ret));
	return ret;
}
#elif defined(__ARM_ARCH_7A__)
typedef unsigned long long cycles_t;
static inline cycles_t get_cycles(void)
{
	cycles_t        clk;
	asm volatile("mrrc p15, 0, %Q0, %R0, c14" : "=r" (clk));
	return clk;
}
#elif defined(__s390x__) || defined(__s390__)
typedef unsigned long long cycles_t;
static inline cycles_t get_cycles(void)
{
	cycles_t        clk;
	asm volatile("stck %0" : "=Q" (clk) : : "cc");
	return clk >> 2;
}
#elif defined(__sparc__) && defined(__arch64__)
typedef unsigned long long cycles_t;
static inline cycles_t get_cycles(void)
{
	cycles_t v;
	asm volatile ("rd %%tick, %0" : "=r" (v) : );
	return v;
}
#elif defined(__aarch64__)

typedef unsigned long cycles_t;
static inline cycles_t get_cycles()
{
	cycles_t cval;
	asm volatile("isb" : : : "memory");
	asm volatile("mrs %0, cntvct_el0" : "=r" (cval));
	return cval;
}

#else
#warning get_cycles not implemented for this architecture: attempt asm/timex.h
#include <asm/timex.h>
#endif

extern double get_cpu_mhz(int);

#endif
