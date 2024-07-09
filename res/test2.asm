.data

A : .half 0x002A, 0xA5FF, 0x5BE1
N : .word 3
newLine : .asciiz "\n\0"

.text

main:
    la $a0, A
    lw $a1, N
    
    jal esercizio

    # Salvo i risultati in s0 e s1 prima di fare le syscall
    addi $s0, $v0, 0
    addi $s1, $v1, 0
    
    li $v0, 1
    addi $a0, $s0, 0 
    syscall 
    
    li $v0, 4
    la $a0, newLine
    syscall
    
    li $v0, 1
    addi $a0, $s1, 0 
    syscall 
        
    li $v0, 10
    syscall
      
esercizio:
    # Variabili usate
    li $t0, 0 #indice dell'array
    li $t1, 0 #indice del bit dell'half-word
    li $t2, 16 #Costante : lunghezza  di un half word in bit
    li $t3, 0 # Word Attuale
    li $t4, 0 #Variabile di appoggio per calcolare il parity bit
    li $t5, 0 # Variabile  per il bit mask del LSB
    li $t6, 0 # Parity Word per L'output

    ciclo:
        bge $t0, $a1, fineCiclo
        li $t1, 0 # azzero il ciclo
        li $t4, 0 # azzero il parity bit
        
        addi $t3, $t0, 0 # prendo l'indice attuale
        sll $t3,$t3, 1 # indice * 4. mi allineo alla word usando l'offset
        add $t3, $t3, $a0 # indice + offset
        lh $t3, 0($t3) # carico in memoria l'half word
        
            
        cicloInterno: # qui prendo bit  a bit l'elemento
            bge $t1, $t2, fineCicloInterno
            
            andi $t5, $t3, 1 # prendo il lsb
            xori $t5, $t5, 1 #Xor sul primo bit
            xor $t4, $t4, $t5 # xor sul counter attuale
            srl $t3, $t3, 1 # toglo il lsb 
        
            
            addi $t1, $t1, 1
        j cicloInterno
        fineCicloInterno:
            sll $t6, $t6, 1 # shifto versoda sinistra
            add $t6, $t6, $t4 # dato che  $t4 appartiene a 0 e 1 
                                                # sto sommando sempre il lsb

            addi $t0, $t0, 1
            j ciclo 
    fineCiclo:
        add $v0, $v0, $t6
        # Calcolo il parity bit della word
        
        li $t0, 0
        li $t5, 0
        li $t4, 0
          
        cicloXORWord: # qui prendo bit  a bit l'elemento
            bge $t1, $t2, fineCicloXORWord
            
            andi $t5, $t3, 1 # prendo il msb
            xori $t5, $t5, 1 #Xor sul primo bit
            xor $t4, $t4, $t5 # xor sul counter attuale
            srl $t3, $t3, 1 # toglo il MSB 
        
            
            add $t1, $t1, 1
        j cicloXORWord
        fineCicloXORWord:
        
        add $v1, $v1, $t4

        jr $ra
