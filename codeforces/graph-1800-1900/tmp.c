#include <stdio.h>
#include <string.h>
int main() {
	char str[1024];
	int cnt[26];
	scanf("%s", str);
	for (int i=0; i<strlen(str); i++) {
		cnt[str[i]-'a'] += 1;
	}
	for (int i=0; i<26; ++i) {
		printf("%c:%d\n", i+'a', cnt[i]);
	}
}
