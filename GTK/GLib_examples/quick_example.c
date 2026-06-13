// quick_example.c
#include <glib.h>
#include <stdio.h>

/* Функция для демонстрации работы GError */
static gboolean divide(int a, int b, int *result, GError **error) {
    if (b == 0) {
        g_set_error(error,
                     g_quark_from_static_string("DIV_ERROR"),
                     1,
                     "Division by zero is not allowed");
        return FALSE;
    }

    *result = a / b;
    return TRUE;
}

int main() {
    /* =======================
     * GString (динамические строки)
     * ======================= */
    GString *str = g_string_new("Hello");
    g_string_append(str, ", GLib!");
    g_print("GString: %s\n", str->str);

    g_string_free(str, TRUE);

    /* =======================
     * GList (двусвязный список)
     * ======================= */
    GList *list = NULL;
    list = g_list_append(list, "Apple");
    list = g_list_append(list, "Banana");
    list = g_list_append(list, "Cherry");

    g_print("\nGList contents:\n");
    for (GList *l = list; l != NULL; l = l->next) {
        g_print("- %s\n", (char *)l->data);
    }

    /* free list */
    g_list_free(list);
    list = NULL;

    /* =======================
     * GHashTable (хеш-таблица)
     * ======================= */
    GHashTable *table = g_hash_table_new(g_str_hash, g_str_equal);

    g_hash_table_insert(table, "name", "Nick");
    g_hash_table_insert(table, "lang", "C");

    g_print("\nGHashTable contents:\n");
    g_print("name = %s\n", (char *)g_hash_table_lookup(table, "name"));
    g_print("lang = %s\n", (char *)g_hash_table_lookup(table, "lang"));

    g_hash_table_destroy(table);

    /* =======================
     * GError (обработка ошибок)
     * ======================= */
    GError *error = NULL;
    int result = 0;

    if (divide(10, 2, &result, &error)) {
        g_print("\n10 / 2 = %d\n", result);
    } else {
        g_print("Error: %s\n", error->message);
        g_clear_error(&error);
    }

    if (!divide(10, 0, &result, &error)) {
        g_print("Error: %s\n", error->message);
        g_clear_error(&error);
    }

    return 0;
}

// clang quick_example.c $(pkg-config --cflags --libs glib-2.0) -o app
// gcc quick_example.c $(pkg-config --cflags --libs glib-2.0) -o app

/*

GString: Hello, GLib!

GList contents:
- Apple
- Banana
- Cherry

GHashTable contents:
name = Nick
lang = C

10 / 2 = 5
Error: Division by zero is not allowed

*/