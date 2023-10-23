#include <stdio.h>

int main(void)
{
	unsigned char letra;
	static unsigned char letra_decoded;
	unsigned char rightmost_bit;

	letra = 'z';

	int i = 0;
	while (i < 8)
	{
		rightmost_bit = letra & 0x80;
		rightmost_bit >>= 7;
		letra <<= 1;
		letra_decoded = letra_decoded | rightmost_bit; //isso aqui precisa mudar
		if (i == 7)
			break;
		letra_decoded <<= 1;
		i++;
	}
	printf("%c\n", letra_decoded);
}
