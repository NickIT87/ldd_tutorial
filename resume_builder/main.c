#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hpdf.h>

#define FONT_SIZE 12
#define LINE_HEIGHT 16
#define MARGIN 50

void print_help() {
    printf("Resume Builder — генератор PDF из текстового файла\n\n");
    printf("Использование:\n");
    printf("  resume-builder --input resume.txt --output resume.pdf [--title \"My Resume\"]\n\n");
    printf("Опции:\n");
    printf("  --input,  -i     Путь к исходному текстовому файлу\n");
    printf("  --output, -o     Имя выходного PDF-файла\n");
    printf("  --title,  -t     Заголовок документа (опционально)\n");
    printf("  --help,   -h     Показать эту справку\n");
}

void add_line(HPDF_Page page, HPDF_Font font, float *y, const char *line, int is_title) {
    if (is_title) HPDF_Page_SetFontAndSize(page, font, FONT_SIZE + 4);
    else HPDF_Page_SetFontAndSize(page, font, FONT_SIZE);

    HPDF_Page_BeginText(page);
    HPDF_Page_TextOut(page, MARGIN, *y, line);
    HPDF_Page_EndText(page);
    *y -= LINE_HEIGHT + (is_title ? 4 : 0);
}

void generate_pdf(const char *input_path, const char *output_path, const char *title) {
    FILE *f = fopen(input_path, "r");
    if (!f) {
        printf("Ошибка: не удалось открыть файл %s\n", input_path);
        return;
    }

    HPDF_Doc pdf = HPDF_New(NULL, NULL);
    HPDF_Page page = HPDF_AddPage(pdf);
    HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);
    HPDF_Font font = HPDF_GetFont(pdf, "Helvetica", NULL);
    float y = HPDF_Page_GetHeight(page) - MARGIN;

    // Заголовок
    if (title) {
        HPDF_Page_SetFontAndSize(page, font, FONT_SIZE + 6);
        HPDF_Page_BeginText(page);
        HPDF_Page_TextOut(page, MARGIN, y, title);
        HPDF_Page_EndText(page);
        y -= LINE_HEIGHT * 2;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), f)) {
        buffer[strcspn(buffer, "\r\n")] = 0; // убрать \n
        if (strlen(buffer) == 0) continue;

        if (buffer[0] == '[') {
            add_line(page, font, &y, buffer + 1, 1);
        } else {
            add_line(page, font, &y, buffer, 0);
        }

        if (y < MARGIN + 50) {
            page = HPDF_AddPage(pdf);
            HPDF_Page_SetSize(page, HPDF_PAGE_SIZE_A4, HPDF_PAGE_PORTRAIT);
            y = HPDF_Page_GetHeight(page) - MARGIN;
        }
    }

    fclose(f);
    HPDF_SaveToFile(pdf, output_path);
    HPDF_Free(pdf);

    printf("PDF успешно создан: %s\n", output_path);
}

int main(int argc, char *argv[]) {
    const char *input = NULL;
    const char *output = "resume.pdf";
    const char *title = NULL;

    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--input") || !strcmp(argv[i], "-i")) {
            if (i + 1 < argc) input = argv[++i];
        } else if (!strcmp(argv[i], "--output") || !strcmp(argv[i], "-o")) {
            if (i + 1 < argc) output = argv[++i];
        } else if (!strcmp(argv[i], "--title") || !strcmp(argv[i], "-t")) {
            if (i + 1 < argc) title = argv[++i];
        } else if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
            print_help();
            return 0;
        }
    }

    if (!input) {
        printf("Ошибка: не указан входной файл. Используйте --help для справки.\n");
        return 1;
    }

    generate_pdf(input, output, title);
    return 0;
}
