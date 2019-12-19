let SessionLoad = 1
let s:so_save = &so | let s:siso_save = &siso | set so=0 siso=0
let v:this_session=expand("<sfile>:p")
silent only
cd ~/libftprintf
if expand('%') == '' && !&modified && line('$') <= 1 && getline(1) == ''
  let s:wipebuf = bufnr('%')
endif
set shortmess=aoO
badd +30 term://.//47285:/bin/zsh
badd +26 Makefile
badd +84 term://.//54361:/bin/zsh
badd +80 libftprintf.h
badd +14 sources/ft_match_flag.c
badd +32 sources/ft_resolve.c
badd +3 ft_printf.c
badd +1 test.c
badd +104 libft/libft.h
argglobal
%argdel
$argadd ./
edit test.c
set splitbelow splitright
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
wincmd _ | wincmd |
vsplit
3wincmd h
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd w
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd w
wincmd _ | wincmd |
split
1wincmd k
wincmd w
wincmd w
set nosplitright
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 40 + 42) / 84)
exe 'vert 1resize ' . ((&columns * 103 + 182) / 364)
exe '2resize ' . ((&lines * 39 + 42) / 84)
exe 'vert 2resize ' . ((&columns * 103 + 182) / 364)
exe '3resize ' . ((&lines * 40 + 42) / 84)
exe 'vert 3resize ' . ((&columns * 86 + 182) / 364)
exe '4resize ' . ((&lines * 39 + 42) / 84)
exe 'vert 4resize ' . ((&columns * 86 + 182) / 364)
exe '5resize ' . ((&lines * 69 + 42) / 84)
exe 'vert 5resize ' . ((&columns * 86 + 182) / 364)
exe '6resize ' . ((&lines * 10 + 42) / 84)
exe 'vert 6resize ' . ((&columns * 86 + 182) / 364)
exe 'vert 7resize ' . ((&columns * 86 + 182) / 364)
argglobal
setlocal fdm=syntax
setlocal fde=0
setlocal fmr=vimreg,vimendreg
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 1 - ((0 * winheight(0) + 20) / 40)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1
normal! 0
wincmd w
argglobal
if bufexists("term://.//54361:/bin/zsh") | buffer term://.//54361:/bin/zsh | else | edit term://.//54361:/bin/zsh | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr=vimreg,vimendreg
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 7 - ((6 * winheight(0) + 19) / 39)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
7
normal! 0
wincmd w
argglobal
if bufexists("libftprintf.h") | buffer libftprintf.h | else | edit libftprintf.h | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr=vimreg,vimendreg
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
26,28fold
31,48fold
50,53fold
55,62fold
63,65fold
67,69fold
71,73fold
74,76fold
79,81fold
83,85fold
89,91fold
26
normal! zc
31
normal! zc
50
normal! zc
55
normal! zc
63
normal! zc
67
normal! zc
71
normal! zc
74
normal! zc
79
normal! zc
83
normal! zc
89
normal! zc
let s:l = 83 - ((61 * winheight(0) + 20) / 40)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
83
normal! 0
wincmd w
argglobal
if bufexists("Makefile") | buffer Makefile | else | edit Makefile | endif
setlocal fdm=syntax
setlocal fde=0
setlocal fmr=vimreg,vimendreg
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 21 - ((19 * winheight(0) + 19) / 39)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
21
normal! 05|
wincmd w
argglobal
if bufexists("sources/ft_resolve.c") | buffer sources/ft_resolve.c | else | edit sources/ft_resolve.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr=vimreg,vimendreg
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
let s:l = 23 - ((19 * winheight(0) + 34) / 69)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
23
normal! 05|
wincmd w
argglobal
enew
setlocal fdm=manual
setlocal fde=0
setlocal fmr=vimreg,vimendreg
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
wincmd w
argglobal
if bufexists("libft/libft.h") | buffer libft/libft.h | else | edit libft/libft.h | endif
setlocal fdm=syntax
setlocal fde=0
setlocal fmr=vimreg,vimendreg
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 80 - ((79 * winheight(0) + 40) / 80)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
80
normal! 0
wincmd w
3wincmd w
exe '1resize ' . ((&lines * 40 + 42) / 84)
exe 'vert 1resize ' . ((&columns * 103 + 182) / 364)
exe '2resize ' . ((&lines * 39 + 42) / 84)
exe 'vert 2resize ' . ((&columns * 103 + 182) / 364)
exe '3resize ' . ((&lines * 40 + 42) / 84)
exe 'vert 3resize ' . ((&columns * 86 + 182) / 364)
exe '4resize ' . ((&lines * 39 + 42) / 84)
exe 'vert 4resize ' . ((&columns * 86 + 182) / 364)
exe '5resize ' . ((&lines * 69 + 42) / 84)
exe 'vert 5resize ' . ((&columns * 86 + 182) / 364)
exe '6resize ' . ((&lines * 10 + 42) / 84)
exe 'vert 6resize ' . ((&columns * 86 + 182) / 364)
exe 'vert 7resize ' . ((&columns * 86 + 182) / 364)
tabnext 1
if exists('s:wipebuf') && getbufvar(s:wipebuf, '&buftype') isnot# 'terminal'
  silent exe 'bwipe ' . s:wipebuf
endif
unlet! s:wipebuf
set winheight=1 winwidth=20 winminheight=1 winminwidth=1 shortmess=aFc
let s:sx = expand("<sfile>:p:r")."x.vim"
if file_readable(s:sx)
  exe "source " . fnameescape(s:sx)
endif
let &so = s:so_save | let &siso = s:siso_save
doautoall SessionLoadPost
unlet SessionLoad
" vim: set ft=vim :
