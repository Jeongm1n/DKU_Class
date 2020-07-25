/*myshell program by 조 정 민, qll4359@naver.com*/
#include<stdio.h>             // 헤더 선언
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<errno.h>
#include<stdbool.h>
#include<sys/wait.h>
struct myShell                // command structure
{
	char* command_name;                    
	char* command_expl;
	bool (*func)(int argc, char* argv[]);          // 함수 포인터
};
bool my_cd(int argc, char* argv[]);                    // 함수 전방 선언
bool my_quit(int argc, char* argv[]);
bool my_help(int argc, char* argv[]);
bool my_exit(int argc, char* argv[]);
struct myShell command[] =
{
	{"cd", "Change directory", my_cd},
	{"exit", "Exit this shell", my_exit},
	{"quit", "Quit this shell", my_quit},
	{"help","Show this help", my_help},
	{">", "Output redirection"},
	{"<", "Input redirection"},
	{"&", "Background processing"}
};
bool my_cd(int argc, char* argv[])                     // cd 명령어 함수
{
	if (argc == 1)
		chdir(getenv("HOME"));
	else if (argc == 2)
	{
		if (chdir(argv[1]))
			printf("%s is no directory\n", argv[1]);
	}
	else
		printf("HOW TO USE? cd [directory name]\n");
	return true;
}
bool my_exit(int argc, char* argv[])                  // exit 명령어 함수
{
	return false;
}
bool my_quit(int argc, char* argv[])                  // quit 명령어 함수
{
	return false;
}
bool my_help(int argc, char* argv[])                  // help 명령어 함수
{
	int i;
	printf("==========================Myshell==========================\n");
	printf("You can use it just as the conventional shell\n");
	printf("\nSome examples of the built-in commands\n");
	printf("===========================================================\n");
	for (i = 0; i < sizeof(command) / sizeof(command[0]); ++i)
	{
		if (argc == 1 || strcmp(command[i].command_name, argv[1]) == 0)
			printf("%-6s: %s\n", command[i].command_name, command[i].command_expl);    // 명령어와 도움말 출력
	}
	printf("===========================================================\n");
	return true;
}
void my_redout(int x, int argc, char* argv[])            // redirection > 명령어 함수
{
	int fd;
	if (argc == 3)          
	{
		fd = open(argv[x + 2], O_WRONLY | O_CREAT, 0664);                          
		if (fd < 0)
		{
			printf("Can't open %s file with errno %d\n", argv[x + 2], errno);
			exit(-1);
		}
		dup2(fd, STDOUT_FILENO);
		argv[x + 1] = NULL;
	}
	else                       // 아닌 경우
	{
		fd = open(argv[x + 3], O_WRONLY | O_CREAT, 0664);                          
		if (fd < 0)
		{
			printf("Can't open %s file with errno %d\n", argv[x + 3], errno);
			exit(-1);
		}
		dup2(fd, STDOUT_FILENO);                                // fd에 표준출력하여 복사본 생성
		argv[x + 2] = NULL;
	}
	close(fd);
	return;
}
void my_redin(int x, int argc, char* argv[])                   // redirection < 명령어 함수
{
	int fd;
	fd = open(argv[x + 2], O_RDONLY);                      // 읽기전용으로 open
	if (fd < 0)                                           
	{
		printf("Can't open %s file with errno %d\n", argv[x + 2], errno);
		exit(-1);                                    
	}
	dup2(fd, STDIN_FILENO);                                // fd에 표준출력하여 복사본 생성
	argv[x + 1] = NULL;
	close(fd);                                             // fd 닫기
	return;
}
void check(char* line, bool* back, bool* redout, bool* redin)  // redirection과 background 명령어를 체크해주는 함수
{
	char* check_back = strchr(line, '&');     // 문자열 속 문자 '&', '>', '<' 검색
	char* check_redout = strchr(line, '>');
	char* check_redin = strchr(line, '<');
	if (check_back != NULL)
		*back = true;
	if (check_redout != NULL)
		*redout = true;
	if (check_redin != NULL)
		*redin = true;
	return;
}
int tokenize(char* buf, char* delims, char* tokens[], int maxTokens)
{
	int count = 0;
	char* token;
	token = strtok(buf, delims);                 // 문자열 분리하여 token에 저장
	while (token != NULL && count < maxTokens)
	{
		tokens[count++] = token;
		token = strtok(NULL, delims);        // 다음 토큰을 가져옴
	}
	tokens[count] = NULL;                        // tokens의 마지막은 NULL
	return count;
}
bool run(char* line)
{
	int token_count, status, i, pid, x;
	char delims[] = " \n";
	char* tokens[128];
	bool back = false;
	bool redout = false;
	bool redin = false;

	check(line, &back, &redout, &redin);         // redirection과 background 체크
	token_count = tokenize(line, delims, tokens, sizeof(tokens) / sizeof(char*));
	if (token_count == 0) return true;           // token_count가 0이면 return true

	for (i = 0; i < sizeof(command) / sizeof(command[0]); ++i)
	{
		if (strcmp(command[i].command_name, tokens[0]) == 0) // 명령어와 첫번째 토큰이 같으면
			return command[i].func(token_count, tokens); // 리턴
	}
	pid=fork();
	if (pid < 0)       // pid=fork()가 0보다 작으면
	{
		perror("fork error"); 
		exit(-1);             // fork error로 종료
	}
	else if (pid == 0) // pid이 0이면
	{
		if (redout == true)    // '>'인 경우
		{
			x = 0;
			my_redout(x, token_count, tokens);
		}
		if (redin == true)     // '<'인 경우
		{
			x = 0;
			my_redin(x, token_count, tokens);
		}
		execvp(tokens[0], tokens);
		printf("The file does not exist\n");
		exit(-1);
	}
	else
	{
		if (back == false)
			waitpid(pid, &status, 0);
		else                                      // '&'인 경우
			waitpid(pid, &status, WNOHANG);   // 부모 프로세스가 기다리지 않음(어떤 자식이 종료되지 않은 경우도 함수는 바로 리턴)
	}
	return true;
}
int main()
{
	char line[1024];                                  // command와 option, argument를 입력받을 배열 선언 
	while (1)
	{
		printf("Shell of Jeongmin:~$ ");
		fgets(line, sizeof(line) - 1, stdin);     // (line의 사이즈-1)만큼 표준입력
		if (run(line) == false)
			break;
	}
	return 0;
}
