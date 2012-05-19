struct stat;

// system calls
int fork(void);
int exit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(char*, int);
int mknod(char*, short, short);
int unlink(char*);
int fstat(int fd, struct stat*);
int link(char*, char*);
int mkdir(char*);
int chdir(char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);
int kltsim(int params[]);
int kthread_create(void*(*start_func)(), void* stack,
                   uint stack_size);
int kthread_id();
void kthread_exit();
int kthread_join( int thread_id );
int kthread_yield(void);
int kyield(void);

int kthread_mutex_alloc();
int kthread_mutex_dealloc( int mutex_id );
int kthread_mutex_lock( int mutex_id );
int kthread_mutex_unlock( int mutex_id );

int kthread_cond_alloc();
int kthread_cond_dealloc( int cond_id );
int kthread_cond_wait( int cond_id, int mutex_id );
int kthread_cond_signal( int cond_id );

void* kthread_get_ustack();


// ulib.c
int stat(char*, struct stat*);
char* strcpy(char*, char*);
void *memmove(void*, void*, int);
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, char*, ...);
char* gets(char*, int max);
uint strlen(char*);
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);


/* A&T */
int sim_init(int parameters[]);

/* A&T kthread.c */


#define DEBUG_PRINT(level, fmt, ...)					\
    do { if (T_A_DEBUG >= level) printf(2, "<%s>:%d:[%s()]: " fmt "\n", \
                               __FILE__, __LINE__, __func__,		\
                               __VA_ARGS__); } while (0)
