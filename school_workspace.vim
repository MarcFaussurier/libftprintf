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
badd +84 term://.//12547:/bin/zsh
badd +80 libftprintf.h
badd +12 sources/ft_match_flag.c
badd +32 sources/ft_resolve.c
badd +3 ft_printf.c
badd +44 test.c
badd +45 libft/libft.h
badd +34 sources/ft_vasprintf.c
badd +24 sources/ft_render_arg.c
badd +0 sources/ft_render_styles.c
badd +18 sources/ft_dump_flag.c
badd +0 utils/int_to_binary.c
badd +19 sources/ft_register_callable.c
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
wincmd _ | wincmd |
split
2wincmd k
wincmd w
wincmd w
wincmd w
wincmd _ | wincmd |
split
1wincmd k
wincmd w
set nosplitright
wincmd t
set winminheight=0
set winheight=1
set winminwidth=0
set winwidth=1
exe '1resize ' . ((&lines * 40 + 42) / 84)
exe 'vert 1resize ' . ((&columns * 91 + 182) / 364)
exe '2resize ' . ((&lines * 39 + 42) / 84)
exe 'vert 2resize ' . ((&columns * 91 + 182) / 364)
exe '3resize ' . ((&lines * 40 + 42) / 84)
exe 'vert 3resize ' . ((&columns * 90 + 182) / 364)
exe '4resize ' . ((&lines * 39 + 42) / 84)
exe 'vert 4resize ' . ((&columns * 90 + 182) / 364)
exe '5resize ' . ((&lines * 26 + 42) / 84)
exe 'vert 5resize ' . ((&columns * 90 + 182) / 364)
exe '6resize ' . ((&lines * 26 + 42) / 84)
exe 'vert 6resize ' . ((&columns * 90 + 182) / 364)
exe '7resize ' . ((&lines * 26 + 42) / 84)
exe 'vert 7resize ' . ((&columns * 90 + 182) / 364)
exe '8resize ' . ((&lines * 39 + 42) / 84)
exe 'vert 8resize ' . ((&columns * 90 + 182) / 364)
exe '9resize ' . ((&lines * 40 + 42) / 84)
exe 'vert 9resize ' . ((&columns * 90 + 182) / 364)
argglobal
setlocal fdm=manual
setlocal fde=0
setlocal fmr=vimreg,vimendreg
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
18,62fold
let s:l = 59 - ((26 * winheight(0) + 20) / 40)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
59
normal! 045|
wincmd w
argglobal
if bufexists("term://.//12547:/bin/zsh") | buffer term://.//12547:/bin/zsh | else | edit term://.//12547:/bin/zsh | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr=vimreg,vimendreg
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 1382 - ((38 * winheight(0) + 19) / 39)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
1382
normal! 029|
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
74,78fold
81,83fold
85,87fold
92,94fold
26
normal! zc
50
normal! zc
let s:l = 48 - ((31 * winheight(0) + 20) / 40)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
48
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
let s:l = 24 - ((22 * winheight(0) + 19) / 39)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
24
normal! 0
wincmd w
argglobal
if bufexists("utils/int_to_binary.c") | buffer utils/int_to_binary.c | else | edit utils/int_to_binary.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr=vimreg,vimendreg
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
22,27fold
18,31fold
34,36fold
18
normal! zo
let s:l = 29 - ((20 * winheight(0) + 13) / 26)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
29
normal! 020|
wincmd w
argglobal
if bufexists("sources/ft_render_arg.c") | buffer sources/ft_render_arg.c | else | edit sources/ft_render_arg.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr=vimreg,vimendreg
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
17,28fold
let s:l = 25 - ((13 * winheight(0) + 13) / 26)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
25
normal! 022|
wincmd w
argglobal
if bufexists("sources/ft_render_styles.c") | buffer sources/ft_render_styles.c | else | edit sources/ft_render_styles.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr=vimreg,vimendreg
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
16,20fold
30,32fold
34,36fold
38,40fold
42,44fold
23,46fold
49,56fold
59,66fold
69,76fold
79,91fold
let s:l = 90 - ((19 * winheight(0) + 13) / 26)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
90
normal! 05|
wincmd w
argglobal
if bufexists("sources/ft_vasprintf.c") | buffer sources/ft_vasprintf.c | else | edit sources/ft_vasprintf.c | endif
setlocal fdm=syntax
setlocal fde=0
setlocal fmr=vimreg,vimendreg
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
let s:l = 52 - ((3 * winheight(0) + 19) / 39)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
52
normal! 08|
wincmd w
argglobal
if bufexists("sources/ft_dump_flag.c") | buffer sources/ft_dump_flag.c | else | edit sources/ft_dump_flag.c | endif
setlocal fdm=manual
setlocal fde=0
setlocal fmr=vimreg,vimendreg
setlocal fdi=#
setlocal fdl=99
setlocal fml=1
setlocal fdn=20
setlocal fen
silent! normal! zE
17,24fold
let s:l = 21 - ((18 * winheight(0) + 20) / 40)
if s:l < 1 | let s:l = 1 | endif
exe s:l
normal! zt
21
normal! 014|
wincmd w
2wincmd w
exe '1resize ' . ((&lines * 40 + 42) / 84)
exe 'vert 1resize ' . ((&columns * 91 + 182) / 364)
exe '2resize ' . ((&lines * 39 + 42) / 84)
exe 'vert 2resize ' . ((&columns * 91 + 182) / 364)
exe '3resize ' . ((&lines * 40 + 42) / 84)
exe 'vert 3resize ' . ((&columns * 90 + 182) / 364)
exe '4resize ' . ((&lines * 39 + 42) / 84)
exe 'vert 4resize ' . ((&columns * 90 + 182) / 364)
exe '5resize ' . ((&lines * 26 + 42) / 84)
exe 'vert 5resize ' . ((&columns * 90 + 182) / 364)
exe '6resize ' . ((&lines * 26 + 42) / 84)
exe 'vert 6resize ' . ((&columns * 90 + 182) / 364)
exe '7resize ' . ((&lines * 26 + 42) / 84)
exe 'vert 7resize ' . ((&columns * 90 + 182) / 364)
exe '8resize ' . ((&lines * 39 + 42) / 84)
exe 'vert 8resize ' . ((&columns * 90 + 182) / 364)
exe '9resize ' . ((&lines * 40 + 42) / 84)
exe 'vert 9resize ' . ((&columns * 90 + 182) / 364)
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
