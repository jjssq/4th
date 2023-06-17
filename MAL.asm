; 1. Write an assembly language program to convert alowercase letter to an uppercase letter or vice versa.

.MODEL SMALL
.STACK
.DATA
MESSAGE DB 0DH, 0AH, 'Enter a character: $'
RESULT DB 0DH, 0AH, 'Converted character: $'
CHAR DB ?
.CODE
MAIN PROC
MOV AX, @DATA
MOV DS, AX

MOV DX, OFFSET MESSAGE
MOV AH, 09H
INT 21H

MOV AH, 01H
INT 21H
MOV CHAR, AL

CMP CHAR, 'a'
JB NOT_LOWER
CMP CHAR, 'z'
JA NOT_LOWER

SUB CHAR, 32

JMP DISPLAY_RESULT
NOT_LOWER:

CMP CHAR, 'A'
JB DISPLAY_RESULT
CMP CHAR, 'Z'
JA DISPLAY_RESULT

ADD CHAR, 32
DISPLAY_RESULT:

MOV DX, OFFSET RESULT
MOV AH, 09H
INT 21H
MOV DL, CHAR
MOV AH, 02H
INT 21H

MOV AH, 4CH
INT 21H
MAIN ENDP
END MAIN


; 2. Write an assembly language program to read a character. Ifit is "y" or "Y", display it; otherwise terminate the program.

.MODEL SMALL
.STACK
.DATA
MESSAGE DB 0DH, 0AH, 'Enter a character: $'
VALID_MESSAGE DB 0DH, 0AH, 'Valid character entered: $'
INVALID_MESSAGE DB 0DH, 0AH, 'Invalid character entered. Program terminated. $'
CHAR DB ?
.CODE
MAIN PROC
MOV AX, @DATA
MOV DS, AX

MOV DX, OFFSET MESSAGE
MOV AH, 09H
INT 21H

MOV AH, 01H
INT 21H
MOV CHAR, AL

CMP CHAR, 'y'
JE DISPLAY_VALID
CMP CHAR, 'Y'
JE DISPLAY_VALID

MOV DX, OFFSET INVALID_MESSAGE
MOV AH, 09H
INT 21H
JMP EXIT_PROGRAM
DISPLAY_VALID:

MOV DX, OFFSET VALID_MESSAGE
MOV AH, 09H
INT 21H
MOV DL, CHAR
MOV AH, 02H
INT 21H
EXIT_PROGRAM:

MOV AH, 4CH
INT 21H
MAIN ENDP
END MAIN


; 3.  Write an assembly language program to determine whether a number is odd or even.

.MODEL SMALL
.STACK
.DATA
MESSAGE DB 0DH, 0AH, 'Enter a number: $'
ODD_MESSAGE DB 0DH, 0AH, 'The number is odd. $'
EVEN_MESSAGE DB 0DH, 0AH, 'The number is even. $'
NUMBER DB ?
.CODE
MAIN PROC
MOV AX, @DATA
MOV DS, AX

MOV DX, OFFSET MESSAGE
MOV AH, 09H
INT 21H

MOV AH, 01H
INT 21H
SUB AL, 30H

TEST AL, 01H 
JNZ ODD 

MOV DX, OFFSET EVEN_MESSAGE
MOV AH, 09H
INT 21H
JMP EXIT_PROGRAM
ODD:

MOV DX, OFFSET ODD_MESSAGE
MOV AH, 09H
INT 21H
EXIT_PROGRAM:

MOV AH, 4CH
INT 21H
MAIN ENDP
END MAIN


; 4. Write an assembly language program to add two decimal numbers.

.model small
.stack
.data
val1 db ?
val2 db ?
sum db ?
msg1 db 0dh, 0ah, "Enter first digit: $"
msg2 db 0dh, 0ah, "Enter second digit: $"
msg3 db 0dh, 0ah, "Sum of two numbers: $"
.code
main proc
mov ax, @data
mov ds, ax

mov dx, offset msg1
mov ah, 9
int 21h
mov ah, 1
int 21h
sub al, 30h
mov val1, al

mov dx, offset msg2
mov ah, 9
int 21h
mov ah, 1
int 21h
sub al, 30h
mov val2, al

mov al, val1
add al, val2
add al, 30h

mov sum, al

mov dx, offset msg3
mov ah, 9
int 21h
mov dl, sum
mov ah, 2
int 21h

mov ah, 4Ch
int 21h
main endp
end main


; 5. Write an assembly language program to input two numbers, compare them and display the smaller one.

.model small
.stack
.data
num1 db ?
num2 db ?
msg1 db 0dh, 0ah, "Enter first number: $"
msg2 db 0dh, 0ah, "Enter second number: $"
msg3 db 0dh, 0ah, "The smaller number is: $"
.code
main proc
mov ax, @data
mov ds, ax

mov dx, offset msg1
mov ah, 9
int 21h
mov ah, 1
int 21h
sub al, 30h
mov num1, al

mov dx, offset msg2
mov ah, 9
int 21h
mov ah, 1
int 21h
sub al, 30h
mov num2, al

mov al, num1
cmp al, num2
jge num2_smaller
num1_smaller:

mov dx, offset msg3
mov ah, 9
int 21h
mov dl, num1
add dl, 30h
mov ah, 2
int 21h
jmp exit_program
num2_smaller:

