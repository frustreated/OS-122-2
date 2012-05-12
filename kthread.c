/* #include "defs.h" */
/* #include "proc.h" */

/* #include "kthread.h" */
/* #include "spinlock.h" */

#include "types.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "x86.h"
#include "proc.h"
#include "spinlock.h"

#include "kthread.h"


int
kthread_create(void*(*start_func)(), void* stack, uint stack_size) {
    return fork_kthread(start_func, stack);
}

int kthread_id() {
    return get_id();
}

void kthread_exit() {
    void proc_kthread_exit();
}

int kthread_join( int thread_id ) {
    return proc_kthread_join(thread_id);
}
