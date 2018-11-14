#output properties
compiler := g++
cflags := -I ../lib.datastructure
lflags := -c -lm
output := "keywordcounter"
builddir_r64 := $(src_dir)bin/release64
builddir_r32 := $(src_dir)bin/release32

#variables
root_dir := ../
src_dir := $(root_dir)adsassignment/
src_files := $(shell find $(src_dir) -name '*.cpp') $(shell find $(src_dir) -name '*.c')
src_files := $(filter-out $(src_dir)stdafx.cpp, $(src_files))
hdr_files := $(shell find $(src_dir) -name '*.hpp') $(shell find  $(src_dir) -name '*.h')
obj_files := $(shell find $(src_dir)bin -name *.o)
#$(src_files:.c=.o)

#target
release32:
	@mkdir -v -p $(builddir_r32)
	@echo "Compiling files"
	@make compilerelease32
	@echo "files compiled"
	@echo "generating executable"
	cp -f ../lib.datastructure/bin/release32/* $(builddir_r32)
	make generaterelease32

generaterelease32: $(obj_files)
	$(compiler) -o $(output) $(obj_files)	
	@mv *.a $(builddir_r32) 
	@mv *.o $(builddir_r32)

compilerelease32 : $(src_files)
	@$(compiler) $(cflags) -c $(src_files) -I $(src_dir)
	mv *.o $(builddir_r32)

clean:
	rm -f -v $(src_dir)*.a
	rm -f -v $(src_dir)*.o
	rm -v -rf ./bin
