#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <greyscale.h>

GREYSCALE** get_templates()
{
	GREYSCALE **templates = (GREYSCALE**) malloc(sizeof(GREYSCALE*) * 2);
	FILE *fp = fopen("data/templates.txt", "r");
	int i = 0;
	char path[256];

	while (!feof(fp))
	{
		fscanf(fp, "%s", path);
		if (strlen(path) > 1)
			templates[i] = greyscale_load(path), ++i,
			templates = realloc(templates, sizeof(GREYSCALE*) * (i+2));
	}

	templates[i-1] = NULL;
	fclose(fp);
	return templates;
}

int main(int argc, char *argv[]) {
	GREYSCALE **templates = get_templates();
	/* GREYSCALE *to_find = greyscale_load(argv[1]); */
	int i = 0;

	while (true)
	{
		if (templates[i] == NULL)
			break;
		else
			greyscale_display(templates[i]),
			i++;
	}
	/* discover bitmap */

	free(templates);
	return 0;
}
