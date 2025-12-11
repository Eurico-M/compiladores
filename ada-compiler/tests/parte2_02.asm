.data
x: .word 0

.text
main:
    li $v0, 5
    syscall
    sw $v0, x
    lw $8, x
    li $9, 42
    bge $8, $9, label3
    j label1
label3:
    lw $10, x
    li $11, 2
    rem $8, $10, $11
    li $9, 0
    beq $8, $9, label0
    j label1
label0:
    lw $8, x
    lw $9, x
    li $10, 1
    add $8, $9, $10
    sw $8, x
    lw $8, x
    li $v0, 1
    move $a0, $8
    syscall
    j label2
label1:
    lw $8, x
    lw $9, x
    li $10, 1
    sub $8, $9, $10
    sw $8, x
    lw $8, x
    li $v0, 1
    move $a0, $8
    syscall
label2:
