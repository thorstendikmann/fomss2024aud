.PHONY : all clean build runonly run docker dockerbuild dockerclean

project_name = fomaud
image_name = fomaud

all: | build

clean:
	@rm -Rf build/*

build:
	@mkdir -p build;
	@cd build && cmake .. && make -s -j1;

dockerbuild:
# --no-cache
# --progress=plain
	@docker build --progress=plain -t $(image_name) --compress .;

docker: dockerbuild
#	@docker run --rm $(image_name);
	@docker run --publish 8080:80 --publish 8443:443 --rm $(image_name) \
	

dockerclean:
	@docker rmi $(image_name);
