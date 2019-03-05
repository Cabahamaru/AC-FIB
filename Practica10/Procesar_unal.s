.text
	.align 4
	.globl procesar
	.type	procesar, @function
.data
    aux1: .byte 0
    aux2: .byte 255
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
    
    movdqu (%esi), %xmm0
    movdqu (%edi), %xmm1
    psubb (%edi), %xmm0
    movdqu %xmm0, (%ecx)
    movdqu aux1, %xmm2
    pcmpgtb %xmm2, %xmm0
    movdqu aux2, (%ecx)
    movdqu %xmm2, (%ecx)
    
    addl $1, %eax
    addl $1, %ecx
    addl $1, %edi
    addl $1, %esi
    jmp for
    
fifor:

# El final de la rutina ya esta programado

	emms	# Instruccion necesaria si os equivocais y usais MMX
	popl	%edi
	popl	%esi
	popl	%ebx
	movl %ebp,%esp
	popl %ebp
	ret
