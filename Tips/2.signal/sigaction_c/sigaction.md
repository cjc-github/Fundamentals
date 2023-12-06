# Sigaction结构体



sigaction()函数原型：

```c++
#include <signal.h>
 
int sigaction(int sig, const struct sigaction *act, struct sigaction *oldact);
```

sigaction结构体

```c++
struct sigaction {
  void     (*sa_handler)(int);
  void     (*sa_sigaction)(int, siginfo_t *, void *);
  sigset_t   sa_mask;
  int        sa_flags;
  void     (*sa_restorer)(void);
};
```

sigaction 函数，它类似于 signal 函数，而且完全可以代替 signal 函数，也更稳定。
