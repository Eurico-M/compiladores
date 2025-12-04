.data
y: .word 0
x: .word 0
.text
main:
lw $t0, y
li $t0, 1
sw $t0, y
lw $t0, x
lw $t1, y
li $t3, 2
li $t4, 3
mul $t2, $t3, $t4
add $t0, $t1, $t2
sw $t0, x