# Max Element of an Array with 10 integers
.data
Array: .word 1, 9, 5, 7, 3, 8, 2, 10, 6, 4
max: .word 0

.text
la $t0, Array
li $t1, 10 # number of elements
li $t2, 0 # index counter
lw $s0, max 

loop:
slt $t5, $t2, $t1
beq $t5, $zero, out

sll $t5, $t2, 2
add $t5, $t0, $t5

lw $t3, 0($t5)
addi $t2, $t2, 1

slt $t5, $s0, $t3
beq $t5, $zero, loop
add $s0, $zero, $t3
j loop

out:
sw $s0, max