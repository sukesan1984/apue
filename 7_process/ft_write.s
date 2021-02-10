global _ft_write
; extern ___error

section .text

_ft_write:
; ssize_t write(int fildes, const void *buf, size_t nbyte);
; prolog
  push rbp
  mov rbp, rsp
  sub rsp, 32
  mov rax, rbp
  sub rax, 8 ; int fildes
  mov [rax], rdi ; load
  mov rax, rbp
  sub rax, 16 ; void *buf
  mov [rax], rsi ; load
  mov rax, rbp
  sub rax, 24 ; size_t nbyte
  mov [rax], rdx

  mov rax, rbp
  sub rax, 8
  mov rdi, [rax] ; 第一引数をrdiに入れる

  mov rax, rbp
  sub rax, 16
  mov rsi, [rax]

  mov rax, rbp
  sub rax, 24
  mov rdx, [rax]
  mov rax, 0x2000004
  syscall
;  jc .error_write
  mov rsp, rbp
  pop rbp
  ret
;.error_write:
;  mov r15, rax
;  mov rax, rsp
;  and rax, 15
;  jnz .Lcall
;  mov rax, 0
;  call ___error
;  jmp .Lend
;.Lcall:
;  sub rsp, 8
;  mov rax, 0
;  call ___error
;  add rsp, 8
.Lend:
  mov [rax], r15
  mov rax, -1
  mov rsp, rbp
  pop rbp
  ret
