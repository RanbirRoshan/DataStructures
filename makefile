#output properties
compiler := g++
cflags := -I ./lib.datastructure -w -O3 -Wall -s -g0
lflags := -c -lm
output := keywordcounter

#variables
root_dir := ./
src_dir := $(root_dir)adsassignment/
lib_dir := $(root_dir)lib.datastructure/
src_files1 := $(shell find $(src_dir) -name '*.cpp') $(shell find $(src_dir) -name '*.c') $(shell find $(lib_dir) -name '*.cpp') $(shell find $(lib_dir) -name '*.c')
src_files2 := $(filter-out $(src_dir)stdafx.cpp, $(src_files1))
src_files := $(filter-out $(lib_dir)stdafx.cpp, $(src_files2))
hdr_files := $(shell find $(src_dir) -name '*.hpp') $(shell find  $(src_dir) -name '*.h') $(shell find $(lib_src) -name '*.hpp') $(shell find $(lib_src) -name '*.h')
obj_files := $(shell find $(root_dir) -name '*.o')

#target
.PHONY: default
default: release32 ;

release32:
	@make -s clean
	@make -s compilerelease32
	@make -s generaterelease32
	@make -s cleanobj

generaterelease32:
	@$(compiler) -o $(output) $(obj_files)	

compilerelease32 : $(src_files)
	@$(compiler) $(cflags) -c $(src_files) -I $(src_dir)

cleanobj:
	@rm -rf $(root_dir)*.o

clean:
	@rm -rf $(root_dir)*.a
	@make -s cleanobj
	@rm -rf $(output)
