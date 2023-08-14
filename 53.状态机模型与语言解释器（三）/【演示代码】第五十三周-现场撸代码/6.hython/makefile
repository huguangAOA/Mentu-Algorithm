all:
	java -jar antlr_module/antlr-3.4-complete.jar antlr_module/hython.g
	mv antlr_module/*.c src/
	mv antlr_module/*.h includes/
	mv ./hython.tokens antlr_module/
	g++ main.cpp src/*.c src/*.cc ./libs/libantlr3c.a -o hython -I ./includes/include/ -I ./includes/
	mv hython bin/

test:
	./bin/hython ./samples/test1.hl
	./bin/hython ./samples/test2.hl
	./bin/hython ./samples/test3.hl
	./bin/hython ./samples/test4.hl
	./bin/hython ./samples/prime.hl
