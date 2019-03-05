.text
	.align 4
	.globl OperaVec
	.type	OperaVec, @function
OperaVec:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, -4(%ebp)
	
# Aqui has de introducir el codigo

    movl $1, -8(%ebp) #i = 1
    movl 8(%ebp), %eax #eax = @Vector
for: 
    movl -8(%ebp), %ecx #ecx = i
    cmpl 12(%ebp), %ecx
    jge fifor
    movl (%eax,%ecx,4), %ebx #ebx = Vector[i]
if:
    cmpl -4(%ebp), %ebx #Vector[i]<res
    jge fiif
    movl %ebx, -4(%ebp) # res = Vector[i]
fiif:
    incl -8(%ebp)
    jmp for
fifor:


# El final de la rutina ya esta programado
	movl	-4(%ebp), %eax
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
