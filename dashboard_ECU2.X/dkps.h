#ifndef DKPS
#define DKPS


#define LEVEL 1
#define EDGE  0

#define SW1 0x0E
#define SW2 0X0D
#define SW3 0x0B
#define SW4 0x07

void initdkps();
char dkps(int trigger);

#endif 