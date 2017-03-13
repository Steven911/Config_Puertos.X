Retardo_50mS:
    movlw   .50	    ;asignamos el valor al contador 1 (K)
    movwf   Cont1   
ciclo2:    
    movlw   .10	    ;valor del contador 2 (M)
    movwf   Cont2
ciclo1:    
    movlw   .65	    ;valor del contador 3 (N)
    movwf   Cont3
    
    decfsz  Cont3   ;decrementamos el contador 3, si no es cero ejecuta la siguiente
    goto    $-1	    ;se devuelve a decrementar el cont3
    
    decfsz  Cont2   ;decrementamos contador 2- si no es cero, cargamos el 65
    goto    ciclo1  ;vuelvo al ciclo 1
    
    decfsz  Cont1   ;decrementamos contador 1- si no es cero cargamos el 10 (contador 2)
    goto    ciclo2
    
    return