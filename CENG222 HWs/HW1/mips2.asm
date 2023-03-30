.data
inputs: .word 500, 100, 250, 75, 30, 15
result: .word 0

.text
la $t0, inputs
lw $t1, 0($t0)
lw $t2, 4($t0)
lw $t3, 8($t0)
lw $t4, 12($t0)
lw $t5, 16($t0)
lw $t6, 20($t0)

sub $t7, $t3, $t4
sub $t8, $t1, $t2
add $t9, $t7, $t8
add $t9, $t9, $t5
sub $t9, $t9, $t6

sw $t9, result