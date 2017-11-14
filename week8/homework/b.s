	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.file	1 "b.c"
	.globl	_cmp
	.p2align	4, 0x90
_cmp:                                   ## @cmp
Lfunc_begin0:
	.loc	1 22 0                  ## b.c:22:0
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi2:
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
Ltmp0:
	.loc	1 23 19 prologue_end    ## b.c:23:19
	movq	-8(%rbp), %rsi
	.loc	1 23 12 is_stmt 0       ## b.c:23:12
	movl	(%rsi), %eax
	.loc	1 23 30                 ## b.c:23:30
	movq	-16(%rbp), %rsi
	.loc	1 23 21                 ## b.c:23:21
	cmpl	(%rsi), %eax
	setl	%cl
	andb	$1, %cl
	movzbl	%cl, %eax
	.loc	1 23 5                  ## b.c:23:5
	popq	%rbp
	retq
Ltmp1:
Lfunc_end0:
	.cfi_endproc

	.globl	_check
	.p2align	4, 0x90
_check:                                 ## @check
Lfunc_begin1:
	.loc	1 27 0 is_stmt 1        ## b.c:27:0
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi3:
	.cfi_def_cfa_offset 16
Lcfi4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi5:
	.cfi_def_cfa_register %rbp
	movl	%edi, -4(%rbp)
Ltmp2:
	.loc	1 28 9 prologue_end     ## b.c:28:9
	movl	$1, -8(%rbp)
	.loc	1 29 9                  ## b.c:29:9
	movl	$0, -16(%rbp)
Ltmp3:
	.loc	1 30 12                 ## b.c:30:12
	movl	$0, -12(%rbp)
LBB1_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_3 Depth 2
	.loc	1 0 12 is_stmt 0        ## b.c:0:12
	movq	_n@GOTPCREL(%rip), %rax
Ltmp4:
	.loc	1 30 17 discriminator 1 ## b.c:30:17
	movl	-12(%rbp), %ecx
	.loc	1 30 19 discriminator 1 ## b.c:30:19
	cmpl	(%rax), %ecx
Ltmp5:
	.loc	1 30 5 discriminator 1  ## b.c:30:5
	jge	LBB1_9
## BB#2:                                ##   in Loop: Header=BB1_1 Depth=1
Ltmp6:
	.loc	1 31 18 is_stmt 1       ## b.c:31:18
	movl	-12(%rbp), %eax
	.loc	1 31 13 is_stmt 0       ## b.c:31:13
	movl	%eax, -20(%rbp)
LBB1_3:                                 ##   Parent Loop BB1_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	.loc	1 0 13                  ## b.c:0:13
	xorl	%eax, %eax
	movb	%al, %cl
	movq	_n@GOTPCREL(%rip), %rdx
	.loc	1 32 16 is_stmt 1 discriminator 1 ## b.c:32:16
	movl	-20(%rbp), %eax
	.loc	1 32 19 is_stmt 0 discriminator 1 ## b.c:32:19
	addl	$1, %eax
	.loc	1 32 23 discriminator 1 ## b.c:32:23
	cmpl	(%rdx), %eax
	.loc	1 32 27 discriminator 1 ## b.c:32:27
	movb	%cl, -21(%rbp)          ## 1-byte Spill
	jge	LBB1_5
## BB#4:                                ##   in Loop: Header=BB1_3 Depth=2
	.loc	1 0 27 discriminator 1  ## b.c:0:27
	movq	_arr@GOTPCREL(%rip), %rax
	.loc	1 32 34 discriminator 2 ## b.c:32:34
	movl	-20(%rbp), %ecx
	.loc	1 32 36 discriminator 2 ## b.c:32:36
	addl	$1, %ecx
	.loc	1 32 30 discriminator 2 ## b.c:32:30
	movslq	%ecx, %rdx
	movl	(%rax,%rdx,4), %ecx
	.loc	1 32 42 discriminator 2 ## b.c:32:42
	movslq	-20(%rbp), %rdx
	movl	(%rax,%rdx,4), %esi
	.loc	1 32 50 discriminator 2 ## b.c:32:50
	addl	-4(%rbp), %esi
	.loc	1 32 40 discriminator 2 ## b.c:32:40
	cmpl	%esi, %ecx
	setl	%dil
	movb	%dil, -21(%rbp)         ## 1-byte Spill
