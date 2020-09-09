main:
	gcc -g shell.h shell.c prompt.c read.c tokenize.c execute.c inblt_cd.c inblt_echo.c inblt_pwd.c pinfo.c ls.c sys.c bg_handler.c  