
unsigned char	swap_bits(unsigned char octet)
{
    // 'octet' usually defines 8 bits (1byte) 
    // a byte is the smallest addressable unit of memory and typically consists of 8 bits
    // octet = ((octet >> 4) & 0x0F | (octet << 4) & 0xF0;
    // above if octet = 01011000
    // (octet >> 4) & 0x0F (00001111) = 00000101
    // bitwise OR '|' will then combine
    // (octet << 4) & 0xF0 (11110000) = 10000000
    // returning a final answer of '10000101'
    
    octet = ((octet >> 4) | (octet << 4));

    return (octet);
} 

/*
#include <stdio.h>
int	main(void)
{
	char a = 120;
	char b = swap_bits(a);

	printf("%04d | %04d\n", (a >> 4) & 0x0F, a & 0x0F);
	printf("%04d | %04d\n", (b >> 4) & 0x0F, b & 0x0F);
} */