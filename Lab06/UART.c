


#define SYSPLLCLKSEL (* ((volatile unsigned long *) 0x40048040))
#define MAINCLKSEL (* ((volatile unsigned long *) 0x40048070))

int main()
{
    SYSPLLCLKSEL = 0x1;
    MAINCLKSEL = 0x1;
    while (1)

    return 0;
}
