.text
	.align 4
	.globl procesar
	.type	procesar, @function
procesar:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$16, %esp
	pushl	%ebx
	pushl	%esi
	pushl	%edi

# Aqui has de introducir el codigo
    movl $0, %eax #i
    movl 20(%ebp), %ebx #n
    movl 16(%ebp), %ecx #mat c
    movl 12(%ebp), %edi #mat b
    movl 8(%ebp), %esi #mat a
    imul %ebx, %ebx #nxn
    
for:
    cmpl %ebx, %eax
    jge fifor
    
    movb (%esi), %dl #dl = mata[i*n+j]
    subb (%edi), %dl #dl = dl - matb[i*n+j]
    movb %dl, (%ecx) #matc[i*n+j] = dl
if: cmpb $0, (%ecx)
    jle else
    movb $255, (%ecx) #matc = 255
    jmp fiif
else:
    movb $0, (%ecx)
fiif:
    addl $1, %eax
    addl $1, %ecx
    addl $1, %edi
    addl $1, %esi
    jmp for
fifor:

# El final de la rutina ya esta programado

	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
