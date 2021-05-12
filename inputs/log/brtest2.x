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
[00400024] 2402000a  addiu $2, $0, 10         ; 8: addiu $v0, $zero, 0xa 
[00400028] 0810000b  j 0x0040002c [l_1]       ; 10: j l_1 
[0040002c] 14000004  bne $0, $0, 16 [l_3-0x0040002c]; 12: bne $zero, $zero, l_3 
[00400030] 10000004  beq $0, $0, 16 [l_4-0x00400030]; 14: beq $zero, $zero, l_4 
[00400034] 24070347  addiu $7, $0, 839        ; 15: addiu $7, $zero, 0x347 
[00400038] 0000000c  syscall                  ; 16: syscall 
[0040003c] 24071337  addiu $7, $0, 4919       ; 18: addiu $7, $zero, 0x1337 
[00400040] 3407d00d  ori $7, $0, -12275       ; 21: addiu $7, $zero, 0xd00d 
[00400044] 0000000c  syscall                  ; 22: syscall 


