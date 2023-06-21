#include "monty.h"

int _strcmp(char *s1, char *s2) {
    int i = 0;
    while (s1[i] == s2[i]) {
        if (s1[i] == '\0')
            return 0;
        i++;
    }
    return s1[i] - s2[i];
}


void free_dlistint(stack_t *head) {
    stack_t *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


int is_integer(char *str) {
    if (*str == '-' || *str == '+')
        str++;
    while (*str != '\0') {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

char *_strtoky(char *s, char *d)
{
    static char *lastToken = NULL;  /* Static variable to store the last token*/
    char *start;
    char *end;

    if (s != NULL) {
        lastToken = s;
    } else if (lastToken == NULL) {
        return NULL;  /* No more tokens*/
    }

    
    start = lastToken;
    while (*start && strchr(d, *start)) {
        start++;
    }

    if (!*start) {
        lastToken = NULL;
        return NULL;  /* Reached the end, no more tokens */
    }

    /* Find the end of the token */
    end = start + 1;
    while (*end && !strchr(d, *end)) {
        end++;
    }

    if (*end) {
        *end = '\0';  /* Null-terminate the token  */
        lastToken = end + 1;
    } else {
        lastToken = NULL;
    }

    return start;
}
