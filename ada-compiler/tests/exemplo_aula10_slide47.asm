.data
b: .word 0
a: .word 0

.text
main:
    lw $8, a
    li $9, 0
    bne $8, $9, label2
    j label1
label2:
    lw $8, b
    lw $9, a
    bgt $8, $9, label0
    j label1
label0:
    lw $8, b
    lw $9, b
    lw $10, a
    sub $8, $9, $10
    sw $8, b
label1:
