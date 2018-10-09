#include<gtk/gtk.h>
#include<webkit/webkit.h>
 
GtkWidget *window;
GtkWidget *web;
GtkWidget *vbox;
GtkWidget *hbox;
GtkWidget *hbox_web_view;
GtkWidget *go_button;
GtkWidget *back_button;
GtkWidget *forward_button;
GtkWidget *stop_button;
GtkWidget *entry;
 
const char* uri;
void go(GtkWidget* widget, gpointer* wid)
{
GtkWidget* entry = GTK_WIDGET(wid);
uri = gtk_entry_get_text(GTK_ENTRY(entry));
gtk_entry_progress_pulse(GTK_ENTRY(entry));
webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web),uri);
 
}
void back(GtkWidget* widget, gpointer* wid)
{
GtkWidget* web = GTK_WIDGET(wid);
webkit_web_view_go_back(WEBKIT_WEB_VIEW(web));
 
}
void forward(GtkWidget* widget, gpointer* wid)
{
GtkWidget* web = GTK_WIDGET(wid);
webkit_web_view_go_forward(WEBKIT_WEB_VIEW(web));
 
}
void stop(GtkWidget* widget, gpointer* wid)
{
GtkWidget* web = GTK_WIDGET(wid);
webkit_web_view_stop_loading(WEBKIT_WEB_VIEW(web));
 
}
void activate(GtkWidget* widget, gpointer* wid)
{
GtkWidget* web = GTK_WIDGET(wid);
uri = gtk_entry_get_text(GTK_ENTRY(widget));
gtk_entry_progress_pulse(GTK_ENTRY(widget));
webkit_web_view_load_uri(WEBKIT_WEB_VIEW(web),uri);
 
}
void progress (WebKitWebView *web, gint progress,gpointer* data)
{
GtkWidget* wid = GTK_WIDGET(data);
gtk_entry_set_progress_fraction (GTK_ENTRY(wid),progress);
}
 
void finished (WebKitWebView  *web_view, WebKitWebFrame *frame,
gpointer*  data)
{
GtkWidget* wid = GTK_WIDGET(data);
gtk_entry_set_progress_fraction (GTK_ENTRY(wid),0.0);
}
 
int main(int argc, char** argv)
{
 
gtk_init(&argc,&argv);
 
window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
gtk_window_set_default_size(GTK_WINDOW(window), 850, 600);
gtk_window_set_title(GTK_WINDOW(window), "myWebBrowser");
 
vbox = gtk_vbox_new(false,false);
hbox = gtk_hbox_new(false,false);
hbox_web_view = gtk_hbox_new(false,false);
 
gtk_container_add(GTK_CONTAINER(window), vbox);
gtk_container_add(GTK_CONTAINER(vbox), hbox);
gtk_container_add(GTK_CONTAINER(vbox), hbox_web_view);
 
back_button = gtk_button_new_with_label("Back");
forward_button = gtk_button_new_with_label("Forward");
go_button = gtk_button_new_with_label("Go");
stop_button = gtk_button_new_with_label("stop");
entry = gtk_entry_new();
gtk_entry_set_text (GTK_ENTRY(entry),"http://");
 
gtk_box_pack_start(GTK_BOX(hbox),back_button,0,0,1);
gtk_box_pack_start(GTK_BOX(hbox),forward_button,0,0,1);
gtk_box_pack_start(GTK_BOX(hbox),stop_button,0,0,1);
gtk_box_pack_start(GTK_BOX(hbox),entry,1,1,1);
gtk_box_pack_start(GTK_BOX(hbox),go_button,0,0,0);
 
/* create Webview */
web = webkit_web_view_new();
gtk_box_pack_start(GTK_BOX(hbox_web_view),web,0,0,0);
 
g_signal_connect(go_button, "clicked",  G_CALLBACK(go), entry);
g_signal_connect(back_button, "clicked",  G_CALLBACK(back), web);
g_signal_connect(forward_button, "clicked",  G_CALLBACK(forward), web);
g_signal_connect(stop_button, "clicked",  G_CALLBACK(stop), web);
g_signal_connect(entry, "activate",  G_CALLBACK(activate), web);
g_signal_connect(WEBKIT_WEB_VIEW(web),"load-progress-changed",G_CALLBACK(progress),entry);
g_signal_connect(WEBKIT_WEB_VIEW(web),"load-finished",G_CALLBACK(finished),entry);
g_signal_connect_swapped(G_OBJECT(window), "destroy",
G_CALLBACK(gtk_main_quit), NULL);
 
gtk_widget_show_all(window);
 
gtk_main();
return 0;
 
}
