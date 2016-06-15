READ AX ;leitura do primeiro numero
READ BX ;leitura do segundo numero
MOV CX, AX ;copia valor de AX para CX
ADD CX, BX ;soma CX com BX e salva em CX
DW variavel1 ;definição de uma variavel
JMP _pula ;pula algumas instruções
_volta: READ AX ;le nova AX
WRITE AX ;imprime AX negado
AND CX, AX ;subtrai AX de BX
PUSH 0xFF ;empilha 10
PUSH BX ;empilha BX
POP CX ;desimpilha BX salva em CX
POP BX ;desempilha 0xFF e salva em BX
JMP _exit ;pula pro final
_pula: WRITE AX ;imprime
WRITE BX ;imprime
WRITE CX
MUL BX ;multiplica BX alterando AX
WRITE AX
WRITE BX
MOV BX, 0x5
MOV CX, 0x5
CMP BX, CX ;compara BX e CX e muda tagz se igual ZF = 1
JZ _volta ; se BX == Cx pula pro volta
_exit: DUMP
HLT
