#ifndef HOLBERTON_H
#define HOLBERTON_H

int sizeof_string(char *str);
int builtin_handler(char *cmd, char *envp[]);
int _strcmp(char *s1, char *s2);
int execution_handler(char *raw_cmd, char *env[]);
char *find_path(char *env[]);
int _contains(char *str, char *keyword);
char *str_concat(char *s1, char *s2);
char **cmd_parser(char *cmd_to_parse);
char *_strcpy(char *dest, char *src);
int print_env(char *envp[]);
char *find_home_dir(char *envp[]);
int change_directory(char **parsed_cmd, char *envp[]);
void free_2d_array(char **);

#endif
