push    ebx
push    edi
push    esi
mov     edi, [esp+0Ch+arg_0]
xor     ebx, ebx
push    ebx
push    28h
push    1
call    sub_410B8C
add     esp, 0Ch
mov     [eax], edi
mov     dword ptr [eax+20h], offset off_48F000
mov     [eax+24h], ebx
mov     esi, eax
mov     byte ptr [eax+1Dh], 0
lea     eax, [eax+4]
push    eax
call    sub_45672F
add     esp, 4
mov     [esi+18h], ebx
mov     byte ptr [esi+1Ch], 1
lea     eax, [esi+20h]
pop     esi
pop     edi
pop     ebx
retn