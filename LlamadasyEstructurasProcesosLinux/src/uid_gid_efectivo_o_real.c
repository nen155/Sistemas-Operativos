#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

void main(void)
{
printf("Identificador usuario: %d\n", getuid());
printf("Identificador usuario efectivo: %d\n", geteuid());
printf("Identificador grupo: %d\n", getgid());
printf("Identificador grupo efectivo: %d\n", getegid());
}

