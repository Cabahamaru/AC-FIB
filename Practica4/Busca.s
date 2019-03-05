 .text
	.align 4
	.globl Buscar
	.type Buscar,@function
Buscar:
        # Aqui viene vuestro codigo

        push %ebp
        movl %esp, %ebp
        subl $16, %esp
        
        movl $-1, -4(%ebp)      #trobat = -1
        movl $0, -16(%ebp)      #low = 0
        movl $0, -8(%ebp)       #mid = low
        
        movl 24(%ebp), %eax     #eax <- N
        subl $1, %eax           #eax <- N-1
        movl %eax, -12(%ebp)    #high = N-1
        
while:
        movl -16(%ebp), %eax    #eax <- low
        movl -12(%ebp), %ecx    #ecx <- high
        cmpl %ecx, %eax
        jg fiwhile
        pushl 8(%ebp)
        pushl 20(%ebp)
        pushl 16(%ebp)
        pushl 12(%ebp)
        leal -8(%ebp), %eax
        pushl %eax
        leal -12(%ebp), %eax
        pushl %eax
        leal -16(%ebp), %eax
        pushl %eax
        call BuscarElemento
        addl $28, %esp
        movl %eax, -4(%ebp)     #trobat = resultado de BuscarElemento
        cmpl $0, %eax
        jl  while
fiwhile:
        movl -4(%ebp), %eax
        movl %ebp, %esp
        popl %ebp
        ret
        
        
        
