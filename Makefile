GCC-DIR := $(CURDIR)/output/gcc

install:
ifeq (,$(wildcard ./gcc-7.4.0))
	tar -zxvf gcc-7.4.0.tar.gz
else
	@echo "exist dir gcc-7.4.0, stop unzip"
endif
	@cd gcc-7.4.0 && bash ./contrib/download_prerequisites
	@cd gcc-7.4.0 && mkdir -p objdir
	@cd gcc-7.4.0/objdir && ../configure --prefix=$(GCC-DIR) --enable-languages=c,c++,fortran,go
	@cd gcc-7.4.0/objdir && make -j8
	@cd gcc-7.4.0/objdir && make install

download:
ifeq (,$(wildcard ./gcc-7.4.0.tar.gz))
	wget -o gcc-7.4.0.tar.gz http://ftp.gnu.org/gnu/gcc/gcc-7.4.0/gcc-7.4.0.tar.gz
else
	@echo "exist gcc-7.4.0.tar.gz, stop download"
endif
