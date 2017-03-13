list p=16f887
    #include "p16f887.inc"

    cblock  0x20
	Cont1	;0x20
	Cont2	;0x21
	Cont3	;0x22
	contador
	new
    endc
    
    ORG 0x00
    call	osc_conf    ;llamamos a la configuracion del oscilador
    call	port_conf   ;llamamos a la configuracion de los puertos

ciclo:		    ;etiqueta a donde se devuelve el ciclo goto
    movf	PORTA,W	    ;registro q quiero leer y lo traigo hacia el registro de trabajo
    movwf	PORTB	    ;se pone lo del registro de trabajo y se pone en puerto B
    goto	ciclo	    ;ciclo infinito con etiqueta a donde hace el salto

#include "CONFIGURACION.inc"	;Se definen subrutinas por lo que debe estar después del org y antes del end
#include "Retardos.inc"
    end