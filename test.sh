#!/bin/bash

if [ "$#" -ne 2 ]; then
    echo "Uso: $0 <rango> <movimientos>"
    exit 1
fi

RANGO=$1
UMBRAL=$2
SUMA=0
INTENTOS=0
MINMOVES=0
MAXMOVES=0

if [ "$RANGO" -eq 0 ] || [ "$RANGO" -eq 1 ]; then
	RANGO=2
    while true; do 
        rm -f test.txt checker.txt
        ARG=$(shuf -i 1-$RANGO -n $RANGO | tr '\n' ' ') 
        ./push_swap $ARG > test.txt
        ./push_swap $ARG | ./checker $ARG > checker.txt

        if [ "$1" -eq 0 ] && [ "$RANGO" -eq 501 ]; then
            break
        fi
        
        VAR=$(wc -l < test.txt)

        if [ "$MINMOVES" -eq 0 ] || [ "$VAR" -lt "$MINMOVES" ]; then
            MINMOVES=$VAR
        fi
        if [ "$MAXMOVES" -eq 0 ] || [ "$VAR" -gt "$MAXMOVES" ]; then
            MAXMOVES=$VAR
        fi

        SUMA=$((SUMA + VAR))
        INTENTOS=$((INTENTOS + 1))
        PROMEDIO=$((SUMA / INTENTOS))

        ULTIMA_LINEA=$(tail -n 1 checker.txt)

        if [ "$ULTIMA_LINEA" = "OK" ]; then
			echo -e "\033[42m [OK] $VAR (ARGS: $RANGO)\033[0m $ARG"  # Fondo rojo
        else
            echo -e "\033[41m [KO] BAD SORT (ARGS: $RANGO)\033[0m $ARG"  # Fondo rojo
            break
        fi

        RANGO=$((RANGO + 1))
    done
else
    while true; do
        rm -f test.txt checker.txt
        ARG=$(shuf -i 1-$RANGO -n $RANGO | tr '\n' ' ') 
        ./push_swap $ARG > test.txt
        ./push_swap $ARG | ./checker $ARG > checker.txt

        VAR=$(wc -l < test.txt)

        if [ "$MINMOVES" -eq 0 ] || [ "$VAR" -lt "$MINMOVES" ]; then
            MINMOVES=$VAR
        fi
        if [ "$MAXMOVES" -eq 0 ] || [ "$VAR" -gt "$MAXMOVES" ]; then
            MAXMOVES=$VAR
        fi

        SUMA=$((SUMA + VAR))
        INTENTOS=$((INTENTOS + 1))
        PROMEDIO=$((SUMA / INTENTOS))

        ULTIMA_LINEA=$(tail -n 1 checker.txt)

        if [ "$VAR" -lt "$UMBRAL" ] && [ "$ULTIMA_LINEA" = "OK" ]; then
            echo -e "\033[42m [OK] $VAR (Promedio: $PROMEDIO)(MAX: $MAXMOVES MIN: $MINMOVES)\033[0m"  # Fondo verde
        elif [ "$ULTIMA_LINEA" = "OK" ]; then
            echo -e "\033[41m [KO] $VAR (Promedio: $PROMEDIO)\033[0m $ARG"  # Fondo rojo
            break
        else
            echo -e "\033[41m [KO] BAD SORT\033[0m $ARG"  # Fondo rojo
            break
        fi
    done
fi
