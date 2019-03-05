.text
	.align 4
	.globl OperaMat
	.type	OperaMat, @function
OperaMat:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
# Aqui has de introducir el codigo

    movl $0, -4(%ebp) #res=0
    movl $0, -8(%ebp) #i=0
    movl $0, -12(%ebp) #j=0
    movl 8(%ebp), %eax #eax = @Matriz
for1:
    cmpl $3, -8(%ebp)
    jge fifor1
for2:
    cmpl $3,-12(%ebp)
    jge fifor2
    movl -8(%ebp), %ecx #ecx = i
    imul $3, %ecx, %ecx #ecx = i*3
    addl -8(%ebp), %ecx #ecx = i*3+i
    movl (%eax,%ecx,4), %ebx # ebx = M[i][i]
    addl -12(%ebp), %ebx #ebx = M[i][i]+j
    subl -4(%ebp), %ebx #ebx = ebx-res
    incl -12(%ebp)
    jmp for2
fifor2:
    movl -8(%ebp), %edx #edx = i
    addl 12(%ebp), %edx #edx = i+salto
    movl %edx, -8(%ebp) #i = i+salto
    jmp for1
fifor1:

# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx	
	movl %ebp,%esp
	popl %ebp
	ret
