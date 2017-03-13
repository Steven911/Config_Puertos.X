    ; CONFIG1
    ; __config 0xE3F2
     __CONFIG _CONFIG1, _FOSC_INTRC_NOCLKOUT & _WDTE_OFF & _PWRTE_OFF & _MCLRE_ON & _CP_OFF & _CPD_OFF & _BOREN_ON & _IESO_OFF & _FCMEN_OFF & _LVP_OFF
    ; CONFIG2
    ; __config 0xFEFF
     __CONFIG _CONFIG2, _BOR4V_BOR21V & _WRT_OFF

     
osc_conf:
    
    bsf	    STATUS,RP0  ;pone RP0 en 1
    bcf	    STATUS,RP1  ;pone RP1 en 0
    movlw   0xf1	    
    movwf   OSCCON
    
    
    return

port_conf:
    banksel TRISA       ;posicionarse en el banco donde se encuentra el TRISA -- tarda dos instrucciones del ensamblador
    movlw   0xff        ;PONER PUWRTO A COMO ENTRADA
    movwf   TRISA       ;movemos el dato al TRISA
    clrf    TRISB       ;clareamos el TRISB para ponerlo como salida
    bsf	    STATUS,RP1  ;vuelve a poner RP1 en 1 y ya está en el banco 3
    clrf    ANSEL	;permite q la entrada sea digital haciendolo 0
    clrf    ANSELH	;	"    "  "    "	   "     "        "      
    bcf	    STATUS,RP0  ;pone RP0 en 0
    bcf	    STATUS,RP1  ;pone RP1 en 0 y ahora estamos en el banco 0
    return
