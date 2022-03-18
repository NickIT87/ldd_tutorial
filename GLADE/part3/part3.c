#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>


GtkWidget   *window;
GtkWidget   *fixed1;
GtkWidget   *button1;
GtkWidget   *button2;
GtkWidget   *label1;
GtkWidget   *label2;
GtkWidget   *radio1;
GtkWidget   *radio2;
GtkWidget   *radio3;
GtkBuilder  *builder;


void on_button1_clicked (GtkButton *b);
void on_button2_clicked (GtkButton *b);
void on_radio1_toggled (GtkRadioButton *b);
void on_radio2_toggled (GtkRadioButton *b);
void on_radio3_toggled (GtkRadioButton *b);


int main(int argc, char *argv[])
{
    gtk_init(&argc, &argv); // init Gtk

    builder = gtk_builder_new_from_file("part3.glade");
    window = GTK_WIDGET(gtk_builder_get_object(builder, "window"));
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    
    gtk_builder_connect_signals(builder, NULL);

    fixed1 = GTK_WIDGET(gtk_builder_get_object(builder, "fixed1"));
    button1 = GTK_WIDGET(gtk_builder_get_object(builder, "button1"));
    button2 = GTK_WIDGET(gtk_builder_get_object(builder, "button2"));
    label1 = GTK_WIDGET(gtk_builder_get_object(builder, "label1"));
    label2 = GTK_WIDGET(gtk_builder_get_object(builder, "label2"));
    radio1 = GTK_WIDGET(gtk_builder_get_object(builder, "radio1"));
    radio2 = GTK_WIDGET(gtk_builder_get_object(builder, "radio2"));
    radio3 = GTK_WIDGET(gtk_builder_get_object(builder, "radio3"));

    gtk_widget_show(window);
    gtk_main();

    return EXIT_SUCCESS;
}

void on_button1_clicked (GtkButton *b)
{
    gtk_label_set_text(GTK_LABEL(label1), (const gchar*) "Hello World");
    printf("Hello World glade test\n");
}

void on_button2_clicked (GtkButton *b)
{
    gtk_label_set_text(GTK_LABEL(label2), (const gchar*) "Button2 clicked");
    printf("button2 glade test\n");
}

void on_radio1_toggled (GtkRadioButton *b)
{
    gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
    if (T) gtk_label_set_text(GTK_LABEL(label1), (const gchar*) "Radio 1 Active");
    else gtk_label_set_text(GTK_LABEL(label2), (const gchar*) "Radio 1 Not Active");
}

void on_radio2_toggled (GtkRadioButton *b)
{
    gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
    if (T) gtk_label_set_text(GTK_LABEL(label1), (const gchar*) "Radio 2 Active");
    else gtk_label_set_text(GTK_LABEL(label2), (const gchar*) "Radio 2 Not Active");
}

void on_radio3_toggled (GtkRadioButton *b)
{
    gboolean T = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(b));
    if (T) gtk_label_set_text(GTK_LABEL(label1), (const gchar*) "Radio 3 Active");
    else gtk_label_set_text(GTK_LABEL(label2), (const gchar*) "Radio 3 Not Active");
}