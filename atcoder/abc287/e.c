#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tri{
	int cnt;
	struct tri *child[26];
};

const int nax = 5e5 + 10;
char str[nax], *arr[nax];
struct tri * root;
int n, l;

void insert(char * s) {
	int i = 0;
	struct tri * cur = root;
	while (s[i] != '\0') {
		if (cur->child[s[i]-'a'] == NULL) {
			cur->child[s[i]-'a'] = malloc(sizeof(struct tri));
		}
		cur = cur->child[s[i]-'a'];
		cur->cnt += 1;
		i += 1;
	}
}
		
int lcp(char *s) {
	struct tri * cur = root;
	int i = 0;
	while (s[i] != '\0') {
		cur = cur->child[s[i]-'a'];
		if (cur->cnt == 1) {
			break;
		}
		i += 1;
	}
	return i;
}

int main() {
	root = malloc(sizeof(struct tri));
	scanf("%d", &n);
	for (int i=0; i<n; ++i) {
		scanf("%s", str);
		l = strlen(str);
		arr[i] = malloc((l+1) * sizeof(char));
		strcpy(arr[i], str);
		memset(str,0,l);
		insert(arr[i]);
	}
	for (int i=0; i<n; ++i) {
		printf("%d\n", lcp(arr[i]));
	}
}
