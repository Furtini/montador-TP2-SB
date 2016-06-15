READ AX ;leitura do primeiro numero
READ BX ;leitura do segundo numero
WRITE AX ;imprime
WRITE BX ;imprime
MOV CX, AX ;copia valor de AX para CX
ADD CX, BX ;soma CX com BX e salva em CX
WRITE CX
JMP _exit ;sai
ADD AX, 0xF ;deve ser ignorado
MUL BX ;deve ser ignorado
DUMP ;deve ser ignorado
_exit: DUMP
HLT