LBB1_5:                                 ##   in Loop: Header=BB1_3 Depth=2
	.loc	1 0 40 discriminator 2  ## b.c:0:40
	movb	-21(%rbp), %al          ## 1-byte Reload
	.loc	1 32 9 discriminator 3  ## b.c:32:9
	testb	$1, %al
	jne	LBB1_6
	jmp	LBB1_7
LBB1_6:                                 ##   in Loop: Header=BB1_3 Depth=2
	.loc	1 32 59 discriminator 4 ## b.c:32:59
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	.loc	1 32 9 discriminator 4  ## b.c:32:9
	jmp	LBB1_3
LBB1_7:                                 ##   in Loop: Header=BB1_1 Depth=1
	.loc	1 33 13 is_stmt 1       ## b.c:33:13
	movl	-20(%rbp), %eax
	.loc	1 33 16 is_stmt 0       ## b.c:33:16
	subl	$1, %eax
	.loc	1 33 11                 ## b.c:33:11
	movl	%eax, -12(%rbp)
	.loc	1 34 13 is_stmt 1       ## b.c:34:13
	movl	-8(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
Ltmp7:
## BB#8:                                ##   in Loop: Header=BB1_1 Depth=1
	.loc	1 30 24 discriminator 2 ## b.c:30:24
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	.loc	1 30 5 is_stmt 0 discriminator 2 ## b.c:30:5
	jmp	LBB1_1
Ltmp8:
LBB1_9:
	.loc	1 36 12 is_stmt 1       ## b.c:36:12
	movl	-8(%rbp), %eax
	.loc	1 36 5 is_stmt 0        ## b.c:36:5
	popq	%rbp
	retq
Ltmp9:
Lfunc_end1:
	.cfi_endproc

	.globl	_main
	.p2align	4, 0x90
_main:                                  ## @main
Lfunc_begin2:
	.loc	1 40 0 is_stmt 1        ## b.c:40:0
	.cfi_startproc
## BB#0:
	pushq	%rbp
Lcfi6:
	.cfi_def_cfa_offset 16
Lcfi7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Lcfi8:
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
LBB2_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB2_3 Depth 2
                                        ##     Child Loop BB2_7 Depth 2
	leaq	L_.str(%rip), %rdi
	movq	_n@GOTPCREL(%rip), %rsi
	leaq	-8(%rbp), %rdx
Ltmp10:
	.loc	1 42 12 prologue_end discriminator 1 ## b.c:42:12
	movb	$0, %al
	callq	_scanf
	.loc	1 42 35 is_stmt 0 discriminator 1 ## b.c:42:35
	cmpl	$-1, %eax
	.loc	1 42 5 discriminator 1  ## b.c:42:5
	je	LBB2_13
## BB#2:                                ##   in Loop: Header=BB2_1 Depth=1
Ltmp11:
	.loc	1 44 16 is_stmt 1       ## b.c:44:16
	movl	$0, -12(%rbp)
LBB2_3:                                 ##   Parent Loop BB2_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	.loc	1 0 16 is_stmt 0        ## b.c:0:16
	movq	_n@GOTPCREL(%rip), %rax
Ltmp12:
	.loc	1 44 21 discriminator 1 ## b.c:44:21
	movl	-12(%rbp), %ecx
	.loc	1 44 23 discriminator 1 ## b.c:44:23
	cmpl	(%rax), %ecx
Ltmp13:
	.loc	1 44 9 discriminator 1  ## b.c:44:9
	jge	LBB2_6
## BB#4:                                ##   in Loop: Header=BB2_3 Depth=2
	.loc	1 0 9 discriminator 1   ## b.c:0:9
	leaq	L_.str.1(%rip), %rdi
	movq	_arr@GOTPCREL(%rip), %rax
Ltmp14:
	.loc	1 45 26 is_stmt 1       ## b.c:45:26
	movslq	-12(%rbp), %rcx
	shlq	$2, %rcx
	addq	%rcx, %rax
	.loc	1 45 13 is_stmt 0       ## b.c:45:13
	movq	%rax, %rsi
	movb	$0, %al
	callq	_scanf
	movl	%eax, -28(%rbp)         ## 4-byte Spill
Ltmp15:
## BB#5:                                ##   in Loop: Header=BB2_3 Depth=2
	.loc	1 44 28 is_stmt 1 discriminator 2 ## b.c:44:28
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	.loc	1 44 9 is_stmt 0 discriminator 2 ## b.c:44:9
	jmp	LBB2_3
Ltmp16:
LBB2_6:                                 ##   in Loop: Header=BB2_1 Depth=1
	.loc	1 0 9 discriminator 2   ## b.c:0:9
	movq	_arr@GOTPCREL(%rip), %rax
	movl	$400020, %ecx           ## imm = 0x61A94
	movl	%ecx, %edx
	leaq	_cmp(%rip), %rcx
	movq	_n@GOTPCREL(%rip), %rsi
	.loc	1 47 20 is_stmt 1       ## b.c:47:20
	movslq	(%rsi), %rsi
	.loc	1 47 9 is_stmt 0        ## b.c:47:9
	movq	%rax, %rdi
	callq	_qsort
	movq	_arr@GOTPCREL(%rip), %rax
	movq	_n@GOTPCREL(%rip), %rcx
	.loc	1 48 13 is_stmt 1       ## b.c:48:13
	movl	$0, -16(%rbp)
	.loc	1 48 33 is_stmt 0       ## b.c:48:33
	movl	(%rcx), %r8d
	.loc	1 48 35                 ## b.c:48:35
	subl	$1, %r8d
	.loc	1 48 29                 ## b.c:48:29
	movslq	%r8d, %rcx
	movl	(%rax,%rcx,4), %r8d
	.loc	1 48 40                 ## b.c:48:40
	subl	(%rax), %r8d
	.loc	1 48 49                 ## b.c:48:49
	addl	$1, %r8d
	.loc	1 48 22                 ## b.c:48:22
	movl	%r8d, -20(%rbp)
LBB2_7:                                 ##   Parent Loop BB2_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	.loc	1 51 16 is_stmt 1 discriminator 1 ## b.c:51:16
	movl	-16(%rbp), %eax
	.loc	1 51 20 is_stmt 0 discriminator 1 ## b.c:51:20
	cmpl	-20(%rbp), %eax
	.loc	1 51 9 discriminator 1  ## b.c:51:9
	jg	LBB2_12
## BB#8:                                ##   in Loop: Header=BB2_7 Depth=2
Ltmp17:
	.loc	1 52 20 is_stmt 1       ## b.c:52:20
	movl	-16(%rbp), %eax
	.loc	1 52 24 is_stmt 0       ## b.c:52:24
	addl	-20(%rbp), %eax
	.loc	1 52 32                 ## b.c:52:32
	sarl	$1, %eax
	.loc	1 52 17                 ## b.c:52:17
	movl	%eax, -24(%rbp)
Ltmp18:
	.loc	1 53 23 is_stmt 1       ## b.c:53:23
	movl	-24(%rbp), %edi
	.loc	1 53 17 is_stmt 0       ## b.c:53:17
	callq	_check
	.loc	1 53 28                 ## b.c:53:28
	cmpl	-8(%rbp), %eax
Ltmp19:
	.loc	1 53 17                 ## b.c:53:17
	jl	LBB2_10
## BB#9:                                ##   in Loop: Header=BB2_7 Depth=2
Ltmp20:
	.loc	1 54 23 is_stmt 1       ## b.c:54:23
	movl	-24(%rbp), %eax
	.loc	1 54 27 is_stmt 0       ## b.c:54:27
	addl	$1, %eax
	.loc	1 54 21                 ## b.c:54:21
	movl	%eax, -16(%rbp)
	.loc	1 55 13 is_stmt 1       ## b.c:55:13
	jmp	LBB2_11
Ltmp21:
LBB2_10:                                ##   in Loop: Header=BB2_7 Depth=2
	.loc	1 56 24                 ## b.c:56:24
	movl	-24(%rbp), %eax
	.loc	1 56 28 is_stmt 0       ## b.c:56:28
	subl	$1, %eax
	.loc	1 56 22                 ## b.c:56:22
	movl	%eax, -20(%rbp)
Ltmp22:
LBB2_11:                                ##   in Loop: Header=BB2_7 Depth=2
	.loc	1 51 9 is_stmt 1 discriminator 2 ## b.c:51:9
	jmp	LBB2_7
LBB2_12:                                ##   in Loop: Header=BB2_1 Depth=1
	.loc	1 0 9 is_stmt 0 discriminator 2 ## b.c:0:9
	leaq	L_.str.2(%rip), %rdi
	.loc	1 59 24 is_stmt 1       ## b.c:59:24
	movl	-24(%rbp), %esi
	.loc	1 59 9 is_stmt 0        ## b.c:59:9
	movb	$0, %al
	callq	_printf
Ltmp23:
	.loc	1 42 5 is_stmt 1 discriminator 2 ## b.c:42:5
	movl	%eax, -32(%rbp)         ## 4-byte Spill
	jmp	LBB2_1
LBB2_13:
	.loc	1 61 1                  ## b.c:61:1
	movl	-4(%rbp), %eax
	addq	$32, %rsp
	popq	%rbp
	retq
Ltmp24:
Lfunc_end2:
	.cfi_endproc

	.comm	_n,4,2                  ## @n
	.comm	_arr,400020,4           ## @arr
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d %d"

L_.str.1:                               ## @.str.1
	.asciz	"%d"

L_.str.2:                               ## @.str.2
	.asciz	"%d\n"

	.section	__DWARF,__debug_str,regular,debug
Linfo_string:
	.asciz	"Apple LLVM version 9.0.0 (clang-900.0.38)" ## string offset=0
	.asciz	"b.c"                   ## string offset=42
	.asciz	"/Users/yogurt/code/programming2017aut/week8/homework" ## string offset=46
	.asciz	"arr"                   ## string offset=99
	.asciz	"int"                   ## string offset=103
	.asciz	"sizetype"              ## string offset=107
	.asciz	"n"                     ## string offset=116
	.asciz	"cmp"                   ## string offset=118
	.asciz	"check"                 ## string offset=122
	.asciz	"main"                  ## string offset=128
	.asciz	"a"                     ## string offset=133
	.asciz	"b"                     ## string offset=135
	.asciz	"mid"                   ## string offset=137
	.asciz	"ans"                   ## string offset=141
	.asciz	"i"                     ## string offset=145
	.asciz	"st"                    ## string offset=147
	.asciz	"c"                     ## string offset=150
	.asciz	"low"                   ## string offset=152
	.asciz	"high"                  ## string offset=156
	.section	__DWARF,__debug_loc,regular,debug
Lsection_debug_loc:
	.section	__DWARF,__debug_abbrev,regular,debug
Lsection_abbrev:
	.byte	1                       ## Abbreviation Code
	.byte	17                      ## DW_TAG_compile_unit
	.byte	1                       ## DW_CHILDREN_yes
	.byte	37                      ## DW_AT_producer
	.byte	14                      ## DW_FORM_strp
	.byte	19                      ## DW_AT_language
	.byte	5                       ## DW_FORM_data2
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	16                      ## DW_AT_stmt_list
	.byte	23                      ## DW_FORM_sec_offset
	.byte	27                      ## DW_AT_comp_dir
	.byte	14                      ## DW_FORM_strp
	.byte	17                      ## DW_AT_low_pc
	.byte	1                       ## DW_FORM_addr
	.byte	18                      ## DW_AT_high_pc
	.byte	6                       ## DW_FORM_data4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	2                       ## Abbreviation Code
	.byte	52                      ## DW_TAG_variable
	.byte	0                       ## DW_CHILDREN_no
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	63                      ## DW_AT_external
	.byte	25                      ## DW_FORM_flag_present
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	2                       ## DW_AT_location
	.byte	24                      ## DW_FORM_exprloc
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	3                       ## Abbreviation Code
	.byte	1                       ## DW_TAG_array_type
	.byte	1                       ## DW_CHILDREN_yes
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	4                       ## Abbreviation Code
	.byte	33                      ## DW_TAG_subrange_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	55                      ## DW_AT_count
	.byte	6                       ## DW_FORM_data4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	5                       ## Abbreviation Code
	.byte	36                      ## DW_TAG_base_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	62                      ## DW_AT_encoding
	.byte	11                      ## DW_FORM_data1
	.byte	11                      ## DW_AT_byte_size
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	6                       ## Abbreviation Code
	.byte	36                      ## DW_TAG_base_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	11                      ## DW_AT_byte_size
	.byte	11                      ## DW_FORM_data1
	.byte	62                      ## DW_AT_encoding
	.byte	11                      ## DW_FORM_data1
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	7                       ## Abbreviation Code
	.byte	15                      ## DW_TAG_pointer_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	8                       ## Abbreviation Code
	.byte	46                      ## DW_TAG_subprogram
	.byte	1                       ## DW_CHILDREN_yes
	.byte	17                      ## DW_AT_low_pc
	.byte	1                       ## DW_FORM_addr
	.byte	18                      ## DW_AT_high_pc
	.byte	6                       ## DW_FORM_data4
	.byte	64                      ## DW_AT_frame_base
	.byte	24                      ## DW_FORM_exprloc
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	39                      ## DW_AT_prototyped
	.byte	25                      ## DW_FORM_flag_present
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	63                      ## DW_AT_external
	.byte	25                      ## DW_FORM_flag_present
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	9                       ## Abbreviation Code
	.byte	5                       ## DW_TAG_formal_parameter
	.byte	0                       ## DW_CHILDREN_no
	.byte	2                       ## DW_AT_location
	.byte	24                      ## DW_FORM_exprloc
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	10                      ## Abbreviation Code
	.byte	52                      ## DW_TAG_variable
	.byte	0                       ## DW_CHILDREN_no
	.byte	2                       ## DW_AT_location
	.byte	24                      ## DW_FORM_exprloc
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	11                      ## Abbreviation Code
	.byte	11                      ## DW_TAG_lexical_block
	.byte	1                       ## DW_CHILDREN_yes
	.byte	17                      ## DW_AT_low_pc
	.byte	1                       ## DW_FORM_addr
	.byte	18                      ## DW_AT_high_pc
	.byte	6                       ## DW_FORM_data4
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	12                      ## Abbreviation Code
	.byte	46                      ## DW_TAG_subprogram
	.byte	1                       ## DW_CHILDREN_yes
	.byte	17                      ## DW_AT_low_pc
	.byte	1                       ## DW_FORM_addr
	.byte	18                      ## DW_AT_high_pc
	.byte	6                       ## DW_FORM_data4
	.byte	64                      ## DW_AT_frame_base
	.byte	24                      ## DW_FORM_exprloc
	.byte	3                       ## DW_AT_name
	.byte	14                      ## DW_FORM_strp
	.byte	58                      ## DW_AT_decl_file
	.byte	11                      ## DW_FORM_data1
	.byte	59                      ## DW_AT_decl_line
	.byte	11                      ## DW_FORM_data1
	.byte	73                      ## DW_AT_type
	.byte	19                      ## DW_FORM_ref4
	.byte	63                      ## DW_AT_external
	.byte	25                      ## DW_FORM_flag_present
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	13                      ## Abbreviation Code
	.byte	38                      ## DW_TAG_const_type
	.byte	0                       ## DW_CHILDREN_no
	.byte	0                       ## EOM(1)
	.byte	0                       ## EOM(2)
	.byte	0                       ## EOM(3)
	.section	__DWARF,__debug_info,regular,debug
Lsection_info:
Lcu_begin0:
	.long	395                     ## Length of Unit
	.short	4                       ## DWARF version number
Lset0 = Lsection_abbrev-Lsection_abbrev ## Offset Into Abbrev. Section
	.long	Lset0
	.byte	8                       ## Address Size (in bytes)
	.byte	1                       ## Abbrev [1] 0xb:0x184 DW_TAG_compile_unit
	.long	0                       ## DW_AT_producer
	.short	12                      ## DW_AT_language
	.long	42                      ## DW_AT_name
Lset1 = Lline_table_start0-Lsection_line ## DW_AT_stmt_list
	.long	Lset1
	.long	46                      ## DW_AT_comp_dir
	.quad	Lfunc_begin0            ## DW_AT_low_pc
Lset2 = Lfunc_end2-Lfunc_begin0         ## DW_AT_high_pc
	.long	Lset2
	.byte	2                       ## Abbrev [2] 0x2a:0x15 DW_TAG_variable
	.long	99                      ## DW_AT_name
	.long	63                      ## DW_AT_type
                                        ## DW_AT_external
	.byte	1                       ## DW_AT_decl_file
	.byte	20                      ## DW_AT_decl_line
	.byte	9                       ## DW_AT_location
	.byte	3
	.quad	_arr
	.byte	3                       ## Abbrev [3] 0x3f:0xf DW_TAG_array_type
	.long	78                      ## DW_AT_type
	.byte	4                       ## Abbrev [4] 0x44:0x9 DW_TAG_subrange_type
	.long	85                      ## DW_AT_type
	.long	100005                  ## DW_AT_count
	.byte	0                       ## End Of Children Mark
	.byte	5                       ## Abbrev [5] 0x4e:0x7 DW_TAG_base_type
	.long	103                     ## DW_AT_name
	.byte	5                       ## DW_AT_encoding
	.byte	4                       ## DW_AT_byte_size
	.byte	6                       ## Abbrev [6] 0x55:0x7 DW_TAG_base_type
	.long	107                     ## DW_AT_name
	.byte	8                       ## DW_AT_byte_size
	.byte	7                       ## DW_AT_encoding
	.byte	2                       ## Abbrev [2] 0x5c:0x15 DW_TAG_variable
	.long	116                     ## DW_AT_name
	.long	78                      ## DW_AT_type
                                        ## DW_AT_external
	.byte	1                       ## DW_AT_decl_file
	.byte	26                      ## DW_AT_decl_line
	.byte	9                       ## DW_AT_location
	.byte	3
	.quad	_n
	.byte	7                       ## Abbrev [7] 0x71:0x5 DW_TAG_pointer_type
	.long	78                      ## DW_AT_type
	.byte	8                       ## Abbrev [8] 0x76:0x36 DW_TAG_subprogram
	.quad	Lfunc_begin0            ## DW_AT_low_pc
Lset3 = Lfunc_end0-Lfunc_begin0         ## DW_AT_high_pc
	.long	Lset3
	.byte	1                       ## DW_AT_frame_base
	.byte	86
	.long	118                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	22                      ## DW_AT_decl_line
                                        ## DW_AT_prototyped
	.long	78                      ## DW_AT_type
                                        ## DW_AT_external
	.byte	9                       ## Abbrev [9] 0x8f:0xe DW_TAG_formal_parameter
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	120
	.long	133                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	22                      ## DW_AT_decl_line
	.long	392                     ## DW_AT_type
	.byte	9                       ## Abbrev [9] 0x9d:0xe DW_TAG_formal_parameter
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	112
	.long	135                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	22                      ## DW_AT_decl_line
	.long	392                     ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	8                       ## Abbrev [8] 0xac:0x6e DW_TAG_subprogram
	.quad	Lfunc_begin1            ## DW_AT_low_pc
Lset4 = Lfunc_end1-Lfunc_begin1         ## DW_AT_high_pc
	.long	Lset4
	.byte	1                       ## DW_AT_frame_base
	.byte	86
	.long	122                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	27                      ## DW_AT_decl_line
                                        ## DW_AT_prototyped
	.long	78                      ## DW_AT_type
                                        ## DW_AT_external
	.byte	9                       ## Abbrev [9] 0xc5:0xe DW_TAG_formal_parameter
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	124
	.long	137                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	27                      ## DW_AT_decl_line
	.long	78                      ## DW_AT_type
	.byte	10                      ## Abbrev [10] 0xd3:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	120
	.long	141                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	28                      ## DW_AT_decl_line
	.long	78                      ## DW_AT_type
	.byte	10                      ## Abbrev [10] 0xe1:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	116
	.long	145                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	28                      ## DW_AT_decl_line
	.long	78                      ## DW_AT_type
	.byte	10                      ## Abbrev [10] 0xef:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	112
	.long	147                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	29                      ## DW_AT_decl_line
	.long	78                      ## DW_AT_type
	.byte	11                      ## Abbrev [11] 0xfd:0x1c DW_TAG_lexical_block
	.quad	Ltmp6                   ## DW_AT_low_pc
Lset5 = Ltmp7-Ltmp6                     ## DW_AT_high_pc
	.long	Lset5
	.byte	10                      ## Abbrev [10] 0x10a:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	108
	.long	147                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	31                      ## DW_AT_decl_line
	.long	78                      ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	0                       ## End Of Children Mark
	.byte	12                      ## Abbrev [12] 0x11a:0x6e DW_TAG_subprogram
	.quad	Lfunc_begin2            ## DW_AT_low_pc
Lset6 = Lfunc_end2-Lfunc_begin2         ## DW_AT_high_pc
	.long	Lset6
	.byte	1                       ## DW_AT_frame_base
	.byte	86
	.long	128                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	40                      ## DW_AT_decl_line
	.long	78                      ## DW_AT_type
                                        ## DW_AT_external
	.byte	10                      ## Abbrev [10] 0x133:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	120
	.long	150                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	41                      ## DW_AT_decl_line
	.long	78                      ## DW_AT_type
	.byte	11                      ## Abbrev [11] 0x141:0x46 DW_TAG_lexical_block
	.quad	Ltmp11                  ## DW_AT_low_pc
Lset7 = Ltmp23-Ltmp11                   ## DW_AT_high_pc
	.long	Lset7
	.byte	10                      ## Abbrev [10] 0x14e:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	116
	.long	145                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	43                      ## DW_AT_decl_line
	.long	78                      ## DW_AT_type
	.byte	10                      ## Abbrev [10] 0x15c:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	112
	.long	152                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	48                      ## DW_AT_decl_line
	.long	78                      ## DW_AT_type
	.byte	10                      ## Abbrev [10] 0x16a:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	108
	.long	156                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	48                      ## DW_AT_decl_line
	.long	78                      ## DW_AT_type
	.byte	10                      ## Abbrev [10] 0x178:0xe DW_TAG_variable
	.byte	2                       ## DW_AT_location
	.byte	145
	.byte	104
	.long	137                     ## DW_AT_name
	.byte	1                       ## DW_AT_decl_file
	.byte	49                      ## DW_AT_decl_line
	.long	78                      ## DW_AT_type
	.byte	0                       ## End Of Children Mark
	.byte	0                       ## End Of Children Mark
	.byte	7                       ## Abbrev [7] 0x188:0x5 DW_TAG_pointer_type
	.long	397                     ## DW_AT_type
	.byte	13                      ## Abbrev [13] 0x18d:0x1 DW_TAG_const_type
	.byte	0                       ## End Of Children Mark
	.section	__DWARF,__debug_ranges,regular,debug
Ldebug_range:
	.section	__DWARF,__debug_macinfo,regular,debug
Ldebug_macinfo:
Lcu_macro_begin0:
	.byte	0                       ## End Of Macro List Mark
	.section	__DWARF,__apple_names,regular,debug
Lnames_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	5                       ## Header Bucket Count
	.long	5                       ## Header Hash Count
	.long	12                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	1                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.long	-1                      ## Bucket 0
	.long	0                       ## Bucket 1
	.long	2                       ## Bucket 2
	.long	3                       ## Bucket 3
	.long	4                       ## Bucket 4
	.long	193486506               ## Hash in Bucket 1
	.long	2090499946              ## Hash in Bucket 1
	.long	193488517               ## Hash in Bucket 2
	.long	177683                  ## Hash in Bucket 3
	.long	255409219               ## Hash in Bucket 4
	.long	LNames1-Lnames_begin    ## Offset in Bucket 1
	.long	LNames2-Lnames_begin    ## Offset in Bucket 1
	.long	LNames0-Lnames_begin    ## Offset in Bucket 2
	.long	LNames3-Lnames_begin    ## Offset in Bucket 3
	.long	LNames4-Lnames_begin    ## Offset in Bucket 4
LNames1:
	.long	99                      ## arr
	.long	1                       ## Num DIEs
	.long	42
	.long	0
LNames2:
	.long	128                     ## main
	.long	1                       ## Num DIEs
	.long	282
	.long	0
LNames0:
	.long	118                     ## cmp
	.long	1                       ## Num DIEs
	.long	118
	.long	0
LNames3:
	.long	116                     ## n
	.long	1                       ## Num DIEs
	.long	92
	.long	0
LNames4:
	.long	122                     ## check
	.long	1                       ## Num DIEs
	.long	172
	.long	0
	.section	__DWARF,__apple_objc,regular,debug
Lobjc_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	1                       ## Header Bucket Count
	.long	0                       ## Header Hash Count
	.long	12                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	1                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.long	-1                      ## Bucket 0
	.section	__DWARF,__apple_namespac,regular,debug
Lnamespac_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	1                       ## Header Bucket Count
	.long	0                       ## Header Hash Count
	.long	12                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	1                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.long	-1                      ## Bucket 0
	.section	__DWARF,__apple_types,regular,debug
Ltypes_begin:
	.long	1212240712              ## Header Magic
	.short	1                       ## Header Version
	.short	0                       ## Header Hash Function
	.long	1                       ## Header Bucket Count
	.long	1                       ## Header Hash Count
	.long	20                      ## Header Data Length
	.long	0                       ## HeaderData Die Offset Base
	.long	3                       ## HeaderData Atom Count
	.short	1                       ## DW_ATOM_die_offset
	.short	6                       ## DW_FORM_data4
	.short	3                       ## DW_ATOM_die_tag
	.short	5                       ## DW_FORM_data2
	.short	4                       ## DW_ATOM_type_flags
	.short	11                      ## DW_FORM_data1
	.long	0                       ## Bucket 0
	.long	193495088               ## Hash in Bucket 0
	.long	Ltypes0-Ltypes_begin    ## Offset in Bucket 0
Ltypes0:
	.long	103                     ## int
	.long	1                       ## Num DIEs
	.long	78
	.short	36
	.byte	0
	.long	0

.subsections_via_symbols
	.section	__DWARF,__debug_line,regular,debug
Lsection_line:
Lline_table_start0:
