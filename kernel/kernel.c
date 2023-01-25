#include <limine.h>
#include <stddef.h>

#include <hal/hal.h>
#include <include/stdio.h>

/* void handleKeypress(int code){
        char Scancode[] = {
                0 , 0 , '1' , '2' ,
                '3' , '4' , '5' , '6' ,
                '7' , '8' , '9' , '0' ,
                '-' , '=' , 0 , 0 , 'Q' ,
                'W' , 'E' , 'R' , 'T' , 'Y' ,
                'U' , 'I' , 'O' , 'P' , '[' , ']' ,
                0 , 0 , 'A' , 'S' , 'D' , 'F' , 'G' ,
                'H' , 'J' , 'K' , 'L' , ';' , '\'' , '`' ,
                0 , '\\' , 'Z' , 'X' , 'C' , 'V' , 'B' , 'N' , 'M' ,
                ',' , '.' , '/' , 0 , '*' , 0 , ' '
        };

        terminal_request.response->write(terminal, Scancode[code], 1);
} */

/*
Limine sets up a basic GDT (which I can use), I must setup an IDT!
*/

static void done(void) {
  for (;;) {
    __asm__("hlt");
  }
}

void kmain() {
	printf("[kmain] Hellow to BogusOS 0.0.1-sus.25.01.2023\n");
	//printf("[kmain] Starting FizzBuzz...\n");

	//fizzbuzz();

	done();
}

void _start(void) {
  printf("Test... ");
  initHAL();
  printf("HAL Started...\n");

  printf("Starting kmain()\n");
  kmain();
}