User Text Segment [00400000]..[00440000]
[00400000] 8fa40000  lw $4, 0($29)            ; 183: lw $a0 0($sp) # argc 
[00400004] 27a50004  addiu $5, $29, 4         ; 184: addiu $a1 $sp 4 # argv 
[00400008] 24a60004  addiu $6, $5, 4          ; 185: addiu $a2 $a1 4 # envp 
[0040000c] 00041080  sll $2, $4, 2            ; 186: sll $v0 $a0 2 
[00400010] 00c23021  addu $6, $6, $2          ; 187: addu $a2 $a2 $v0 
[00400014] 0c100009  jal 0x00400024 [main]    ; 188: jal main 
[00400018] 00000000  nop                      ; 189: nop 
[0040001c] 3402000a  ori $2, $0, 10           ; 191: li $v0 10 
[00400020] 0000000c  syscall                  ; 192: syscall # syscall 10 (exit) 
[00400024] 24020400  addiu $2, $0, 1024       ; 11: addiu $2, $zero, 1024 
[00400028] 00421821  addu $3, $2, $2          ; 12: addu $3, $2, $2 
[0040002c] 00622025  or $4, $3, $2            ; 13: or $4, $3, $2 
[00400030] 200504d2  addi $5, $0, 1234        ; 14: add $5, $zero, 1234 
[00400034] 00053400  sll $6, $5, 16           ; 15: sll $6, $5, 16 
[00400038] 24c7270f  addiu $7, $6, 9999       ; 16: addiu $7, $6, 9999 
[0040003c] 00e24023  subu $8, $7, $2          ; 17: subu $8, $7, $2 
[00400040] 00834826  xor $9, $4, $3           ; 18: xor $9, $4, $3 
[00400044] 384a00ff  xori $10, $2, 255        ; 19: xori $10, $2, 255 
[00400048] 00065942  srl $11, $6, 5           ; 20: srl $11, $6, 5 
[0040004c] 00066103  sra $12, $6, 4           ; 21: sra $12, $6, 4 
[00400050] 01656824  and $13, $11, $5         ; 22: and $13, $11, $5 
[00400054] 308e0064  andi $14, $4, 100        ; 23: andi $14, $4, 100 
[00400058] 000a7822  sub $15, $0, $10         ; 24: sub $15, $zero, $10 
[0040005c] 3c110064  lui $17, 100             ; 25: lui $17, 100 
[00400060] 2402000a  addiu $2, $0, 10         ; 26: addiu $v0, $zero, 0xa 
[00400064] 0000000c  syscall                  ; 27: syscall 


