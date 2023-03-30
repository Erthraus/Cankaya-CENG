.data
result: .word 0

.text
addi $t0, $zero, 500
addi $t1, $zero, 100
addi $t2, $zero, 250
addi $t3, $zero, 75
addi $t4, $zero, 30
addi $t5, $zero, 15

sub $t6, $t2, $t3
sub $t7, $t0, $t1
add $t8, $t7, $t6
add $t9, $t8, $t4
sub $t9, $t9, $t5

sw $t9, result