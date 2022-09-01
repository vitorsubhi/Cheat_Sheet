syntax on

""colorscheme dracula
""colorscheme molokai
""colorscheme torte
""""colorscheme delek

set guifont=Ubuntu\ Mono\ 10
set mouse=a

"set C indent on
"set indent on
set tabstop=4
set softtabstop=4
set shiftwidth=4
set noexpandtab
set noai
set autoindent
"set nowrap "Sem quebra de linha
"set filetype cindent
set smartindent
set ruler
"set cindent

ab PF printf("\n<esc>A;<esc>hhhhi
ab STDIO #include<stdio.h>
ab /* /* */<ESC>hhi
ab free free( <esc>A;<esc>hhi
""ab else else<CR>{<CR>
ab malloc malloc( <esc>A;<esc>hhi

ab then then<CR><CR><backspace>end<esc>kkA<delete>

ab ifndef #ifndef<CR>#define<CR>#endif<ESC>kkA
ab inc #include< ><ESC>i


"Mapeamento de teclado
map <F10> <ESC>:w<ENTER><ESC>:!make<ENTER>
map <F12> <ESC>:w<ENTER><ESC>:!make run<ENTER>

inoremap <F5> <ESC>gTi
inoremap <F6> <ESC>gti
inoremap <C-T> <ESC>:tabe<CR>:E<CR>i
inoremap <S-F5> <ESC>:tabmove 0<CR>i
inoremap <S-F6> <ESC>:tabmove<CR>i

map <F5> <ESC>gTi
map <F6> <ESC>gti
map <C-T> <ESC>:tabe<CR>:E<CR>i
map <S-F5> <ESC>:tabmove 0<CR>i
map <S-F6> <ESC>:tabmove<CR>i


"Mapeamento em runtime
""inoremap if( if(<space><space>)<ESC>hhi
inoremap ( ()<ESC>i
inoremap {<CR> {<CR>}<ESC>ko
inoremap {<space> { }<ESC>i
inoremap " ""<ESC>i
inoremap [ []<ESC>i
inoremap ' ''<esc>i


set scrolloff=8



""set foldmethod=syntax
""set foldmethod=indent
set foldmethod=manual
inoremap <F7> <C-O>za
nnoremap <F7> za
onoremap <F7> <C-C>za
vnoremap <F7> zf

nnoremap ; :

map <F9> :make<CR><CR>:cw<CR>


""set complete=.,i
