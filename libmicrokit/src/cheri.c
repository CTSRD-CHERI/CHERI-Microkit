#include <cheri_init_globals_bw.h>
#include <cheri.h>

void _start_purecap( void *__capability code_cap, void *__capability data_cap)
{
		cheri_init_globals_3(data_cap,
													code_cap,
													code_cap);
}
