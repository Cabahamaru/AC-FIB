 .text
	.align 4
	.globl BuscarElemento
	.type BuscarElemento,@function
BuscarElemento:
        # Aqui viene vuestro codigo
        
    pushl %ebp
    movl %esp, %ebp
    
    movl 16(%ebp),%ecx     #ecx <- @mid
    movl (%ecx),%ecx       #ecx <- *mid
    movl 32(%ebp),%eax     #eax <- @v
    imul $12,%ecx          #ecx <- (*mid)*12
    addl %ecx,%eax         #eax <- v[*mid]
    #addl $4, %eax         #eax <- v[*mid].k
    movl 24(%ebp),%ecx     #ecx <- X.k
    cmpl 4(%eax),%ecx
    jne else
    movl 16(%ebp),%eax     #eax <- @mid
    movl (%eax),%eax       #eax <- *mid
    movl %ebp,%esp
    popl %ebp
    ret                     #return *mid
else:
    movl 16(%ebp), %eax     #eax <- @mid
    movl (%eax), %eax       #eax <- *mid
    movl 12(%ebp), %ecx     #ecx <- @high
    movl (%ecx), %ecx       #ecx <- *high
    cmpl %ecx, %eax
    jge else2
    movl 16(%ebp), %eax     #eax <- @mid
    movl %ecx, (%eax)       #*mid = *high
    movl 8(%ebp), %ecx      #ecx <- @low
    addl $1, (%ecx)         #++(*low)
    movl $-1, %eax          #eax <- -1
    movl %ebp, %esp
    popl %ebp
    ret                     #return -1
else2:
    movl 8(%ebp), %ecx      #ecx <- @low
    movl (%ecx), %eax       #*mid = *low
    movl 12(%ebp), %ecx     #ecx <- @high
    subl $1, (%ecx)         #--(*high)
    movl $-1, %eax          #eax <- -1
    movl %ebp, %esp
    popl %ebp
    ret                     #return -1
    
