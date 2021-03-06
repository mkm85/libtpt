// Example usage of TPT::Buffer class.

#include "mylex.h"
#include "mybuffer.h"

#include "libtpt/buffer.h"

int main()
{
	char buffer[BUFSIZE];
	int bufsize = fillbuffer(buffer);

	TPT::Buffer inbuf(buffer, bufsize);
	char c;

	while (inbuf)
	{
	    c = inbuf.getnextchar();
	    lex(c);
	}

	return 0;
}
