#include <limine.h>
#include <stddef.h>
#include <stdint.h>

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

void _start(void) {

  if (initIO() == -1)
    done();

  printf("%d", 5);

  done();
}