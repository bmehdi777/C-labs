#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

void search_in_line(char *line, char *query, int nLine, char *filename) {
	char *ptr = strstr(line, query);
	if (ptr != NULL)
		printf("[l.%d - %s] - %s", nLine, filename, line);
}
void search_in_file(char *pathname, char *query, char *filename) {
	FILE *pFile = fopen(pathname, "r");
	int bufferLength = 10000; // We won't find word if there are split due to the buffer length
	char buffer[bufferLength];
	int line = 0;

	if (pFile == NULL) {
		printf("%s can't be opened\n", pathname);
		return;
	}

	while(fgets(buffer, bufferLength, pFile)) {
		line++;
		search_in_line(buffer, query, line,filename);
	}

	fclose(pFile);
}

void search_in_files(char *path, char *query) {
	DIR *directory;
	struct dirent *dir;

	directory = opendir(path);
	if (directory) {
		while ((dir = readdir(directory)) != NULL) {
			if(strcmp(dir->d_name, ".") != 0 && strcmp(dir->d_name, "..") ) {
				char *pathname = malloc(strlen(path)+1 + strlen(dir->d_name)+1);
				strcpy(pathname, path);
				strcat(pathname, dir->d_name);
				search_in_file(pathname, query, dir->d_name);
				free(pathname);
			}
		}
		closedir(directory);
	}
}

int handle_arg(int argc, char *argv[], char *path) {
	if (argc < 2) {
		goto error_arg;
	}

	for (char **pointerArgv = argv+1; *pointerArgv != argv[argc]; pointerArgv++) {
		search_in_files(path, *pointerArgv);
	}
	return 0;

error_arg:
	printf("USAGE: logfind <query1> [...query]\n");
	return 1;
}

int main(int argc, char *argv[]) {
	char* logPath = "/var/log/";
	handle_arg(argc, argv, logPath);
	return 0;
}