mov dx, offset msg3
mov ah, 9
int 21h
mov dl, num2
add dl, 30h
mov ah, 2
int 21h
exit_program:

mov ah, 4Ch
int 21h
main endp
end main


; 6. Write an assembly language program to find the largest element of an array.

.model small
.stack
.data
array db 7, 5, 3, 9, 0, 1, 2
size equ 7
maxVal db 0
msg db "The largest element is: $"
.code
main proc
mov ax, @data
mov ds, ax

mov al, array
mov maxVal, al

mov cx, size
mov si, offset array + 1
loop_start:
mov al, byte ptr [si]
cmp al, maxVal
jle not_largest

mov maxVal, al
not_largest:
inc si
loop loop_start

mov dx, offset msg
mov ah, 09h
int 21h
mov dl, maxVal
add dl, 30h
mov ah, 02h
int 21h

mov ah, 4Ch
int 21h
main endp
end main


; 7. Write an assembly language program to calculate the average of numbers.

.model small
.stack
.data
count dw 4
numbers db 2, 3, 1, 2
sum dw 0
average db 0
msg db "Average: $"
.code
main proc
mov ax, @data
mov ds, ax

mov cx, count
mov si, offset numbers
xor bx, bx
sum_loop:
mov al, byte ptr [si]
add bx, ax
inc si
loop sum_loop

mov ax, bx
cwd 
idiv count
mov sum, bx
mov average, al

mov dx, offset msg
mov ah, 09h
int 21h
mov dl, average
add dl, 30h
mov ah, 02h
int 21h
mov ah, 4Ch
int 21h
main endp
end main


; 8. Write an assembly language program to calculate the factorial of an integer number.

.MODEL SMALL
.STACK 100H
.DATA
.CODE
MAIN PROC
MOV CX, 6
MOV AX, 1
TOP:
MUL CX
LOOP TOP
MOV BX, 10
MOV CX, 0
CONVERT:
XOR DX, DX
DIV BX
ADD DL, 30H
PUSH DX
INC CX
OR AX, AX
JNZ CONVERT
DISPLAY:
POP DX
MOV AH, 02H
INT 21H
LOOP DISPLAY
MOV AH, 4CH
INT 21H
MAIN ENDP
END MAIN

; 9. Write an assembly language program to sort numbers in ascending order.
.MODEL SMALL
.STACK 100H
.DATA
MSG1 DB 'enter elements: $'
MSG2 DB 'AFTER SORTING: $'
ARR DB 100 dup (0)
.CODE
MAIN PROC
MOV AX, @DATA
MOV DS, AX
MOV AH, 9
lea DX, MSG1
INT 21H
XOR CX, CX
MOV AH, 1
INT 21H
XOR SI, SI
WHILE_:
CMP AL, 0dH
JE END_WHILE
MOV ARR[SI], AL
INC SI ;SI+1
INC CX
MOV AH, 2
MOV DL, ' '
INT 21h
MOV AH, 1
INT 21H
JMP WHILE_
END_WHILE:
MOV AH, 2
MOV DL, 0DH
INT 21H
MOV DL, 0AH
INT 21H
JCXZ EXIT
LEA SI, ARR
MOV BX, CX
CALL BUBBLE_SORT
MOV AH, 9
LEA DX, MSG2
INT 21H
XOR SI,SI
TOP:
MOV AH, 2
MOV DL, ARR[SI]
INT 21H
MOV DL, ' '
INT 21H
INC SI
LOOP TOP
EXIT:
MOV AH, 4CH
INT 21H
MAIN ENDP
BUBBLE_SORT PROC

PUSH AX 
PUSH BX
PUSH CX
PUSH DX
PUSH DI
MOV AX, SI
MOV CX, BX
DEC CX
@OUTER_LOOP:
MOV BX, CX
MOV SI, AX
MOV DI, AX
INC DI
@INNER_LOOP:
MOV DL, [SI]
CMP DL, [DI]
JNG @SKIP_EXCHANGE
XCHG DL, [DI]
MOV [SI], DL
@SKIP_EXCHANGE:
INC SI
INC DI
DEC BX
JNZ @INNER_LOOP
LOOP @OUTER_LOOP
POP DI
POP DX
POP CX
POP BX
POP AX
RET
BUBBLE_SORT ENDP
END MAIN


; 10. Write an assembly language program to accept a string from keyboard and display the string in reverse order.

.MODEL SMALL
.STACK 100H
.DATA

STRING DB 'This is a sample string', '$'
.CODE
MAIN PROC FAR
MOV AX,@DATA
MOV DS,AX

CALL REVERSE

LEA DX,STRING

MOV AH, 09H
INT 21H

MOV AH, 4CH
INT 21H
MAIN ENDP
REVERSE PROC

MOV SI, OFFSET STRING

;string
MOV CX, 0H
LOOP1:

;the last character
MOV AX, [SI]
CMP AL, '$'
JE LABEL1

;stack
PUSH [SI]

;and count
INC SI
INC CX
JMP LOOP1
LABEL1:

;address of the string
MOV SI, OFFSET STRING
LOOP2:
;if count not equal to zero
CMP CX,0
JE EXIT

POP DX

XOR DH, DH

;reversed string
MOV [SI], DX

;decrement count
INC SI
DEC CX
JMP LOOP2
EXIT:

MOV [SI],'$ '
RET
REVERSE ENDP
END MAIN

