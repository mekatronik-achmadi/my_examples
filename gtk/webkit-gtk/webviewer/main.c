#include <webkit/webkit.h>
#include <gtk/gtk.h>

static void entry_activated (GtkEntry *entry, WebKitWebView *embed){
	webkit_web_view_load_uri (embed, gtk_entry_get_text (entry));
}

int main (int argc, char** argv)
{
	gtk_init (&argc, &argv);
	
	/* Widgets and signals */
	GtkWidget *window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size (GTK_WINDOW (window), 800, 600);
	gtk_window_set_title (GTK_WINDOW (window), "Mini browser written in C");
	GtkWidget *embed = webkit_web_view_new();
	GtkWidget *entry = gtk_entry_new();
	g_signal_connect (entry, "activate", G_CALLBACK (entry_activated), embed);
	GtkWidget *scroller = gtk_scrolled_window_new(NULL, NULL);
	gtk_container_add (GTK_CONTAINER(scroller), embed);
	
	/* Pack everything and show */
	GtkWidget *vbox = gtk_vbox_new (FALSE, 0);
	gtk_box_pack_start (GTK_BOX(vbox), entry, FALSE, FALSE, 0);
	gtk_box_pack_start (GTK_BOX(vbox), scroller, TRUE, TRUE, 0);
	gtk_container_add (GTK_CONTAINER(window), vbox);
	gtk_widget_show_all (window);
	
	/* Load a default URI and run */
	webkit_web_view_load_uri (WEBKIT_WEB_VIEW (embed), "http://www.webkit.org");
	gtk_main();
	return 0;
}
