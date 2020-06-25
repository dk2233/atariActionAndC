/*  to compile please run
 *  C65 C1.C C2.A -T
 *  MAC65 C2.A E: C2.COM -A*/
#DEFINE MAX_INT 32767
CLEARARRAY(TAB,SIZE)
    CHAR *TAB;
    INT SIZE;
    $(
            INT I;
            I=0;
            WHILE( SIZE>0)
            $(
                TAB[I]=0;
                --SIZE;
                $)
            RETURN 0;
            $)


INTTOASC(I,STRING)
    INT I;
    CHAR *STRING;
    $(
            INT SIZE;
            INT TEST;

            SIZE=1;
            WHILE (1)
            $(
                IF (I/SIZE<10) 
                    BREAK; 
                SIZE = SIZE * 10;
                ++TEST;
                $)  

            TEST = 0;

            WHILE (SIZE>0)
            $(
                *(STRING+TEST)='0'+I/SIZE;
                I =I % SIZE;
                SIZE = SIZE/10;
                ++TEST;
                $)
            *(STRING+TEST) = '\0';
            RETURN 0;
    $)
MAIN()
    $(
            CHAR WORD[10];
            CHAR MYVAR;
            INT I1, I2;
            MYVAR=0;
            CLEARARRAY(WORD,10);
            WHILE ( MYVAR<2  )
            $(
                PUTS("My program shows number ");
                INTTOASC(MYVAR,WORD);
                PUTS(WORD);
                PUTCHAR('\n');
                ++MYVAR;
                $)
            INTTOASC(9,WORD);
            PUTS(WORD);
            INTTOASC(39,WORD);
            PUTS(WORD);
            INTTOASC(152,WORD);
            PUTS(WORD);
            INTTOASC(892,WORD);
            PUTS(WORD);
            INTTOASC(4725,WORD);
            PUTS(WORD);
            INTTOASC(12356,WORD);
            PUTS(WORD);

            INTTOASC(32356,WORD);
            PUTS(WORD);
            
            I1 = 152/100;
            INTTOASC(I1,WORD);
            PUTS(WORD);

/*             PUTS("enter 1 number");
 */



            $)
#ASM H1:IO.LIB

