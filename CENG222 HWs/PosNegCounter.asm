# Variables
.data
input: .word 10,-5,7,-3,6,9,-10,-8,40,100
output1: .word 0
output2: .word 0

.text
# Add your code below
li $t0, 0 #positive
li $t1, 0 #negative

la $t2, input

li $t3, 0 #counter

loop:
beq $t3, 10, end
lw $t4, 0($t2)
slti $t5, $t4, 0
bne $t5, $zero, neg

pos:
addi $t0, $t0, 1
j next

neg:
addi $t1, $t1, 1

next:
addi $t3, $t3, 1
addiu $t2, $t2, 4
j loop

end:
sw $t0, output1
sw $t1, output2