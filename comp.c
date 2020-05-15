#include <stdio.h>
#include <unistd.h>
 
#if 0
#define STATIC static  
#else
#define STATIC
#endif

void func(void)
{
	char* a = ({ STATIC char b[40];
			char *_b = b;
			_b += sprintf(_b, "test 1");
			_b += sprintf(_b, "test 2");
			b;
	    });
 
	char* b = ({ STATIC  char c[40];
			char *__b = c;
			__b += sprintf(__b, "test 3");
			__b += sprintf(__b, "test 4");
			c;
	    });
 
    printf("a = %s\n", a);
    printf("b = %s\n", b);

}


int main(void)
{
	unsigned int i = 0;
	while(1) {
		func(); 
		sleep(1);
	}
    return 0;
}
