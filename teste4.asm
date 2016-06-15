DW v1 ;variavel 1
READ AX ;leitura de uma variavel do usuario
READ BX ;leitura de outra variavel
MOV v1, AX ;copia o numero lido para v1
JMP _multiplicacoes ;parte do codigo q realiza multiplicações
_adicao: MOV AX, 0x0 ;zera AX
MOV BX, 0x4 ;zera BX
ADD AX, 0x14 ;soma 20 a AX
DIV BX ;divide AX por 4
MOV v1, AX ;move para v1 o novo AX (4 supostamente)
WRITE v1 ;escreve v1
JMP _exit ;pula pra saida
_multiplicacoes: MUL BX ;dobra valor de AX
WRITE AX
MOV v1, AX ;atualiza v1 com o valor novo
SUB v1, 0x5 ;v1 = v1 - 5
MOV CX, v1 ;copia v1 em CX
CMP v1, CX ;compara v1 e v2
JZ _adicao ;move para adicao caso v1 e CX sejam iguais 
_exit: WRITE v1
DUMP
HLT
