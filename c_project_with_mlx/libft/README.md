**my current libft**


```
Last update Fri 19 Aug 2022 13:45 PM CET
```
```diff
* libft original functions
+ personal
! require fix

box
+┣ ft_box_del
+┣ ft_box_new
+┣ ft_box_show
+┣ ft_box_xlen
+┣ ft_box_ylen
+┗ ft_box_zlen

char
*┣ ft_isalnum
*┣ ft_isalpha
*┣ ft_isascii
*┣ ft_isdigit
+┣ ft_islower
*┣ ft_isprint
+┣ ft_issign
+┣ ft_isspace
+┣ ft_isupper
*┣ ft_tolower
*┗ ft_toupper

color
+┣ color_cool           (4)
+┣ color_palette_bwgr   (4)
+┣ color_palette_cbym   (4)
+┗ color_palette_format (4)

conv
*┣ ft_atoi
+┣ ft_atoi_base
+┣ ft_atol
+┃ ┣ ft_atoull
+┃ ┣ ft_atoll
+┃ ┣ ft_atol
+┃ ┗ ft_atol_severe
+┣ ft_convert_base
*┣ ft_itoa
+┣ ft_itoabtw
+┗ ft_nbrlen

debug
+┣ dbg_ar
+┣ dbg_cmd (debug_aux.c)
+┃ ┣ dbg_cmd
+┃ ┣ dbg_assert
+┃ ┗ dbg_display_file_range
+┣ db (debug_coffee.c)
+┃ ┣ dbs
+┃ ┣ dbe
+┃ ┣ db
+┃ ┣ db3
+┃ ┗ dbx
+┗ dbv (debug_int.c)
+┃ ┣ dbv
+  ┗ dba

file
+┣ ft_filelen
+┣ ft_filename
+┣ ft_gnln
+┗ ft_is_extension

hash
+┗ ft_hash_crc32

io
+┣ sc_close (sc_close.c)
+┃ ┣ sc_close_std
+┃ ┣ sc_close
+┃ ┣ sc_2close
+┃ ┗ sc_3close
+┣ sc_dup
+┣ sc_dup2
+┗ sc_unlink

lst
*┣ ft_lstadd_back
*┣ ft_lstadd_front
*┣ ft_lstclear
*┣ ft_lstdelone
*┣ ft_lstiter
*┣ ft_lstlast
*┣ ft_lstmap
*┣ ft_lstnew
*┗ ft_lstsize

maths
+┣ ft_abs
+┣ ft_distance_btw_values
+┣ ft_factorial
+┣ ft_fibonacci
+┣ ft_isprime
+┣ ft_median
+┣ ft_min
+┃ ┗ ft_max
+┣ ft_nextprime
+┣ ft_power
!┗ ft_sqrt

mem
*┣ ft_bzero
*┣ ft_calloc
*┣ ft_memchr
*┣ ft_memcmp
*┣ ft_memcpy
*┣ ft_memmove
*┗ ft_memset

sort
!┣ ft_insort_asc
!┃ ┗ ft_insort_des
+┣ ft_intswap
+┣ ft_qsort_asc
+┃ ┗ ft_qsort_des
+┣ ft_rev_int_tab
+┗ ft_sort_int_tab

stack
+┣ ft_stack_add_bottom
+┣ ft_stack_del
+┣ ft_stack_isempty
+┣ ft_stack_isfull
+┣ ft_stack_ascs (ft_stack_issort.c)
+┃ ┣ ft_stack_asc
+┃ ┣ ft_stack_des
+┃ ┣ ft_stack_ascn
+┃ ┗ ft_stack_desn
+┣ ft_stack_len
+┣ ft_stack_median
+┣ ft_stack_min
+┃ ┗ ft_stack_max
+┣ ft_stack_new
+┣ ft_stack_peek
+┣ ft_stack_pop
+┃ ┗ ft_stack_pop_bottom
+┣ ft_stack_push
+┣ ft_stack_rev
+┣ ft_stack_show
+┣ ft_stack_stats
+┗ ft_stack_swap_top

str
+┣ ft_arfree
+┣ ft_arlen
+┣ ft_close_gnl
+┣ ft_contains_only
*┣ ft_split
*┣ ft_strchr
*┣ ft_strcmp
*┣ ft_strcpy
*┣ ft_strdup
*┣ ft_striteri
*┣ ft_strjoin
+┃ ┗ ft_strjointri
*┣ ft_strlcat
*┣ ft_strlcpy
*┣ ft_strlen
*┣ ft_strmapi
*┣ ft_strncmp
*┣ ft_strnstr
*┣ ft_strrchr
+┣ ft_strtolower
+┣ ft_strtoupper
*┣ ft_strtrim
*┣ ft_substr
+┣ get_next_line
+┗ get_next_line_2

 tab
+┣ ft_iifree
+┣ ft_iishow
+┣ ft_new_iitab
+┣ ft_newtab
+┣ ft_set_iitab
+┣ ft_tab_are_distinct
+┃ ┗ ft_tab_uniq_count
+┣ ft_tab_firstquart
+┣ ft_tab_issort_des
+┃ ┗ ft_tab_issort_asc
+┣ ft_tab_median
+┃ ┣ ft_tab_first_quar
+┃ ┗ ft_tab_third_quar
+┣ ft_tab_min
+┃ ┗ ft_tab_max
+┣ ft_tabdup
+┃ ┗ ft_tabdup_range
+┗ ft_tabshow

 test
+┗ ft_test

 write
+┣ sc_write
+┣ ft_printf
+┣ ┗ ft_dprintf
+┣ ft_putarray
+┃ ┗ ft_putarray_fd
+┣ ft_putchar
*┃ ┗ ft_putchar_fd
+┣ ft_putnbase
+┣ ft_putnbr
*┃ ┗ ft_putnbr_fd
+┣ ft_putnl
+┃ ┗ ft_putnl_fd
+┣ ft_putptr
+┃ ┗ ft_putptr_fd
+┣ ft_putstr
*┃ ┣ ft_putstr_fd
+┃ ┣ ft_putsnl
*┃ ┗ ft_putsnl_fd (eq. *ft_putendl_fd)
+┗ ft_putx
+  ┣ ft_putx_fd
+  ┗ ft_putxnl_fd
```
