#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int
main(int argc, char *argv[])
{
  /* Syscall invocation here */
  printf(1, "available memory: %d\n", memtop());
  int pid = fork();
  wait();
  int i;
  for (i = 0; i < pid; i++)
  {
    char name[16];
    int result;
    result = getmeminfo(i, name, 16);
    if (result)
      printf(1, "pid: %d, name: %s, mem: %d\n", i, name, result);
  }

  exit();
}
