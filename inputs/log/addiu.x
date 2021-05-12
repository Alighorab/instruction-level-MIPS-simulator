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
[00400024] 2402000a  addiu $2, $0, 10         ; 6: addiu $v0, $zero, 10 
[00400028] 24080005  addiu $8, $0, 5          ; 7: addiu $t0, $zero, 5 
[0040002c] 2509012c  addiu $9, $8, 300        ; 8: addiu $t1, $t0, 300 
[00400030] 240a01f4  addiu $10, $0, 500       ; 9: addiu $t2, $zero, 500 
[00400034] 254b0022  addiu $11, $10, 34       ; 10: addiu $t3, $t2, 34 
[00400038] 256b002d  addiu $11, $11, 45       ; 11: addiu $t3, $t3, 45 
[0040003c] 0000000c  syscall                  ; 12: syscall 


